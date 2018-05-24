/*******************************************************************************
* File: library.h

* Description: Library class contains arrays to hold instantiated Music, Book,
               and Video objects. Library provides methods for retrieving and
               setting the members of these stored objects

* Attributes and Methods:
public:

    - Constructors
    Library();
    // Precondition:
    // Postconditions: Instantiates a library object with null values for its
                       arrays and IDs

    - Inspectors
    const Book& getBook(const size_t& ID);
    // Preconditions: An ID within valid bounds of the Books array
    // Postcondition: Returns a const reference to the book at position ID.
                      Throws a const char* error if ID is out of bounds

    const Video& getVideo(const size_t& ID);
    // Preconditions: An ID within valid bounds of the videos array
    // Postcondition: Returns a const reference to the Video at position ID.
                      Throws a const char* error if ID is out of bounds

    const Music& getMusic(const size_t& ID);
    // Preconditions: An ID within valid bounds of the albums array
    // Postcondition: Returns a const reference to the Music at position ID.
                      Throws a const char* error if ID is out of bounds

    - Mutators
    void setBook(const std::string& title, const std::string& author,
                 const std::string& genre, const int& year, const size_t& ID);
    // Preconditions: An ID within valid bounds of the books array
    // Postcondition: Sets the book objects members to the values of the provided
                      arguments ONLY if the ID is within bounds

    void setVideo(const std::string& title, const std::string& actor,
                  const std::string& genre, const int& year, const size_t& ID);
    // Preconditions: An ID within valid bounds of the books array
    // Postcondition: Sets the Video object's members to the values of the provided
                      arguments ONLY if the ID is within bounds

    void setMusic(const std::string& title, const std::string& artist,
                  const int& numTracks, const size_t& ID);
    // Preconditions: An ID within valid bounds of the albums array
    // Postcondition: Sets the Music object's members to the values of the provided
                      arguments ONLY if the ID is within bounds


    // Member functions
    std::stringstream& listBooks(std::stringstream* stream);
    // Preconditions: A valid address for a string stream object
    // Postcondition: inserts into the stream the information of each book and
                      its attributes contained in the books array. Returns the
                      address of the stream.

    std::stringstream& listVideos(std::stringstream* stream);
    // Preconditions: A valid address for a string stream object
    // Postcondition: inserts into the stream the information of each video and
                      its attributes contained in the videos array. Returns the
                      address of the stream.

    std::stringstream& listMusic(std::stringstream* stream);
    // Preconditions: A valid address for a string stream object
    // Postcondition: inserts into the stream the information of each album and
                      its attributes contained in the albums array. Returns the
                      address of the stream.


private:

    static const size_t SIZE = 2; - Represents the max storage available for eac
                                    category in the library

    size_t bookIDs; - Represents the unique IDs assigned to books
    size_t videoIDs; - Represents the unique IDs assigned to videos
    size_t musicIDs; - Represents the unique IDs assigned to music

    Book books[SIZE]; - Holds the books contained in the library
    Music albums[SIZE]; - Holds the albums contained in the library
    Video videos[SIZE]; - Holds the videos contained in the library

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
