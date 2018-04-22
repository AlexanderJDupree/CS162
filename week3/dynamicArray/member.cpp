#include "member.h"
#include <iostream> // debug

Member::Member(unsigned int id, std::string fName, std::string lName, 
        std::string email) : m_id(id), m_fName(fName), m_lName(lName), 
                             m_email(email)
{
    if (memberIDs.find(m_id) == memberIDs.end())
    {
        memberIDs[m_id] = this;
    }
    else
    {
        throw invalid_ID();
    }
}

Member::Member(const Member& member) : m_id(member.m_id),
    m_fName(member.m_fName), m_lName(member.m_lName), m_email(member.m_email)
{
    // Change the pointer associated with the member ID to this object
    memberIDs[m_id] = this;
}

// Getters
unsigned int Member::ID() const 
{
    return m_id;
}

std::string Member::name() const 
{
    return m_lName + ", " + m_fName;
}

std::string Member::lname() const 
{
    return m_lName;
}

std::string Member::fname() const 
{
    return m_fName;
}

std::string Member::email() const
{
    return m_email;
}

// Setters
void Member::setName(std::string fName, std::string lName)
{
    m_fName = fName;
    m_lName = lName;
    return;
}

void Member::setEmail(std::string email)
{
    m_email = email;
    return;
}

// Operator overloads
std::ostream& operator << (std::ostream& out, Member& member)
{
    out << "\nID:\t" << member.ID() << "\nName:\t" << member.name() 
              << "\nEmail:\t" << member.email() << std::endl;
    return out;
}

bool Member::operator < (const Member& member) const
{
    return m_id < member.ID();
}

bool Member::operator <= (const Member& member) const
{
    return !(*this > member);
}

bool Member::operator > (const Member& member) const
{
    return member.ID() < m_id;
}

bool Member::operator >= (const Member& member) const
{
    return !(*this < member);
}

bool Member::operator == (const Member& member) const
{
    return m_id == member.ID();
}

bool Member::operator != (const Member& member) const
{
    return !(*this == member);
}

Member& Member::operator = (const Member copy)
{
    m_id = copy.m_id;
    m_fName = copy.m_fName;
    m_lName = copy.m_lName;
    m_email = copy.m_email;

    memberIDs[m_id] = this;

    return *this;
}

// Public interface of user IDs
std::map<unsigned int, Member*> Member::memberIDs = std::map<unsigned int, Member*>();
