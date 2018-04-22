/*******************************************************************************
* File: member.h
* Description: 
* Author: Alexander Dupree
* Compiler:  GNU GCC 5.4.0
* Date: 2018-04-19
*
* Modifications:
*   TODO Add data validation for id, and email
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
    
    // Default Constructor
    Member() : m_id(0), m_fName(""), m_lName(""), m_email("") {};

    // Initializer Constructor
    Member(unsigned int id, std::string fName, std::string lName, 
           std::string email);

    // Copy Constructor
    Member(const Member& member);
    
    // Getters
    unsigned int ID() const;

    std::string name() const;
    // Uses string concatenation to return Lname, Fname
    
    std::string lname() const;
    std::string fname() const;
    
    std::string email() const;

    // Setters
    void setName(std::string fName, std::string lName);
    void setEmail(std::string email);

    // Operator overloads
    friend std::ostream& operator << (std::ostream& out, Member& member);
    bool operator < (const Member& member) const;
    bool operator <= (const Member& member) const;
    bool operator > (const Member& member) const;
    bool operator >= (const Member& member) const;
    bool operator == (const Member& member) const;
    bool operator != (const Member& member) const;
    Member& operator = (const Member copy);

    // Public interface of user IDs
    static std::map<unsigned int, Member*> memberIDs;

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
