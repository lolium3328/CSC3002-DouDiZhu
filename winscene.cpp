#include "winscene.h"
#include "ui_winscene.h"

WinScene::WinScene(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WinScene)
{
    ui->setupUi(this);
}

WinScene::~WinScene()
{
    delete ui;
}
