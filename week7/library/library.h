/*******************************************************************************
* File: library.h

* Description: 

* Author: Alexander DuPree

* Compiler:  GNU GCC 5.4.0

* Date: 2018-05-22
*******************************************************************************/

#ifndef LIBRAY_H
#define LIBRARY_H

#include <sstream>
#include "book.h"
#include "music.h"
#include "video.h"

class Library
{
public:

    Library();

    // Inspectors
    const Book& getBook(const size_t& ID);
    const Video& getVideo(const size_t& ID);
    const Music& getMusic(const size_t& ID);

    // Mutators
    void setBook(const std::string& title, const std::string& author, 
                 const std::string& genre, const int& year, const size_t& ID);
    void setVideo(const std::string& title, const std::string& actor, 
                  const std::string& genre, const int& year, const size_t& ID);
    void setMusic(const std::string& title, const std::string& artist, 
                  const int& numTracks, const size_t& ID);


    // Member functions
    std::stringstream& listBooks(std::stringstream* stream);
    std::stringstream& listVideos(std::stringstream* stream);
    std::stringstream& listMusic(std::stringstream* stream);

private:

    static const size_t SIZE = 2;

    size_t bookIDs;
    size_t videoIDs;
    size_t musicIDs;

    Book books[SIZE];
    Music albums[SIZE];
    Video videos[SIZE];
    
};

#endif // LIBRARY_H
