/*******************************************************************************
* File: testMain.hpp
*
* Description: testMain provides the unit testing framework for use in other
               testing files
*
* Author: Alexander DuPree
*
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 22
*******************************************************************************/

#ifndef TEST_MAIN
#define TEST_MAIN

#include <cassert>
#include <sstream>
#include <iostream>
#include <string>

namespace Test
{
    #define LOG(x) std::cout << x << std::endl;

    #define GIVEN(x) std::cout << "\nGIVEN: " << x << std::endl;

    #define THEN(x) std::cout << "THEN: " << x << std::endl;

    #define WHEN(x) std::cout << "WHEN: " << x << std::endl;

    #define AND_WHEN(x) std::cout << "\nAND_WHEN: " << x << std::endl;

    #define PRINT_RESULTS(assertions) {\
        std::cout << "\n\t" << assertions << " Assertions Passed!" << std::endl;\
        std::cout << "------------------------------------------------------";\
        std::cout << std::endl;\
    }

    #define PRINT_TEST_CASE(testCase) {\
        std::cout << testCase << " Complete!" << std::endl;\
        std::cout << "=======================================================";\
        std::cout << std::endl;\
    }

    // Video tests
    void TEST_VIDEO_CONSTRUCTORS();
    void TEST_VIDEO_MUTATORS();
    void RUN_VIDEO_TESTS();

    // Music tests
    void TEST_MUSIC_CONSTRUCTORS();
    void TEST_MUSIC_MUTATORS();
    void RUN_MUSIC_TESTS();

    // Book tests
    void TEST_BOOK_CONSTRUCTORS();
    void TEST_BOOK_MUTATORS();
    void RUN_BOOK_TESTS();

    // Library tests
    void TEST_LIBRARY_CONSTRUCTORS();
    void TEST_LIBRARY_MUTATORS();
    void TEST_LIBRARY_INSPECTORS();
    void RUN_LIBRARY_TESTS();

}

#endif // TEST_MAIN


