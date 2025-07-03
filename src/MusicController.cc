#include "MusicController.h"
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <QUrl>
#include <QFileDialog>
#include <QAudioOutput>
#include <QDebug>
#include <QTimer>

MusicController::MusicController(QObject *parent)
    : QObject(parent)
    , mPlayer(new QMediaPlayer(this))
    , mCurrentIndex(-1)
    , mCurrentSong("No song selected")
    , mVolume(50)
    , mDuration(0)
{
    // Set initial volume
    mPlayer->setAudioOutput(new QAudioOutput(this));
    mPlayer->audioOutput()->setVolume(mVolume / 100.0);
    
    // Connect media player signals
    connect(mPlayer, &QMediaPlayer::mediaStatusChanged, [this](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            Next(); // Auto-play next song
        }
    });
    
    connect(mPlayer, &QMediaPlayer::playbackStateChanged, [this](QMediaPlayer::PlaybackState state) {
        emit playingStateChanged();
    });

    // Connect position and duration signals
    connect(mPlayer, &QMediaPlayer::positionChanged, [this](qint64 position) {
        emit positionChanged();
    });

    connect(mPlayer, &QMediaPlayer::durationChanged, [this](qint64 duration) {
        mDuration = duration;
        emit durationChanged();
    });

    // Create a timer to update position more frequently
    QTimer* positionTimer = new QTimer(this);
    connect(positionTimer, &QTimer::timeout, [this]() {
        if (mPlayer->playbackState() == QMediaPlayer::PlayingState) {
            emit positionChanged();
        }
    });
    positionTimer->start(100); // Update every 100ms
}

void MusicController::OpenFolder()
{
    QString folderPath = QFileDialog::getExistingDirectory(nullptr, "Select Music Folder");
    if (!folderPath.isEmpty()) {
        LoadSongsFromFolder(folderPath);
    }
}

void MusicController::Play()
{
    if (mCurrentIndex >= 0 && mCurrentIndex < mPlaylist.size()) {
        mPlayer->play();
    }
}

void MusicController::Pause()
{
    mPlayer->pause();
}

void MusicController::Next()
{
    if (mPlaylist.isEmpty()) return;
    
    mCurrentIndex = (mCurrentIndex + 1) % mPlaylist.size();
    QString songPath = mPlaylist[mCurrentIndex];
    mCurrentSong = QFileInfo(songPath).fileName();
    
    mPlayer->setSource(QUrl::fromLocalFile(songPath));
    mPlayer->play();
    
    emit currentSongChanged();
}

void MusicController::Previous()
{
    if (mPlaylist.isEmpty()) return;
    
    mCurrentIndex = (mCurrentIndex - 1 + mPlaylist.size()) % mPlaylist.size();
    QString songPath = mPlaylist[mCurrentIndex];
    mCurrentSong = QFileInfo(songPath).fileName();
    
    mPlayer->setSource(QUrl::fromLocalFile(songPath));
    mPlayer->play();
    
    emit currentSongChanged();
}

void MusicController::SetVolume(int volume)
{
    if (volume < 0) volume = 0;
    if (volume > 100) volume = 100;
    
    mVolume = volume;
    if (mPlayer->audioOutput()) {
        mPlayer->audioOutput()->setVolume(volume / 100.0);
    }
    emit volumeChanged();
}

void MusicController::SetPosition(qint64 position)
{
    if (position >= 0 && position <= mDuration) {
        mPlayer->setPosition(position);
    }
}

void MusicController::SeekToPosition(qint64 position)
{
    SetPosition(position);
}

void MusicController::LoadSongsFromFolder(const QString& folderPath)
{
    mPlaylist.clear();
    mCurrentIndex = -1;
    
    QDir dir(folderPath);
    QFileInfoList files = dir.entryInfoList(QDir::Files);
    
    for (const QFileInfo& file : files) {
        QString extension = file.suffix().toLower();
        if (mSupportedExtensions.contains(extension)) {
            mPlaylist.append(file.absoluteFilePath());
        }
    }
    
    qDebug() << "Loaded" << mPlaylist.size() << "songs from folder:" << folderPath;
    
    if (!mPlaylist.isEmpty()) {
        mCurrentIndex = 0;
        mCurrentSong = QFileInfo(mPlaylist[0]).fileName();
        mPlayer->setSource(QUrl::fromLocalFile(mPlaylist[0]));
        emit currentSongChanged();
        emit playlistChanged();
    }
}

QString MusicController::CurrentSong() const
{
    return mCurrentSong;
}

int MusicController::Volume() const
{
    return mVolume;
}

bool MusicController::IsPlaying() const
{
    return mPlayer->playbackState() == QMediaPlayer::PlayingState;
}

int MusicController::PlaylistSize() const
{
    return mPlaylist.size();
}

qint64 MusicController::Position() const
{
    return mPlayer->position();
}

qint64 MusicController::Duration() const
{
    return mDuration;
}

QString MusicController::FormattedPosition() const
{
    return formatTime(Position());
}

QString MusicController::FormattedDuration() const
{
    return formatTime(mDuration);
}

QString MusicController::formatTime(qint64 milliseconds) const
{
    if (milliseconds <= 0) return "0:00";
    
    qint64 seconds = milliseconds / 1000;
    qint64 minutes = seconds / 60;
    seconds = seconds % 60;
    
    return QString("%1:%2").arg(minutes).arg(seconds, 2, 10, QChar('0'));
} 