/*******************************************************************************
* File: wk5_volunteers_adupree.cpp
*
* Description: Program declares three volunteer structure instances and allows
*              the user to populate the volunteers attributes. It then prints
*              the instances to the screen
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-05-03
*******************************************************************************/

#include <iostream>
#include <cstdio>
#include <limits>
#include <string>

typedef std::string string;

/* Volunteer struct holds basic attributes pertaining to a volunteer object
  A constructor and a basic inspector function was added for quality of life
  purposes.*/
struct Volunteer 
{
    int idNo;
    double hours;
    string lName;
    string fName;
    string phone;

    // Default Constructor
    Volunteer() : idNo(0), hours(0.0), lName(""), fName(""), phone("") {};

    // Explicit Constructor
    Volunteer(int id, double hours, string lName, string fName, string phone)
        : idNo(id), hours(hours), lName(lName), fName(fName), phone(phone) {}
    
    // Concatenates name attributes into a formatted string
    string name() const
    {
        return lName + ' ' + fName;
    }
};

void printVolunteers(const Volunteer& worker1, const Volunteer& worker2, 
                     const Volunteer& worker3);
// Prints the fields for each volunteer using prinf to format the strings in a
// specific way

void printCaption(const string& caption);
// Prints to paramter caption to the screen

void getAttributes(int* id, double* hours, string* lName, string* fName, 
                   string* phone);
// Calls templated getInput function to grab and store user values into the 
// correct placement values. 

void resetInputStream();
// Resets failed state, and flushes input buffer

template <typename T>
T getInput(string prompt);
// grabs input from the keyboard. Discards all characters after the first space

int main()
{   
    // Placeholder declarations for grabbing user input
    int id = 0;
    double hours = 0;
    string lName = "";
    string fName = "";
    string phone = "";

    // Explicit instantation of Volunteer struct
    Volunteer worker1(1, 40.0, "DuPree", "Alex", "9712841416");

    // Default instantation, user will populate attributes
    Volunteer worker2,
              worker3;

    // Input and process
    printCaption("\nEnter data for volunteer 2");
    getAttributes(&id, &hours, &lName, &fName, &phone);

    worker2 = Volunteer(id, hours, lName, fName, phone);

    printCaption("\nEnter data for volunteer 3");
    getAttributes(&id, &hours, &lName, &fName, &phone);

    worker3 = Volunteer(id, hours, lName, fName, phone);

    // Output
    printVolunteers(worker1, worker2, worker3);
    
    return 0;
}

void printVolunteers(const Volunteer& worker1, const Volunteer& worker2, 
                     const Volunteer& worker3)
{
    std::printf("ID\tHOURS\tNAME\t\t     PHONE");

    // Prints the volunteer in the following format:
    // newline - id number - hours with one decimal place - up to 20 characters
    // of the volunteers name - up to 10 characters of the phone number
    std::printf("\n%i\t%.1f\t%-20.20s %.10s\n", worker1.idNo, worker1.hours, 
                                 worker1.name().c_str(), worker1.phone.c_str());

    std::printf("\n%i\t%.1f\t%-20.20s %.10s\n", worker2.idNo, worker2.hours, 
                                 worker2.name().c_str(), worker2.phone.c_str());

    std::printf("\n%i\t%.1f\t%-20.20s %.10s\n", worker3.idNo, worker3.hours, 
                                 worker3.name().c_str(), worker3.phone.c_str());

    return;
}

void printCaption(const string& caption)
{
    std::cout << caption << std::endl;
}

void getAttributes(int* id, double* hours, string* lName, string* fName, 
                   string* phone)
{
    *id = getInput<int>("\nEnter Volunteer ID: ");
    *fName = getInput<string>("Enter volunteers First name: ");
    *lName = getInput<string>("Enter volunteers Last name: ");
    *phone = getInput<string>("Enter phone number: ");
    *hours = getInput<double>("Enter hours worked: ");
    return;
}

void resetInputStream()
{
    // reset failed state
    std::cin.clear();

    // discard characters to the limit of the stream size OR to newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
} 

template <typename T>
T getInput(std::string prompt)
{
    T input;

    std::cout << prompt;
    std::cin >> input;
    resetInputStream();

    return input;
}
