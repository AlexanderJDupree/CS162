// Implementation for Library class
#include "library.h"

Library::Library() : bookIDs(0), videoIDs(0), musicIDs(0) {}


// Inspectors
const Book& Library::getBook(const size_t& ID)
{
    if (ID > SIZE)
    {
        throw "Invalid ID";
    }
    return books[ID];
}

const Video& Library::getVideo(const size_t& ID)
{
    if (ID > SIZE)
    {
        throw "Invalid ID";
    }
    return videos[ID];
}

const Music& Library::getMusic(const size_t& ID)
{
    if (ID > SIZE)
    {
        throw "Invalid ID";
    }
    return albums[ID];
}

// Mutators
void Library::setBook(const std::string& title, const std::string& author, 
                      const std::string& genre, const int& year, const size_t& ID)
{
    if (ID < SIZE)
    {
       books[ID].setTitle(title)->setAuthor(author)->setGenre(genre)->setYear(year);
    }
    return;
}

void Library::setVideo(const std::string& title, const std::string& actor, 
                      const std::string& genre, const int& year, const size_t& ID)
{
    if (ID < SIZE)
    {
       videos[ID].setTitle(title)->setLeadActor(actor)->setGenre(genre)->setYear(year);
    }
    return;
}

void Library::setMusic(const std::string& title, const std::string& artist, 
                       const int& numTracks, const size_t& ID)
{
    if (ID < SIZE)
    {
       albums[ID].setTitle(title)->setArtist(artist)->setNumTracks(numTracks);
    }
    return;
}



// Member Functions
std::stringstream& Library::listBooks(std::stringstream* stream)
{
    *stream << "TITLE\tAUTHOR\tYEAR\tGENRE\tID\n";
    for (size_t i = 0; i < bookIDs; i++)
    {
        *stream << books[i].getTitle() << '\t' << books[i].getAuthor() << '\t'
               << books[i].getYear() << '\t' << books[i].getGenre()  << '\t'
               << i << std::endl;
    }

    return *stream;
}

std::stringstream& Library::listVideos(std::stringstream* stream)
{
    *stream << "TITLE\tLEAD ACTOR\tYEAR\tGENRE\tID\n";
    for (size_t i = 0; i < videoIDs; i++)
    {
        *stream << videos[i].getTitle() << '\t' << videos[i].getLeadActor() 
                << '\t' << videos[i].getYear() << '\t' << videos[i].getGenre()  
                << '\t' << i << std::endl;
    }

    return *stream;
}

std::stringstream& Library::listMusic(std::stringstream* stream)
{
    *stream << "TITLE\tARTIST\tTRACKS\tID\n";
    for (size_t i = 0; i < musicIDs; i++)
    {
        *stream << albums[i].getTitle() << '\t' << albums[i].getArtist() 
                << '\t' << albums[i].getNumTracks() << '\t' << i << std::endl;
    }
    return *stream;
}