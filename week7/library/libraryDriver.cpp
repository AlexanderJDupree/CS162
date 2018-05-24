/*******************************************************************************
* File: libraryDriver.cpp
*
* Description: libraryDriver runs the test fixtures for each class. In the
               process of unit testing each individual class, the driver file
               was becoming ungainly long. So I separated the methods to test
               each class into individual classes.
*
* Author: Alexander DuPree
*
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 22
*******************************************************************************/

#include "testMain.hpp"

int main()
{
    // Video tests
    Test::RUN_VIDEO_TESTS();

    // Music tests
    Test::RUN_MUSIC_TESTS();

    // Book tests
    Test::RUN_BOOK_TESTS();

    // Library tests
    Test::RUN_LIBRARY_TESTS();

    return 0;
}
