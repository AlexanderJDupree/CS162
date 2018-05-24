/*******************************************************************************
* File: musicTests.cpp
*
* Description: musicTests utilizes assert and macros defined in testMain to test
               each method of a Music object individually
*
* Author: Alexander DuPree
*
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 22
*******************************************************************************/

#include "testMain.hpp"
#include "music.h"

namespace Test
{
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

                PRINT_RESULTS(3);

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

                    PRINT_RESULTS(3);
                }
            }
        }
        PRINT_TEST_CASE("TEST_MUSIC_CONSTRUCTORS" );
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
            PRINT_RESULTS(3);
        }
        PRINT_TEST_CASE("TEST_MUSIC_MUTATORS");
        return;
    }

    void RUN_MUSIC_TESTS()
    {
        TEST_MUSIC_CONSTRUCTORS();
        TEST_MUSIC_MUTATORS();
    }
}
