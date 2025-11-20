#ifndef WINSCENE_H
#define WINSCENE_H

#include <QDialog>

namespace Ui {
class WinScene;
}

class WinScene : public QDialog
{
    Q_OBJECT

public:
    explicit WinScene(QWidget *parent = nullptr);
    ~WinScene();

private:
    Ui::WinScene *ui;
};

#endif // WINSCENE_H
