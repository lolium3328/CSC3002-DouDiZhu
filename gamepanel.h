#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Gamepanel;
}
QT_END_NAMESPACE

class Gamepanel : public QMainWindow
{
    Q_OBJECT

public:
    Gamepanel(QWidget *parent = nullptr);
    ~Gamepanel();

private:
    Ui::Gamepanel *ui;
};
#endif // GAMEPANEL_H
