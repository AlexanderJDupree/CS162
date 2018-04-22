/*******************************************************************************
* File: wk3_dynamicArrayProject_adupree.cpp
*
* Description: Prototype Saints Fitness application to allow employees to view,
*              keep, search and modify membership records. Membership records 
*              will be stored into the "saintsMembers.txt" file. Each row in 
*              this file will represent a member, and each column(tab delimited)
*              will represent an attribute. 
*
*              When the program runs, it first will load each member from the 
*              file into memory as a "Member" object. It will then create a 
*              dynamic array based on the number of current members + 20. These
*              20 extra blocks of memory will be used to add new members. Any 
*              open slots in our Member array will be represented by a NULL 
*              pointer. When deleting members we will take the slot where the 
*              member was and point it to NUll. 
*              
*              When adding members we will search for a NULL pointer and add 
*              the new member at that location. If no NULL pointers are found 
*              then we must resize the array. We do this by allocating memory
*              for the size of the old array + 20 and then copy the data over to
*              the new array and deleting the old array. 
*
*              To prevent duplicate entries of members we will use a Map to hold
*              member ID's as keys and pointers to the Member object as the 
*              value. 
*
*              To search for a members email address we will use a dynamic array
*              of Member pointers to iterate through the list until a match has
*              been found and then return the pointer of the member. 
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-04-19
*
* Modifications:
*   TODO Change the createID function calls to hash on the Members phone number. 
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "member.h"
#include "CSV_Reader.h"

void loadData(CSV_Reader& reader, Member members[]);
// Loads data from the input file into the Members array. 

void addMember(Member *& members, std::string fName, std::string lName,
        std::string email, int& size);
// TODO reword this function into seperate functions. A int that returns the 
// index of the free location. AddMember that adds the member into the location
// and a resize call for when the array is full

void deleteMember(std::map<unsigned int, Member*>& IDs,  int memberID);
// Looks in the map for a matching ID. If a matching ID is found then the 
// members values are set to null, signaling an empty block of memory for new 
// members to be added to. Else, prints to console that no ID was found. 

void resize(Member *& members, int& size);
// Allocates a new dynamic array of size + 10. Copies over the contents, deletes
// the old array and then points the member ptr to the new array. A pointer 
// reference is used to ensure the original pointer is being reassigned

int strToInt(const std::string& input);
// loops through validated input string and builds an integer by taking
// advantage of a encoding offset. i.e. the characters '0' - '9' are 48 - 57 on 
// the ascii and utf-8 tables. this means we can take each character from the 
// input string and minus 48 from it and get the represented integer.

unsigned int createID(const std::string& name);
// Utilizes a VERY basic hash function to create a unique 5 digit identification
// number. This hash function is likely to cause collisions, however in the 
// scope of this program it is unlikely.

Member* searchByName(std::map<unsigned int, Member*>& IDs, std::string fName, 
        std::string lName);

int main()
{   
    //Declarations
    std::ofstream fout;
    
    int size = 10;
    // Initial size of 10 allows a buffer of 10 empty member slots in our 
    // dynamic array. This value is CHANGED everytime the array needs to resize
    
    const char delim = ',';
    const char FNAME[] = "saintsMembers.txt";

    CSV_Reader reader(FNAME, delim);

    size += reader.lines();
    // Size is equal to the number of members in the FNAME file + 10

    Member* members = new Member[size];
    // Dynamic Array to hold all member objects with a buffer for adding new
    // members

    try
    {
        loadData(reader, members);
        // Catch invalid id error
    }
    catch (invalid_ID& err)
    {
        std::cout << err.what() << std::endl;
        std::cout << FNAME << " contained invalid IDs" << std::endl;
        exit(1);
    }

    // Interface
    do {

    } while(true);
    



    return 0;
}

void loadData(CSV_Reader& reader, Member members[])
{
    std::string* fields = new std::string[reader.fields()];

    reader.seek(1);
    // Skips the field names line
    
    for (int i = 0; i < reader.lines() - 1; i++)
    {
        reader.readLine(fields);
        members[i] = Member(strToInt(fields[0]), fields[1], fields[2], 
                            fields[3]);
        // throws custom exception invalid_ID, this exception is caught in main
    }
    
    delete [] fields;

    return;
}

void addMember(Member *& members, std::string fName, std::string lName,
        std::string email, int& size)
{
    for (int i = 0; i < size; i++)
    {
        // Find an empty slot in our array
        if (members[i].ID() == 0)
        {
            members[i] = Member(createID(fName + lName), fName, lName, email);
            return;
        }
    }
    // If the loop completes we need to resize the array and try again.
    resize(members, size);

    // Recurisvely call itself until member can be added.
    addMember(members, fName, lName, email, size);
    
    return;
}

void deleteMember(std::map<unsigned int, Member*>& IDs, int memberID)
{
    std::map<unsigned int, Member*>::iterator it;
    it = IDs.find(memberID);
    if (it == IDs.end())
    {
        std::cout << "No matching ID: " << memberID << std::endl;
    }
    else 
    {
        // Member with matching ID is assigned null values.
        *it->second = Member();
    }
    return;
}

void resize(Member *& members, int& size)
{
    int newSize = size + 10;

    Member* resized = new Member[newSize];

    // Copy the contents from old to new array
    for (int i = 0; i < size; i++)
    {
        resized[i] = members[i];
    }
       
    size = newSize;

    // Delete the old array
    delete [] members;

    // Reassign the members pointer
    members = resized;

    return;

}

int strToInt(const std::string& input)
{
    // num will be used to build the integer
    int num = 0;
    int sign = 1;
    unsigned int i = 0;

    // store the sign of the input. then increment index to skip sign.
    if (input[0] == '-') 
    { 
        sign = -1; 
        i++;
    }
    for (; i <= input.length(); i++)
    {
        // drop decimal values
        if (input[i] < 48 || input[i] > 57) 
        { 
            break; 
        }
        
        // build integer from left to right. 
        num = 10 * num + (input[i] - '0');
    }
    return num * sign;
}

unsigned int createID(const std::string& name)
{
    unsigned long hash = 5381;
    // Prime number for hashing, long data type is used to hold the all digits
    // the has may reach
    
    for(unsigned int i = 0; i < name.size(); i++)
    {
        hash = 33 * hash + (unsigned char)name[i];
    }
    
    // Return the last 6 digits of the hash
    return hash % 1000000;
}

Member* searchByName(std::map<unsigned int, Member*>& IDs, std::string fName, 
        std::string lName)
{
    std::map<unsigned int, Member*>::iterator it;
    it = IDs.find(createID(fName + lName));
    if (it == IDs.end())
    {
        std::cout << "Member not found: " << lName << " " << fName << std::endl; 
        return NULL;
    }
    else
    {
        return it->second;
    }
}
