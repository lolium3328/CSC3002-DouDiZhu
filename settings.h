#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

private slots:
    void on_Slider_music_valueChanged(int value);
    void on_Slider_effect_valueChanged(int value);

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
