#include "gamepanel.h"
#include "./ui_gamepanel.h"

Gamepanel::Gamepanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gamepanel)
{
    ui->setupUi(this);
}

Gamepanel::~Gamepanel()
{
    delete ui;
}
