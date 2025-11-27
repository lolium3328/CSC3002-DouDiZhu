#include "audiomanager.h"
#include <QUrl>
#include <QDebug>

AudioManager &AudioManager::instance()
{
    static AudioManager mgr;
    return mgr;
}

AudioManager::AudioManager(QObject *parent)
    : QObject(parent)
    , m_bgmPlayer(new QMediaPlayer(this))
    , m_bgmOutput(new QAudioOutput(this))
    , m_effectVolume(1.0f)   // 默认音效音量 100%
{
    m_bgmPlayer->setAudioOutput(m_bgmOutput);
    m_bgmOutput->setVolume(0.3f);  // 默认 BGM 音量 30%

    connect(m_bgmPlayer, &QMediaPlayer::errorOccurred,
            this, [](QMediaPlayer::Error error){
                qWarning() << "BGM error:" << error;
            });
}

void AudioManager::playBgm(const QString &resourcePath, bool loop)
{
    m_bgmPlayer->setSource(QUrl(resourcePath));
    m_bgmPlayer->setLoops(loop ? QMediaPlayer::Infinite : 1);
    m_bgmPlayer->play();
}

void AudioManager::stopBgm()
{
    m_bgmPlayer->stop();
}

void AudioManager::setBgmVolume(float volume)
{
    if (volume < 0.0f) volume = 0.0f;
    if (volume > 1.0f) volume = 1.0f;
    m_bgmOutput->setVolume(volume);
}

float AudioManager::bgmVolume() const
{
    return m_bgmOutput->volume();
}

// ---------- Effect volume ----------
void AudioManager::setEffectVolume(float volume)
{
    if (volume < 0.0f) volume = 0.0f;
    if (volume > 1.0f) volume = 1.0f;
    m_effectVolume = volume;
}

float AudioManager::effectVolume() const
{
    return m_effectVolume;
}

// 用当前全局 effectVolume 播放一个音效
void AudioManager::playEffect(const QString &resourcePath)
{
    auto *player = new QMediaPlayer(this);
    auto *output = new QAudioOutput(this);

    player->setAudioOutput(output);
    output->setVolume(m_effectVolume);          // 用全局音效音量
    player->setSource(QUrl(resourcePath));

    connect(player, &QMediaPlayer::mediaStatusChanged,
            this, [player, output](QMediaPlayer::MediaStatus status){
                if (status == QMediaPlayer::EndOfMedia ||
                    status == QMediaPlayer::InvalidMedia) {
                    player->deleteLater();
                    output->deleteLater();
                }
            });

    player->play();
}
