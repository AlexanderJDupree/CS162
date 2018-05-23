/*******************************************************************************
* Class: Video 

* Description: Video class provides a basic abstract data structure for storing
               relevant information for a movie

* Attributes and Methods: 
 public:
    - Constructors
    Video();
    // Precondition: 
    // Postcondition: Instantiates Video object with null values

    Video(std::string title, std::string actor, std::string genre, int year);
    // Precondition: 
    // Postcondition: Instantiates Video object with member's values equal to
                      arguments

    - Inspectors
    const std::string& getTitle() const;
    // Precondition: 
    // Postcondition: returns a const reference to title member

    const std::string& getLeadActor() const;
    // Precondition: 
    // Postcondition: returns a const reference to lead actor member

    const std::string& getGenre() const;
    // Precondition: 
    // Postcondition: returns a const reference to genre member

    const int& getYear() const;
    // Precondition: 
    // Postcondition: returns a const reference to year member

    - Mutators
    Video* setTitle(const std::string& title);
    // Precondition:  A valid string reference
    // Postcondition:  Sets title member to the value of title arguement

    Video* setLeadActor(const std::string& leadActor);
    // Precondition: A valid string reference
    // Postcondition: sets leadActor member to the value of leadActor

    Video* setGenre(const std::string& genre);
    // Precondition: a valid string reference
    // Postcondition: sets genre member to the value of genre argument

    Video* setYear(const int& year);
    // Precondition: 
    // Postcondition: sets uyear membber to the value of year argument 

private:

    std::string title - represnets the title of a movie
    std::string leadActor - represents the leading actor/actress of a movie
    std::string genre - represents the genre of a movie
    int year  - represents the date of release for the movie
   

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

