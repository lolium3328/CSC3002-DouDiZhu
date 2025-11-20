#ifndef SELECTSCENE_H
#define SELECTSCENE_H

#include <QDialog>

namespace Ui {
class SelectScene;
}

class SelectScene : public QDialog
{
    Q_OBJECT

public:
    explicit SelectScene(QWidget *parent = nullptr);
    ~SelectScene();

private slots:
    void on_easy_clicked();

    void on_median_clicked();

private:
    Ui::SelectScene *ui;
};

#endif // SELECTSCENE_H
