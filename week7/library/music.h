/*******************************************************************************
* Class: Music

* Description: Music class provides a basic abstract data structure for storing
               information pertaining to an album

* Attributes and Methods: 
 // public:
    - Constructors
    Music();
    // Precondition: 
    // Postcondition: Instantiates a Music object with null values

    Music(std::string title, std::string artist, int numTracks);
    // Precondition: 
    // Postcondition: Instantiates a Music object with members matching 
                      corresponding arguments

    - Inspectors 
    const std::string& getTitle() const;
    // Precondition: 
    // Postcondition: Returns a const reference to title member

    const std::string& getArtist() const;
    // Precondition: 
    // Postcondition:  Returns a const reference to artist member

    const int& getNumTracks() const;
    // Precondition: 
    // Postcondition: Returns a const reference to numTracks member

    - Mutators 
    Music* setTitle(const std::string& title);
    // Precondition: A valid string reference
    // Postcondition: sets title member to the value of title argument

    Music* setArtist(const std::string& artist);
    // Precondition:  A valid string reference
    // Postcondition: sets artist member to the value of artist argument

    Music* setNumTracks(const int& numTracks);
    // Precondition:  a valid int reference
    // Postcondition: sets numTracks member to the value of numTracks argument

// private:

    - Member Variables 
    std::string title - Represents the title of the album
    std::string artist - Represents the name of the artist
    int numTracks - Represents the number of tracks in the album

* Author: Alexander DuPree

* Date: 2018 - 05 - 21
*******************************************************************************/

#ifndef MUSIC_H
#define MUSIC_H

#include <string>

class Music
{
public:
    // Constructors
    Music();

    Music(std::string title, std::string artist, int numTracks);

    // Inspectors
    const std::string& getTitle() const;
    const std::string& getArtist() const;
    const int& getNumTracks() const;

    // Mutators
    Music* setTitle(const std::string& title);
    Music* setArtist(const std::string& artist);
    Music* setNumTracks(const int& numTracks);

private:

    // Member Variables
    std::string title;
    std::string artist;
    int numTracks;

};

#endif // MUSIC_H

