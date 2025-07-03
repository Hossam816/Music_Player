#include "song_model.h"

SongModel::SongModel(QObject *parent)
    : QObject(parent)
    , m_title("Unknown Title")
    , m_artist("Unknown Artist")
    , m_duration(0)
{
}

QString SongModel::getSongTitle() const
{
    return m_title;
}

QString SongModel::getArtist() const
{
    return m_artist;
}

int SongModel::getDuration() const
{
    return m_duration;
}
