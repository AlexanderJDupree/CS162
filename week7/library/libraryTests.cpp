/*******************************************************************************
* File: libraryTests.cpp
*
* Description: libraryTests utilizes assert and macros defined in testMain to test
               each method of a library object individually
*
* Author: Alexander DuPree
*
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 22
*******************************************************************************/

#include "testMain.hpp"
#include "library.h"

namespace Test
{
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

                PRINT_RESULTS(4);
            }
        }
        PRINT_TEST_CASE("TEST_LIBRARY_CONSTRUCTORS");
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

                    PRINT_RESULTS(4);
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

                    PRINT_RESULTS(4);
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

                    PRINT_RESULTS(4);
                }
            }
        }
        PRINT_TEST_CASE("TEST_LIBRARY_MUTATORS");
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
                    PRINT_RESULTS(1);
                }
            }
        }
        PRINT_TEST_CASE("TEST_LIBRARY_INSPECTORS");
    }

    void RUN_LIBRARY_TESTS()
    {
        TEST_LIBRARY_CONSTRUCTORS();
        TEST_LIBRARY_MUTATORS();
        TEST_LIBRARY_INSPECTORS();
    }
}
