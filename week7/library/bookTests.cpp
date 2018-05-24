/*******************************************************************************
* File: bookTests.cpp
*
* Description: bookTests utilizes assert and macros defined in testMain to test
               each method of a Book object individually
*
* Author: Alexander DuPree
*
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 22
*******************************************************************************/

#include "testMain.hpp"
#include "book.h"

namespace Test
{
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

                PRINT_RESULTS(4);
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

                    PRINT_RESULTS(4);
                }
            }
        }
        PRINT_TEST_CASE("TEST_BOOK_CONSTRUCTORS" );
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
            PRINT_RESULTS(4);
        }
        PRINT_TEST_CASE("TEST_BOOK_MUTATORS");
        return;
    }

    void RUN_BOOK_TESTS()
    {
        TEST_BOOK_CONSTRUCTORS();
        TEST_BOOK_MUTATORS();
    }
}
