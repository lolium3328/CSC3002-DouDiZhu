#ifndef GAMESTARTSCENE_H
#define GAMESTARTSCENE_H

#include <QDialog>
#include "audiomanager.h"

namespace Ui {
class Gamestartscene;
}

class Gamestartscene : public QDialog
{
    Q_OBJECT

public:
    explicit Gamestartscene(QWidget *parent = nullptr);
    ~Gamestartscene();

private slots:
    void on_start_clicked();
    void on_exit_clicked();
    void on_settings_clicked();

private:
    Ui::Gamestartscene *ui;
};

#endif // GAMESTARTSCENE_H
