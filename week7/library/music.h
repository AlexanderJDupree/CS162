/*******************************************************************************
* File: triangle.h

* Description: 

* Attributes and Methods: 
    

* Author: Alexander DuPree

* Date: 2018 - 05 - 21
*******************************************************************************/

#ifndef MUSIC_H
#define MUSIC_H

#include <string>

class Music
{
public:
    Music();

    Music(std::string title, std::string artist, int numTracks);

    const std::string& getTitle() const;
    const std::string& getArtist() const;
    const int& getNumTracks() const;

    Music* setTitle(const std::string& title);
    Music* setArtist(const std::string& artist);

private:

    std::string title;
    std::string artist;

    int numTracks;

};

#endif // MUSIC_H