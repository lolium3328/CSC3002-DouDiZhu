#include "gamestartscene.h"
#include "settings.h"
#include "ui_gamestartscene.h"
#include "selectscene.h"
#include "settings.h"   // ← 加上设置窗口的头文件
#include "audiomanager.h"

Gamestartscene::Gamestartscene(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Gamestartscene)
{
    ui->setupUi(this);
    this->setWindowTitle("start");
    this->setFixedSize(800, 600);

    // 播放开始界面的 BGM
    AudioManager::instance().playBgm(
        "qrc:/sounds/music/strart.Mp3",
        true
        );
}

Gamestartscene::~Gamestartscene()
{
    delete ui;
}

// 进入选择界面
void Gamestartscene::on_start_clicked()
{
    // 如果你希望进入游戏就切掉开始 BGM，可以在这里停
    // AudioManager::instance().stopBgm();

    SelectScene *w = new SelectScene();
    w->show();
    this->hide();
}

// 退出程序
void Gamestartscene::on_exit_clicked()
{
    AudioManager::instance().stopBgm();
    this->close();
}

// 打开设置窗口
void Gamestartscene::on_settings_clicked()
{
    // 模态对话框：打开设置窗口，关掉前会暂停在这里
    settings dlg(this);
    dlg.exec();

    // 如果你希望非模态（打开后还能操作开始界面），可以用下面这段代替：
    /*
    auto *dlg = new SettingScene(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose); // 关窗时自动 delete
    dlg->show();
    */
}

