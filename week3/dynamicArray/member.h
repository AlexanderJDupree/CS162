/*******************************************************************************
* Class Name: Member
*
* Description: Member class provides user with an interface to store modify and
*              view data relevant to each member at Saints Fitness. Each member 
*              shares a static map of member IDs as keys and pointers to the 
*              associated member as the value. This map is used in the 
*              constructor to ensure each member has a UNIQUE ID associated with
*              themself. 
*
* Author: Alexander DuPree
*
* Date: 2018-04-19
*
* Modifications:
*   TODO Add data validation for email
*******************************************************************************/

#ifndef MEMBER_H
#define MEMBER_H

#include <exception>
#include <iostream>
#include <string>
#include <map>

class Member
{

public:

    /* Constructors */
    
    // Default Constructor
    Member() : m_id(0), m_fName(""), m_lName(""), m_email("") {};

    // Initializer Constructor
    Member(unsigned int id, std::string fName, std::string lName, 
           std::string email);

    // Copy Constructor
    Member(const Member& member);
    
    // Default Destructor is used
    
    /* Inspectors */ 
    unsigned int ID() const;

    std::string name() const;
    // Uses string concatenation to return Lname + Fname
    
    std::string lname() const;

    std::string fname() const;
    
    std::string email() const;

    /* Mutators */
    void setName(std::string fName, std::string lName);
    void setEmail(std::string email);

    /* Operator overloads */

    friend std::ostream& operator << (std::ostream& out, Member& member);
    // Overload for console output
    
    Member& operator = (const Member copy);
    // Assignment operator overload


    /* Static Members */
    static std::map<unsigned int, Member*> memberIDs;
    // memberIDs provides a public interface for searching, and modifying 
    // members by entering the userID. The nature of this red-black tree ensures
    // there are no duplicate IDs

private:

    unsigned int m_id;

    std::string m_fName;
    std::string m_lName;
    std::string m_email;

    
};

// invlalid_ID is a custom exception for duplicate ID entries in our program
struct invalid_ID : public std::exception 
{
    const char* error;

    // Default constructor is a duplicate ID error
    invalid_ID() : error("Invalid ID: duplicate ID") {};

    // Constructor with specific message error
    invalid_ID(const char* msg) : error(msg) {};

    const char* what() const throw () 
    {
        return error;
    }
};

#endif // MEMBER_H
