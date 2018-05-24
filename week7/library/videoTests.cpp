/*******************************************************************************
* File: videoTests.cpp
*
* Description: videoTests utilizes assert and macros defined in testMain to test
               each method of a Video object individually
*
* Author: Alexander DuPree
*
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 22
*******************************************************************************/

#include "testMain.hpp"
#include "video.h"

namespace Test
{
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

                PRINT_RESULTS(4);

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

                    PRINT_RESULTS(4);
                }
            }
        }
        PRINT_TEST_CASE("TEST_VIDEO_CONSTRUCTORS" );
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
            PRINT_RESULTS(4);
        }
        PRINT_TEST_CASE("TEST_VIDEO_MUTATORS");
        return;
    }

    void RUN_VIDEO_TESTS()
    {
        TEST_VIDEO_CONSTRUCTORS();
        TEST_VIDEO_MUTATORS();
    }
}
