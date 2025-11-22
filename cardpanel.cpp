#include "cardpanel.h"
#include <QPainter>
#include <QMouseEvent>

// 静态变量初始化
QPoint CardPanel::s_dragStart;
QPoint CardPanel::s_dragEnd;
bool   CardPanel::s_dragging = false;
CardPanel* CardPanel::s_lastHoverPanel = nullptr;

CardPanel::CardPanel(QWidget *parent)
    : QWidget(parent)
{
    // 牌面大小固定，不再跟随图片尺寸
    setFixedSize(CARD_WIDTH, CARD_HEIGHT);
}

void CardPanel::setCardId(int id)
{
    m_id = id;

    // 根据牌号生成资源路径并加载贴图
    const QString path = cardImagePath(id);
    m_front.load(path);   // 这里不会提前构造 QPixmap，全在 QApplication 之后

    update();
}

void CardPanel::setFaceUp(bool up)
{
    m_faceUp = up;
    update();
}

void CardPanel::setSelected(bool sel)
{
    m_selected = sel;
    update();
}

// ========== 牌号 → 图片路径 ==========
// 命名规则（你要这样放图片）：
//
//  普通牌：<点数><花色首字母>.png
//   点数: 3 4 5 6 7 8 9 10 J Q K A 2
//   花色: C = 梅花 ♣, D = 方块 ♦, H = 红桃 ♥, S = 黑桃 ♠
//
//   例如：3C.png, 10H.png, JD.png, AS.png, 2C.png .
//
//  小王: SJ.png    (Small Joker)
//  大王: BJ.png    (Big  Joker)
//
//  资源文件 cardsimage.qrc 里：
//   <qresource prefix="/cards">
//       <file>3C.png</file>
//       .
//       <file>SJ.png</file>
//       <file>BJ.png</file>
//       <file>BACK.png</file>
//   </qresource>
//
//  代码中访问路径为 :/cards/xxx.png
// ====================================
QString CardPanel::cardImagePath(int id)
{
    if (id < 0 || id > 53)
        return QString();

    // Joker
    if (id == 52) {
        // 小王 → SJ.png
        return QString(":/cards/54png/SJ.png");
    }
    if (id == 53) {
        // 大王 → BJ.png
        return QString(":/cards/54png/BJ.png");
    }

    // 普通牌：0~51
    // 和你原来 main.cpp 的逻辑保持一致：
    // suit = id / 13;   // 0=♦,1=♣,2=♥,3=♠
    // rank = id % 13;   // 0~12 → 3,4,5,6,7,8,9,10,J,Q,K,A,2
    int suit = id / 13;
    int rank = id % 13;

    static const char* rankNames[] = {
        "3","4","5","6","7","8","9","10","J","Q","K","A","2"
    };
    static const char* suitLetters[] = {
        "D",  // 0 → ♦
        "C",  // 1 → ♣
        "H",  // 2 → ♥
        "S"   // 3 → ♠
    };

    QString r = rankNames[rank];   // 例如 "3", "10", "J", "A", "2"
    QString s = suitLetters[suit]; // 例如 "C", "D", "H", "S"

    // 最终文件名：比如 "3C.png"、"AD.png"、"10H.png"
    // 资源路径就是 :/cards/3C.png 等
    return QString(":/cards/54png/%1%2.png").arg(r, s);
}

// 懒加载牌背：第一次调用 backPixmap() 时才真正加载
QPixmap &CardPanel::backPixmap()
{
    static QPixmap back(":/cards/54png/BACK.png");
    return back;
}

void CardPanel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);
    p.setRenderHint(QPainter::SmoothPixmapTransform, true);

    QRect r = rect();

    if (m_faceUp && !m_front.isNull()) {
        // 把正面图缩放到牌大小（保持比例）
        QPixmap scaled = m_front.scaled(
            r.size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            );
        int x = (width()  - scaled.width())  / 2;
        int y = (height() - scaled.height()) / 2;
        p.drawPixmap(x, y, scaled);
    } else {
        QPixmap &back = backPixmap();
        QPixmap scaled = back.scaled(
            r.size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            );
        int x = (width()  - scaled.width())  / 2;
        int y = (height() - scaled.height()) / 2;
        p.drawPixmap(x, y, scaled);
    }

}

// ===== 鼠标事件：支持“按住左键横划多选” =====

void CardPanel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // 开始滑选
        s_dragging = true;
        s_dragStart = event->pos();
        s_dragEnd   = event->pos();
        s_lastHoverPanel = this;

        // 先点当前这张牌，让它弹起 / 取消弹起
        emit clicked(Qt::LeftButton);
    } else {
        // 其他按键按原样转发
        emit clicked(event->button());
    }

    QWidget::mousePressEvent(event);
}

void CardPanel::mouseMoveEvent(QMouseEvent *event)
{
    if (s_dragging && (event->buttons() & Qt::LeftButton)) {
        s_dragEnd = event->pos();

        QWidget *parent = parentWidget();
        if (parent) {
            // 当前鼠标位置映射到父窗口坐标
            QPoint parentPos = mapToParent(event->pos());

            // 找到父窗口里这个位置下的子控件
            QWidget *child = parent->childAt(parentPos);
            CardPanel *panel = qobject_cast<CardPanel*>(child);

            // 划到了新的牌，就“点”一下它
            if (panel && panel != s_lastHoverPanel) {
                s_lastHoverPanel = panel;
                panel->clicked(Qt::LeftButton);  // 触发该牌的 clicked 信号
            }
        }
    }

    QWidget::mouseMoveEvent(event);
}

void CardPanel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && s_dragging) {
        s_dragging = false;
        s_lastHoverPanel = nullptr;
    }

    QWidget::mouseReleaseEvent(event);
}
