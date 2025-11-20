#ifndef LOSESCENE_H
#define LOSESCENE_H

#include <QDialog>

namespace Ui {
class LoseScene;
}

class LoseScene : public QDialog
{
    Q_OBJECT

public:
    explicit LoseScene(QWidget *parent = nullptr);
    ~LoseScene();

private:
    Ui::LoseScene *ui;
};

#endif // LOSESCENE_H
