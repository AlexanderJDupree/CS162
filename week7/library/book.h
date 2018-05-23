/*******************************************************************************
* Class: Book

* Description: Book class provides a basic abstract data structure for storing
               relevant information for a book

* Attributes and Methods: 
 
public:

    - Constructors
    Book();
    // Precondition: 
    // Postcondition: Instantiates a Book object with null values

    Book(std::string title, std::string author, std::string genre, int year);
    // Precondition: 
    // Postcondition: Instantiates a Book object with members initialized to 
                      argument values

    - Inspectors
    const std::string& getTitle() const;
    // Precondition: 
    // Postcondition: Return const reference to title member

    const std::string& getAuthor() const;
    // Precondition: 
    // Postcondition: Return const reference to author member

    const std::string& getGenre() const;
    // Precondition: 
    // Postcondition: Return const reference to genre member

    const int& getYear() const;
    // Precondition: 
    // Postcondition: Return const reference to year member

    - Mutators
    Book* setTitle(const std::string& title);
    // Precondition: A valid string reference 
    // Postcondition: sets the value of title member to title argument

    Book* setAuthor(const std::string& author);
    // Precondition:  A valid string reference
    // Postcondition: sets the value of author member to author argument

    Book* setGenre(const std::string& genre);
    // Precondition:  A valid string reference
    // Postcondition: sets the value of genre member to genre argument

    Book* setYear(const int& year);
    // Precondition: 
    // Postcondition: 

private:

    std::string title;
    std::string author;
    std::string genre;
    int year;

   

* Author: Alexander DuPree

* Date: 2018 - 05 - 21
*******************************************************************************/

#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:

    Book();

    Book(std::string title, std::string author, std::string genre, int year);

    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    const std::string& getGenre() const;
    const int& getYear() const;

    Book* setTitle(const std::string& title);
    Book* setAuthor(const std::string& author);
    Book* setGenre(const std::string& genre);
    Book* setYear(const int& year);

private:

    std::string title;
    std::string author;
    std::string genre;

    int year;

};

#endif // BOOK_H
