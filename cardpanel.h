#ifndef CARDPANEL_H
#define CARDPANEL_H
#pragma once

#include <QWidget>
#include <QPixmap>
#include <QPoint>

class CardPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CardPanel(QWidget *parent = nullptr);

    // 绑定一张牌：0~53
    void setCardId(int id);
    int  cardId() const { return m_id; }

    // 正面 / 背面
    void setFaceUp(bool up);
    bool isFaceUp() const { return m_faceUp; }

    // 是否被选中（比如点击后弹起）
    void setSelected(bool sel);
    bool isSelected() const { return m_selected; }

signals:
    // 点击信号，外面用来处理“选中/出牌/弹起”
    void clicked(Qt::MouseButton button);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    // 固定牌大小（你可以自己改，比如 80x120）
    static constexpr int CARD_WIDTH  = 70;
    static constexpr int CARD_HEIGHT = 105;

    int  m_id       = -1;   // 牌号：0~53
    bool m_faceUp   = true; // 是否显示正面
    bool m_selected = false;

    QPixmap m_front;        // 这张牌的正面图片（根据 id 加载）

    // 根据牌号生成图片路径（按 3C / 10H / KD / SJ / BJ 命名）
    static QString cardImagePath(int id);

    // 懒加载牌背（函数内部 static，避免 QPixmap 全局构造）
    static QPixmap &backPixmap();

    // 鼠标滑选相关
    static QPoint s_dragStart;       // 鼠标拖动起始点（目前只是记录，不参与逻辑）
    static QPoint s_dragEnd;         // 鼠标拖动当前位置
    static bool   s_dragging;        // 是否正在拖动
    static CardPanel* s_lastHoverPanel; // 当前滑选时最后划到的那张牌
};

#endif // CARDPANEL_H

