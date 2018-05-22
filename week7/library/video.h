/*******************************************************************************
* File: video.h

* Description: 

* Attributes and Methods: 
    

* Author: Alexander DuPree

* Date: 2018 - 05 - 21
*******************************************************************************/

#ifndef VIDEO_H
#define VIDEO_H

#include <string>

class Video
{
public:
    Video();

    Video(std::string title, std::string actor, std::string genre, int year);

    const std::string& getTitle() const;
    const std::string& getLeadActor() const;
    const std::string& getGenre() const;
    const int& getYear() const;

    Video* setTitle(const std::string& title);
    Video* setLeadActor(const std::string& leadActor);
    Video* setGenre(const std::string& genre);
    Video* setYear(const int& year);

private:

    std::string title;
    std::string leadActor;
    std::string genre;

    int year;

};

#endif // VIDEO_H
