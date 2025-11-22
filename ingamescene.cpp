#include "ingamescene.h"
#include "ui_ingamescene.h"

#include <algorithm>
#include <QDebug>
#include <QTimer>

#include "winscene.h"
#include "losescene.h"

InGameScene::InGameScene(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InGameScene)
{
    ui->setupUi(this);
    this->setWindowTitle("InGame");
    this->setFixedSize(800, 600);

    // 一开始先把出牌按钮隐藏（只在出牌阶段 / 玩家回合显示）
    ui->btn_play->hide();
    ui->btn_pass->hide();
    ui->btn_hint->hide();

    // 开一局游戏（洗牌 + 发牌 + 设置叫地主起始玩家）
    initGame();

    // 连接叫分按钮
    connect(ui->btn_notcall, &QPushButton::clicked, this, [this]() { onCallScore(0); });
    connect(ui->btn_1p,      &QPushButton::clicked, this, [this]() { onCallScore(1); });
    connect(ui->btn_2p,      &QPushButton::clicked, this, [this]() { onCallScore(2); });
    connect(ui->btn_3p,      &QPushButton::clicked, this, [this]() { onCallScore(3); });

    // 连接出牌区域按钮
    connect(ui->btn_play, &QPushButton::clicked, this, &InGameScene::onPlayClicked);
    connect(ui->btn_pass, &QPushButton::clicked, this, &InGameScene::onPassClicked);
    connect(ui->btn_hint, &QPushButton::clicked, this, &InGameScene::onHintClicked);
    qDebug() << "我是新版本";
}

InGameScene::~InGameScene()
{
    delete ui;
}

// —— 完整开局 / 重开一局 ——
void InGameScene::initGame()
{
    // 清空旧 UI
    clearLastPlay();
    qDeleteAll(m_handPanels);
    qDeleteAll(m_landlordPanels);
    m_handPanels.clear();
    m_landlordPanels.clear();
    setStatusText("Status: New Game Start");

    // 重新开局：洗牌 + 发牌 + 设置叫地主起始玩家
    qDebug() << "===== GameStart() 新一局 =====";
    m_game.GameStart();

    // 根据当前 game 状态重建 UI
    setupUIForCurrentGame();
}

// —— 只根据现有 game 状态重画 UI，不再 GameStart ——
void InGameScene::setupUIForCurrentGame()
{
    // 1. 画出上方 3 张地主牌（先背面）
    createLandlordPanels(false);

    // 2. 画出玩家 0 的手牌（正面）
    createPlayer0HandPanels();

    // 3. 更新 AI 剩余牌数（初始都是 17）
    updateAiRemainLabels();

    // 4. 让 AI 先叫到轮到玩家 0 为止
    while (m_game.GetStatus() == Status::GetLandlord &&
           m_game.GetCurrentPlayer() &&
           m_game.GetCurrentPlayer()->GetId() != 0)
    {
        qDebug() << "[init] AI" << m_game.GetCurrentPlayer()->GetId() << "正在叫分...";
        setStatusText("Status: AI calling...");
        m_game.CallLandlordPhase();

        // 如果 AI 叫分后已经确定地主，直接进入发地主牌阶段
        if (m_game.GetStatus() == Status::SendLandlordCard)
        {
            qDebug() << "[init] AI 已决定地主，发地主牌";
            setStatusText("Status: Game start!");
            m_game.SendLandlordCard();
            createLandlordPanels(true);
            refreshPlayer0HandPanels();
            hideCallButtons();
            enterDiscardPhase();
            return;
        }
    }

    // 5. 如果轮到玩家 0，显示叫分按钮
    if (m_game.GetStatus() == Status::GetLandlord &&
        m_game.GetCurrentPlayer() &&
        m_game.GetCurrentPlayer()->GetId() == 0)
    {
        qDebug() << "[setupUIForCurrentGame] 轮到玩家 0 叫分";
        setStatusText("Status: You Call!");
        ui->btn_notcall->show();
        ui->btn_1p->show();
        ui->btn_2p->show();
        ui->btn_3p->show();
    }
}
void InGameScene::createLandlordPanels(bool faceUp)
{
    // 清空旧的
    qDeleteAll(m_landlordPanels);
    m_landlordPanels.clear();

    int topY    = 60;
    int centerX = width() / 2;
    int spacing = 40;

    for (int i = 0; i < 3; ++i)
    {
        int id = m_game.GetLandlordCard(i);

        auto *p = new CardPanel(this);
        p->setCardId(id);
        p->setFaceUp(faceUp);

        int x = centerX + (i - 1) * spacing - p->width() / 2;
        p->move(x, topY);
        p->show();

        m_landlordPanels.append(p);
    }
}

void InGameScene::createPlayer0HandPanels()
{
    qDeleteAll(m_handPanels);
    m_handPanels.clear();

    Player *human = m_game.GetPlayer(0);
    const std::multiset<int> &cards = human->GetCards();

    std::vector<int> sorted(cards.begin(), cards.end());
    std::sort(sorted.begin(), sorted.end(), [](int a, int b) {
        return CardGroup::Translate(a) < CardGroup::Translate(b);
    });

    int spacing    = 30;
    int leftMargin = 40;
    int baseY      = height() - 150;

    for (int i = 0; i < (int)sorted.size(); ++i)
    {
        int id = sorted[i];

        auto *p = new CardPanel(this);
        p->setCardId(id);
        p->setFaceUp(true);

        p->move(leftMargin + i * spacing, baseY);
        p->show();

        connect(p, &CardPanel::clicked, this, &InGameScene::onCardClicked);

        m_handPanels.append(p);
    }
}

void InGameScene::refreshPlayer0HandPanels()
{
    createPlayer0HandPanels();
}

void InGameScene::hideCallButtons()
{
    ui->btn_notcall->hide();
    ui->btn_1p->hide();
    ui->btn_2p->hide();
    ui->btn_3p->hide();
}
void InGameScene::onCallScore(int score) {
    qDebug() << "[onCallScore] 玩家点击叫分按钮，分数:" << score;

    m_game.PlayerCallLandlord(score);   // 只调这一句

    hideCallButtons();

    if (m_game.GetStatus() == Status::SendLandlordCard) {
        qDebug() << "-- 地主已决定 --";
        m_game.SendLandlordCard();
        createLandlordPanels(true);
        refreshPlayer0HandPanels();
        enterDiscardPhase();
        return;
    }

    if (m_game.GetStatus() == Status::GetLandlord &&
        m_game.GetLandlord() == nullptr)
    {
        qDebug() << "【无人叫地主】重新开局";
        initGame();
        return;
    }
}


void InGameScene::enterDiscardPhase()
{
    // ================== 先检查是否已经 GameOver ==================
    if (m_game.GetStatus() == Status::GameOver)
    {
        qDebug() << "游戏结束，弹出结果界面";

        Player* human = m_game.GetPlayer(0);
        bool humanWin = (human && human->GetRemain() == 0);

        // 禁用 / 隐藏出牌按钮，防止继续操作
        ui->btn_play->setEnabled(false);
        ui->btn_pass->setEnabled(false);
        ui->btn_hint->setEnabled(false);
        ui->btn_play->hide();
        ui->btn_pass->hide();
        ui->btn_hint->hide();

        if (humanWin) {
            auto *dlg = new WinScene(this);
            dlg->show();
        } else {

            auto *dlg = new LoseScene(this);
            dlg->show();
        }

        return;    // 已经结束，不再进入出牌阶段
    }
    // ================== 正常出牌阶段 ==================
    if (m_game.GetStatus() != Status::Discard)
        return;

    // 每次进阶段都刷新一下 AI 剩余牌数
    updateAiRemainLabels();

    Player* cur = m_game.GetCurrentPlayer();
    if (!cur) {
        qDebug() << "当前玩家为空，状态:" << (int)m_game.GetStatus();
        return;
    }

    // 玩家回合
    if (cur->GetId() == 0)
    {
        qDebug() << "轮到玩家出牌";
        setStatusText("Status: Your Turn!");
        ui->btn_play->show();
        ui->btn_pass->show();
        ui->btn_hint->show();
        ui->btn_play->setEnabled(true);
        ui->btn_pass->setEnabled(true);
        ui->btn_hint->setEnabled(true);
        return;
    }

    // AI 回合（加 2 秒延迟）
    qDebug() << "轮到 AI" << cur->GetId() << " 出牌，2 秒后执行";
    setStatusText(QString("Status： AI%1 Play…").arg(cur->GetId()));
    ui->btn_play->hide();
    ui->btn_pass->hide();
    ui->btn_hint->hide();

    QTimer::singleShot(2000, this, [this]() {
        if (m_game.GetStatus() != Status::Discard)
            return;

        Player* curAI = m_game.GetCurrentPlayer();
        if (!curAI || curAI->GetId() == 0)
        {
            // 这 2 秒内有可能游戏结束或轮到玩家了
            enterDiscardPhase();
            return;
        }

        qDebug() << "AI" << curAI->GetId() << " 开始出牌";

        clearLastPlay();       // 先清空上一次显示，避免叠加

        m_game.DiscardPhase(); // 让 Game 内部按规则出牌 / 过牌（可能连着几个 AI）

        showLastPlay();        // 在中间显示“上家出的牌”
        updateAiRemainLabels();

        // 继续下一位（可能又是 AI，也可能轮到玩家）
        enterDiscardPhase();
    });
}


void InGameScene::onCardClicked()
{
    CardPanel *panel = qobject_cast<CardPanel*>(sender());
    if (!panel) return;

    bool sel = !panel->isSelected();
    panel->setSelected(sel);

    int dy = sel ? -20 : 20;
    panel->move(panel->x(), panel->y() + dy);
}

// —— UI 删除玩家刚刚出掉的牌 ——
void InGameScene::applyPlayerDiscardToUI(const std::vector<int>& indices)
{
    // 必须从大到小删，否则前面的删了下标会变
    std::vector<int> sorted = indices;
    std::sort(sorted.begin(), sorted.end(), std::greater<int>());

    for (int idx : sorted)
    {
        if (idx < 0 || idx >= m_handPanels.size()) continue;
        CardPanel* p = m_handPanels[idx];
        m_handPanels.remove(idx);
        p->deleteLater();
    }

    // 重新排版剩余的牌
    int spacing    = 30;
    int leftMargin = 40;
    int baseY      = height() - 150;

    for (int i = 0; i < m_handPanels.size(); ++i)
    {
        m_handPanels[i]->move(leftMargin + i * spacing, baseY);
    }
}

// —— 清空“上家出的牌”的显示 ——
void InGameScene::clearLastPlay()
{
    qDeleteAll(m_lastPlayPanels);
    m_lastPlayPanels.clear();
}

// —— 根据 Game::GetLastDiscard() 把“上家出的牌”显示在中间 ——
void InGameScene::showLastPlay()
{
    clearLastPlay();

    const CardGroup &grp = m_game.GetLastDiscard();
    Player* last = m_game.GetLastPlayer();

    if (!last) {
        qDebug() << "showLastPlay: lastPlayer 为 null";
        return;
    }

    if (grp.GetCount() == 0)
    {
        qDebug() << "showLastPlay: 上家玩家ID =" << last->GetId()
                << " 出牌数 = 0（可能是 pass）";
        return;
    }

    std::vector<int> cards(grp.GetCards().begin(), grp.GetCards().end());
    std::sort(cards.begin(), cards.end(), [](int a, int b){
        return CardGroup::Translate(a) < CardGroup::Translate(b);
    });

    int count   = (int)cards.size();
    int centerX = width() / 2;
    int baseY   = height() / 2 - 80;
    int spacing = 30;

    qDebug() << "在中间显示上家出牌, 玩家ID:" << last->GetId()
             << ", 张数:" << count;

    for (int i = 0; i < count; ++i)
    {
        CardPanel *p = new CardPanel(this);
        p->setCardId(cards[i]);
        p->setFaceUp(true);

        int x = centerX + (i - count/2.0) * spacing - p->width()/2;
        p->move(x, baseY);
        p->show();

        m_lastPlayPanels.append(p);
    }
}

// —— 更新两个 AI 的剩余牌数（使用你在 .ui 里放的 label） ——
void InGameScene::updateAiRemainLabels()
{
    if (!ui) return;

    Player* ai1 = m_game.GetPlayer(1);
    Player* ai2 = m_game.GetPlayer(2);
    if (!ai1 || !ai2) return;

    int r1 = ai1->GetRemain();
    int r2 = ai2->GetRemain();

    ui->label_ai1Remain->setText(
        QString("AI1 剩余: %1").arg(r1)
        );
    ui->label_ai2Remain->setText(
        QString("AI2 剩余: %1").arg(r2)
        );

    qDebug() << "updateAiRemainLabels: AI1 =" << r1 << ", AI2 =" << r2;
}

void InGameScene::onPlayClicked()
{
    // 收集当前选中的牌（UI 顺序索引）
    std::vector<int> indices;
    for (int i = 0; i < m_handPanels.size(); ++i) {
        if (m_handPanels[i]->isSelected())
            indices.push_back(i);
    }

    if (indices.empty()) {
        qDebug() << "没有选择牌";
        return;
    }

    clearLastPlay();  // 防止上一次显示和这次叠在一起

    // 🔴 注意：这里假设 Game::PlayerDiscard 返回 bool，
    // 如果你现在还是 void，可以先改成 bool 版本；
    // 或者临时把下面当成“必定成功”的用法。
    bool ok = m_game.PlayerDiscard(indices);

    if (!ok) {
        qDebug() << "❌ 出牌失败（不合法或无法压上）";
        return;
    }

    // UI 删除出掉的牌
    applyPlayerDiscardToUI(indices);

    // 更新中间“上家出的牌”
    showLastPlay();

    updateAiRemainLabels();

    // Game 内部已自动把轮到下一位（包括 AI 的 DiscardPhase），此处只需要继续处理阶段
    enterDiscardPhase();
}

void InGameScene::onPassClicked()
{
    qDebug() << "玩家选择过牌";
    m_game.PlayerPass();
    // 过牌后，上家出牌区域仍显示上一手，所以不调用 showLastPlay()
    enterDiscardPhase();
}

void InGameScene::onHintClicked()
{
    qDebug() << "玩家请求提示";

    // 1. 先把当前已经弹起的牌全部放回去（清空 UI 选中状态）
    int baseY = height() - 150;   // 和 createPlayer0HandPanels / applyPlayerDiscardToUI 里保持一致
    for (CardPanel* panel : std::as_const(m_handPanels))
    {
        if (panel->isSelected())
        {
            panel->setSelected(false);
            panel->move(panel->x(), baseY);   // 往下放 20 像素
        }
    }

    // 2. 调用游戏逻辑生成提示（会把提示方案写进玩家的 selection）
    m_game.PlayerHint();

    // 3. 读取玩家当前的 selection
    Player* human = m_game.GetPlayer(0);
    if (!human) {
        qDebug() << "Hint: human player is null?";
        return;
    }

    const CardGroup& sel = human->GetSelection();
    const std::set<int>& hintCards = sel.GetCards();

    if (hintCards.empty()) {
        qDebug() << "Hint: 没有可以提示的牌（可能是压不上，建议过牌）";
        return;
    }

    // 4. 遍历手牌面板，凡是牌号在 hintCards 里的，就弹起来
    for (CardPanel* panel : std::as_const(m_handPanels))
    {
        // 这里用的是你 CardPanel 里的 cardId() 接口
        int id = panel->cardId();
        if (hintCards.find(id) != hintCards.end())
        {
            if (!panel->isSelected())
            {
                panel->setSelected(true);
                panel->move(panel->x(), panel->y() - 20);  // 往上弹 20 像素
            }
        }
    }
}

void InGameScene::setStatusText(const QString &text)
{
    ui->label_status->setText(text);
}




