#include "testscene.h"
#include "ui_testscene.h"

testscene::testscene(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::testscene)
{
    ui->setupUi(this);
}

testscene::~testscene()
{
    delete ui;
}
