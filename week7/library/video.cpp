// Implementation for Video class

#include "video.h"

Video::Video() : title(""), leadActor(""), genre(""), year(0) {}

Video::Video(std::string title, std::string actor, std::string genre, int year)
    : title(title), leadActor(actor), genre(genre), year(year) {}

const std::string& Video::getTitle() const {
    return title;
}

const std::string& Video::getLeadActor() const
{
    return leadActor;
}

const std::string& Video::getGenre() const
{
    return genre;
}

const int& Video::getYear() const
{
    return year;
}

Video* Video::setTitle(const std::string& title)
{
    this->title = title;
    return this;
}

Video* Video::setLeadActor(const std::string& leadActor)
{
    this->leadActor = leadActor;
    return this;
}

Video* Video::setGenre(const std::string& genre)
{
    this->genre = genre;
    return this;
}

Video* Video::setYear(const int& year)
{
    this->year = year;
    return this;
}



