#include "losescene.h"
#include "ui_losescene.h"

LoseScene::LoseScene(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoseScene)
{
    ui->setupUi(this);
}

LoseScene::~LoseScene()
{
    delete ui;
}
