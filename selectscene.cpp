#include "selectscene.h"
#include "ui_selectscene.h"
#include "ingamescene.h"

SelectScene::SelectScene(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SelectScene)
{
    ui->setupUi(this);
    this -> setWindowTitle("select");
    this->setFixedSize(800, 600);
}

SelectScene::~SelectScene()
{
    delete ui;
}
//都跳转到游戏界面
void SelectScene::on_easy_clicked()
{
    InGameScene *w = new InGameScene();
    w -> show();
    this -> hide();
}


void SelectScene::on_median_clicked()
{
    InGameScene *w = new InGameScene();
    w -> show();
    this -> hide();
}

