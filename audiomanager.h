#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <QObject>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>

class AudioManager : public QObject
{
    Q_OBJECT
public:
    static AudioManager& instance();

    // ---- BGM ----
    void playBgm(const QString &resourcePath, bool loop = true);
    void stopBgm();
    void setBgmVolume(float volume);   // 0.0 ~ 1.0
    float bgmVolume() const;

    // ---- Sound Effect ----
    void setEffectVolume(float volume); // 0.0 ~ 1.0
    float effectVolume() const;

    void playEffect(const QString &resourcePath); // 使用当前的 effectVolume

private:
    explicit AudioManager(QObject *parent = nullptr);
    Q_DISABLE_COPY_MOVE(AudioManager);

    QMediaPlayer *m_bgmPlayer;
    QAudioOutput *m_bgmOutput;

    float m_effectVolume;      // 全局音效音量
};

#endif // AUDIOMANAGER_H

