// Implementation for Music class

#include "music.h"

Music::Music() : title(""), artist(""), numTracks(0) {}

Music::Music(std::string title, std::string artist, int numTracks)
    : title(title), artist(artist), numTracks(0) {}

const std::string& Music::getTitle() const
{
    return title;
}

const std::string& Music::getArtist() const
{
    return artist;
}

const int& Music::getNumTracks() const
{
    return numTracks;
}

Music* Music::setTitle(const std::string& title)
{
    this->title = title;
    return this;
}

Music* Music::setArtist(const std::string& artist)
{
    this->title = artist;
    return this;
}

