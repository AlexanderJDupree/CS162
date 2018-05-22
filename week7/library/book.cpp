// Implementation for Book class

#include "book.h"

Book::Book() : title(""), author(""), genre(""), year(0) {}

Book::Book(std::string title, std::string author, std::string genre, int year)
    : title(title), author(author), genre(genre), year(year) {}

const std::string& Book::getTitle() const
{
    return title;
}

const std::string& Book::getAuthor() const
{
    return author;
}

const std::string& Book::getGenre() const
{
    return genre;
}

const int& Book::getYear() const
{
    return year;
}

Book* Book::setTitle(const std::string& title)
{
    this->title = title;
    return this;
}

Book* Book::setAuthor(const std::string& author)
{
    this->author = author;
    return this;

}

Book* Book::setGenre(const std::string& genre)
{
    this->genre = genre;
    return this;
}

Book* Book::setYear(const int& year)
{
    this->year = year;
    return this;
}

