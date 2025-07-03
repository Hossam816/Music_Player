#ifndef MUSICCONTROLLER_H
#define MUSICCONTROLLER_H

#include <QObject>
#include <QString>
#include <QMediaPlayer>
#include <QStringList>
#include <QUrl>

class MusicController : public QObject
{
    Q_OBJECT

public:
    explicit MusicController(QObject *parent = nullptr);
    Q_INVOKABLE void OpenFolder();
    
    Q_INVOKABLE void Play();
    Q_INVOKABLE void Pause();
    Q_INVOKABLE void Next();
    Q_INVOKABLE void Previous();
    Q_INVOKABLE void SetVolume(int volume);
    Q_INVOKABLE void SetPosition(qint64 position);
    Q_INVOKABLE void SeekToPosition(qint64 position);

    Q_PROPERTY(QString currentSong READ CurrentSong NOTIFY currentSongChanged);
    Q_PROPERTY(int volume READ Volume WRITE SetVolume NOTIFY volumeChanged);
    Q_PROPERTY(bool isPlaying READ IsPlaying NOTIFY playingStateChanged);
    Q_PROPERTY(int playlistSize READ PlaylistSize NOTIFY playlistChanged);
    Q_PROPERTY(qint64 position READ Position NOTIFY positionChanged);
    Q_PROPERTY(qint64 duration READ Duration NOTIFY durationChanged);
    Q_PROPERTY(QString formattedPosition READ FormattedPosition NOTIFY positionChanged);
    Q_PROPERTY(QString formattedDuration READ FormattedDuration NOTIFY durationChanged);

signals:
    void currentSongChanged();
    void volumeChanged();
    void playingStateChanged();
    void playlistChanged();
    void positionChanged();
    void durationChanged();

private:
    void LoadSongsFromFolder(const QString& folderPath_);
    QString CurrentSong() const;
    int Volume() const;
    bool IsPlaying() const;
    int PlaylistSize() const;
    qint64 Position() const;
    qint64 Duration() const;
    QString FormattedPosition() const;
    QString FormattedDuration() const;
    QString formatTime(qint64 milliseconds) const;

    QMediaPlayer* mPlayer;
    QStringList mSupportedExtensions = { "mp3","wav","flac" };
    QStringList mPlaylist;
    int mCurrentIndex = -1;
    QString mCurrentSong;
    int mVolume = 50;
    qint64 mDuration = 0;
};

#endif // MUSICCONTROLLER_H 