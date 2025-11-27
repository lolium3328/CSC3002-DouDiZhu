#include "settings.h"
#include "ui_settings.h"
#include "audiomanager.h"

settings::settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::settings)
{
    ui->setupUi(this);
    // 设定 slider 的范围（0~100）
    ui->Slider_effect->setRange(0, 100);
    ui->Slider_music->setRange(0, 100);

    // 打开窗口时，把 slider 位置同步成当前音量
    ui->Slider_music->setValue(
        static_cast<int>(AudioManager::instance().bgmVolume() * 100.0f));
    ui->Slider_effect->setValue(
        static_cast<int>(AudioManager::instance().effectVolume() * 100.0f));
}

settings::~settings()
{
    delete ui;
}

void settings::on_Slider_music_valueChanged(int value)
{
    // slider 0~100 映射到 0.0~1.0
    float v = value / 100.0f;
    AudioManager::instance().setBgmVolume(v);
}

void settings::on_Slider_effect_valueChanged(int value)
{
    float v = value / 100.0f;
    AudioManager::instance().setEffectVolume(v);
}
