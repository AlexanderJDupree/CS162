/*******************************************************************************
* File: triangle.h

* Description: 

* Attributes and Methods: 
    

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

    Book* setTitle(const std::string&);
    Book* setAuthor(const std::string&);
    Book* setGenre(const std::string&);
    Book* setYear(const int& year);

private:

    std::string title;
    std::string author;
    std::string genre;

    int year;

};

#endif // BOOK_H
