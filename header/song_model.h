#ifndef SONGMODEL_H
#define SONGMODEL_H

#include <QObject>
#include <QString>

class SongModel : public QObject
{
    Q_OBJECT

public:
    explicit SongModel(QObject *parent = nullptr);

public slots:
    QString getSongTitle() const;
    QString getArtist() const;
    int getDuration() const;

private:
    QString m_title;
    QString m_artist;
    int m_duration;
};

#endif // SONGMODEL_H
