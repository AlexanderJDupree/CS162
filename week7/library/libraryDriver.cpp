/*******************************************************************************
* File: libraryDriver.cpp
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 22
*******************************************************************************/

#include <cassert>
#include <iostream>
#include <sstream>
#include "video.h"
#include "music.h"
#include "book.h"
#include "library.h"

#define LOG(x) std::cout << x << std::endl;
#define GIVEN(x) std::cout << "\nGIVEN: " << x << std::endl;
#define THEN(x) std::cout << "THEN: " << x << std::endl;
#define WHEN(x) std::cout << "WHEN: " << x << std::endl;
#define AND_WHEN(x) std::cout << "\nAND_WHEN: " << x << std::endl;

void printTestResults(int assertions);
void printTestCase(std::string testCase);

void TEST_VIDEO_CONSTRUCTORS();
void TEST_VIDEO_MUTATORS();

void TEST_MUSIC_CONSTRUCTORS();
void TEST_MUSIC_MUTATORS();

void TEST_BOOK_CONSTRUCTORS();
void TEST_BOOK_MUTATORS();

void TEST_LIBRARY_CONSTRUCTORS();
void TEST_LIBRARY_MUTATORS();
void TEST_LIBRARY_INSPECTORS();

int main()
{
    // Video tests
    TEST_VIDEO_CONSTRUCTORS();
    TEST_VIDEO_MUTATORS();

    // Music tests
    TEST_MUSIC_CONSTRUCTORS();
    TEST_MUSIC_MUTATORS();

    // Book tests
    TEST_BOOK_CONSTRUCTORS();
    TEST_BOOK_MUTATORS();

    // Library tests
    TEST_LIBRARY_CONSTRUCTORS();
    TEST_LIBRARY_MUTATORS();
    TEST_LIBRARY_INSPECTORS();
    

    return 0;
}

void printTestResults(int assertions)
{
    std::cout << "\n\t" << assertions << " Assertions Passed!" << std::endl;
    std::cout << "------------------------------------------------------";
    std::cout << std::endl;
    return;
}

void printTestCase(std::string testCase)
{
    std::cout << testCase << " Complete!" << std::endl;
    std::cout << "=======================================================";
    std::cout << std::endl;
    return;
}

void TEST_VIDEO_CONSTRUCTORS()
{
    GIVEN("A default video object")
    {
        Video video;
        THEN("Its member variables are initialized to null values")
        {
            assert(video.getGenre() == "");
            assert(video.getLeadActor() == "");
            assert(video.getTitle() == "");
            assert(video.getYear() == 0);

            printTestResults(4);

        }
    }
    GIVEN("The movie 'Deadpool'")
    {
        const std::string TITLE = "Deadpool";
        const std::string LEAD_ACTOR = "Ryan Reynolds";
        const std::string GENRE = "action";
        const int YEAR = 2016;
        
        WHEN("The video object is initialized to the movie's attributes")
        {
            Video video(TITLE, LEAD_ACTOR, GENRE, YEAR);

            THEN("The videos attributes reflects the movie 'Deadpool'")
            {
                assert(video.getGenre() == GENRE);
                assert(video.getLeadActor() == LEAD_ACTOR);
                assert(video.getTitle() == TITLE);
                assert(video.getYear() == YEAR);

                printTestResults(4);
            }
        }
    }
    printTestCase("TEST_VIDEO_CONSTRUCTORS" );
    return;
}

void TEST_VIDEO_MUTATORS()
{
    GIVEN("A default video object")
    {
        const std::string TITLE = "Titanic";
        const std::string LEAD_ACTOR = "Leonardo DiCaprio";
        const std::string GENRE = "drama";
        const int YEAR= 1997;

        Video video;

        WHEN("We set the title member to 'Titanic'")
        {
            video.setTitle(TITLE);

            THEN("The title member is equal to 'Titanic'")
            {
                assert(video.getTitle() == TITLE);
            }
        }
        AND_WHEN("We set the lead actor member to 'Leonardo DiCaprio'")
        {
            video.setLeadActor(LEAD_ACTOR);
            
            THEN("The lead actor member is equal to 'Leonardo DiCaprio'")
            {
                assert(video.getLeadActor() == LEAD_ACTOR);
            }
        }
        AND_WHEN("We set the genre to 'drama'")
        {
            video.setGenre(GENRE);

            THEN("The genre member is equal to 'drama'")
            {
                assert(video.getGenre() == GENRE);
            }
        }
        AND_WHEN("We set the year to 1997")
        {
            video.setYear(YEAR);

            THEN("The year member is equal to 1997")
            {
                assert(video.getYear() == YEAR);
            }
        }
        printTestResults(4);
    }
    printTestCase("TEST_VIDEO_MUTATORS");
    return;
}

void TEST_MUSIC_CONSTRUCTORS()
{
    GIVEN("A default Music object")
    {
        Music album;
        THEN("Its member variables are initialized to null values")
        {
            assert(album.getArtist() == "");
            assert(album.getTitle() == "");
            assert(album.getNumTracks() == 0);

            printTestResults(3);

        }
    }
    GIVEN("The album 'Thriller'")
    {
        const std::string TITLE = "Thriller";
        const std::string ARTIST = "Michael Jackson";
        const int NUM_TRACKS = 12;
        
        WHEN("The Music object is initialized to 'Thriller's attributes")
        {
            Music album(TITLE, ARTIST, NUM_TRACKS);

            THEN("The Music objects members reflect Thriller's attributes")
            {
                assert(album.getArtist() == ARTIST);
                assert(album.getTitle() == TITLE);
                assert(album.getNumTracks() == NUM_TRACKS);

                printTestResults(3);
            }
        }
    }
    printTestCase("TEST_MUSIC_CONSTRUCTORS" );
    return;
}

void TEST_MUSIC_MUTATORS()
{
    GIVEN("A default Music object")
    {
        const std::string TITLE = "Back in Black";
        const std::string ARTIST = "AC/DC";
        const int NUM_TRACKS = 10;

        Music album;

        WHEN("We set the artist to 'AC/DC'")
        {
            album.setArtist(ARTIST);

            THEN("The artist member is equal to 'AC/DC'")
            {
                assert(album.getArtist() == ARTIST);
            }
        }
        AND_WHEN("We set the tite to 'Back in Black'")
        {
            album.setTitle(TITLE);

            THEN("The title member is equal to 'Back in Black'")
            {
                assert(album.getTitle() == TITLE);
            }
        }
        AND_WHEN("We set the number of tracks to 10")
        {
            album.setNumTracks(NUM_TRACKS);

            THEN("The year member is equal to 1997")
            {
                assert(album.getNumTracks() == NUM_TRACKS);
            }
        }
        printTestResults(3);
    }
    printTestCase("TEST_MUSIC_MUTATORS");
    return;
}

void TEST_BOOK_CONSTRUCTORS()
{
    GIVEN("A default Book object")
    {
        Book book;

        THEN("Its member variables are initialized to null values")
        {
            assert(book.getGenre() == "");
            assert(book.getAuthor() == "");
            assert(book.getTitle() == "");
            assert(book.getYear() == 0);

            printTestResults(4);

        }
    }
    GIVEN("The book 'Game of Thrones'")
    {
        const std::string TITLE = "Game of Thrones";
        const std::string AUTHOR = "George R.R. Martin";
        const std::string GENRE = "fantasy";
        const int YEAR = 1996;
        
        WHEN("The book object is initialized to the book's attributes")
        {
            Book book(TITLE, AUTHOR, GENRE, YEAR);

            THEN("The books attributes reflects the book 'Game of Thrones'")
            {
                assert(book.getGenre() == GENRE);
                assert(book.getAuthor() == AUTHOR);
                assert(book.getTitle() == TITLE);
                assert(book.getYear() == YEAR);

                printTestResults(4);
            }
        }
    }
    printTestCase("TEST_BOOK_CONSTRUCTORS" );
    return;
}

void TEST_BOOK_MUTATORS()
{
    GIVEN("A default Book object")
    {
        const std::string TITLE = "Lord of the Rings";
        const std::string AUTHOR = "J.R.R. Tolkein";
        const std::string GENRE = "fantasy";
        const int YEAR= 1954;

        Book book;

        WHEN("We set the title member to 'Lord of the Rings'")
        {
            book.setTitle(TITLE);

            THEN("The title member is equal to 'Lord of the Rings'")
            {
                assert(book.getTitle() == TITLE);
            }
        }
        AND_WHEN("We set the author member to 'J.R.R. Tolkein'")
        {
            book.setAuthor(AUTHOR);
            
            THEN("The author member is equal to 'J.R.R. Tolken'")
            {
                assert(book.getAuthor() == AUTHOR);
            }
        }
        AND_WHEN("We set the genre to 'fantasy'")
        {
            book.setGenre(GENRE);

            THEN("The genre member is equal to 'fantasy'")
            {
                assert(book.getGenre() == GENRE);
            }
        }
        AND_WHEN("We set the year to 1954")
        {
            book.setYear(YEAR);

            THEN("The year member is equal to 1954")
            {
                assert(book.getYear() == YEAR);
            }
        }
        printTestResults(4);
    }
    printTestCase("TEST_BOOK_MUTATORS");
    return;
}

void TEST_LIBRARY_CONSTRUCTORS()
{
    GIVEN("A default Library object")
    {
        Library library;

        THEN("Listing books, videos, and music returns only the field names")
        {
            std::stringstream stream;

            library.listBooks(&stream);

            assert(stream.str() == "TITLE\tAUTHOR\tYEAR\tGENRE\tID\n");

            stream.str("");

            library.listVideos(&stream);
            
            assert(stream.str() == "TITLE\tLEAD ACTOR\tYEAR\tGENRE\tID\n");

            stream.str("");

            library.listMusic(&stream);

            assert(stream.str() == "TITLE\tARTIST\tTRACKS\tID\n");

            printTestResults(4);
        }
    }
    printTestCase("TEST_LIBRARY_CONSTRUCTORS");
}

void TEST_LIBRARY_MUTATORS()
{
    GIVEN("An empty Library object")
    {
        Library library;

        WHEN("We specify the ID of the book to be set and provide attributes")
        {
            library.setBook("Clean Code", "Robert C. Martin", "code",  2008, 0);

            THEN("The book will equal the provided attributes")
            {
                const Book& book = library.getBook(0);

                assert(book.getAuthor() == "Robert C. Martin");
                assert(book.getGenre() == "code");
                assert(book.getTitle() == "Clean Code");
                assert(book.getYear() == 2008);

                printTestResults(4);
            }
        }
        AND_WHEN("We specify the ID of Video to be set and provide attributes")
        {
            library.setVideo("Scarface", "Al Pacino", "drama", 1983, 1);

            THEN("The video will equal the provided attributes")
            {
                const Video& video = library.getVideo(1);

                assert(video.getGenre() == "drama");
                assert(video.getLeadActor() == "Al Pacino");
                assert(video.getTitle() == "Scarface");
                assert(video.getYear() == 1983);

                printTestResults(4);
            }
        }
        AND_WHEN("We specify the ID of Music to be set and provide attributes")
        {
            library.setMusic("Paranoid", "Black Sabbath", 8, 0);

            THEN("The Music will equal the provided attributes")
            {
                const Music& album = library.getMusic(0);

                assert(album.getTitle() == "Paranoid");
                assert(album.getArtist() == "Black Sabbath");
                assert(album.getNumTracks() == 8);

                printTestResults(4);
            }
        }
    }
    printTestCase("TEST_LIBRARY_MUTATORS");
}

void TEST_LIBRARY_INSPECTORS()
{
    GIVEN("An empty Library object")
    {
        Library library;

        WHEN("We attempt to access a book with an out of bounds ID")
        {
            THEN("The Library object throws an error")
            {
                try
                {
                    library.getBook(300);
                }
                catch(const char* error)
                {
                    LOG(error);
                }
                printTestResults(1);
            }
        }
    }
}