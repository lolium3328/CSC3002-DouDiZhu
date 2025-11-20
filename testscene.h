#ifndef TESTSCENE_H
#define TESTSCENE_H

#include <QDialog>

namespace Ui {
class testscene;
}

class testscene : public QDialog
{
    Q_OBJECT

public:
    explicit testscene(QWidget *parent = nullptr);
    ~testscene();

private:
    Ui::testscene *ui;
};

#endif // TESTSCENE_H
