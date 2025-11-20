#include "gamestartscene.h"
#include "ui_gamestartscene.h"
#include "selectscene.h"

Gamestartscene::Gamestartscene(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Gamestartscene)
{
    ui->setupUi(this);
    this -> setWindowTitle("start");
    this->setFixedSize(800, 600);
}

Gamestartscene::~Gamestartscene()
{
    delete ui;
}
//进入选择界面
void Gamestartscene::on_start_clicked()
{
    SelectScene *w = new SelectScene();
    w -> show();
    this -> hide();
}


//退出程序
void Gamestartscene::on_exit_clicked()
{
    this -> close();
}

