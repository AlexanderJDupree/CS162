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
#include <limits>
#include <string>

typedef std::string string;

struct Volunteer 
{
    int idNo;
    double hours;
    string lName;
    string fName;
    string phone;

    // Default Constructor
    Volunteer();

    // Explicit Constructor
    Volunteer(int id, double hours, string lName, string fName, string phone)
        : idNo(id), hours(hours), lName(lName), fName(fName), phone(phone) {}

    std::ostream& operator << (std::ostream& out, Volunteer& volunteer);

};

void getAttributes(int* id, double* hours, string* lName, string* fName, 
                   string* phone);
// Calls templated getInput function to grab and store user values into the 
// correct placement values. 

void resetInputStream();
// Resets failed state, and flushes input buffer

template <typename T>
T getInput(std::string prompt);
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
    Volunteer volunteer1(1, 40, "DuPree", "Alex", "9712226225");

    // Default instantation, user will populate attributes
    Volunteer volunteer2,
              volunteer3;

    getAttributes(&id, &hours, &lName, &fName, &phone);

    volunteer2 = Volunteer(id, hours, lName, fName, phone);

    getAttributes(&id, &hours, &lName, &fName, &phone);

    volunteer3 = Volunteer(id, hours, lName, fName, phone);
    
    return 0;
}

void getAttributes(int* id, double* hours, string* lName, string* fName, 
                   string* phone)
{
    *id = getInput<int>("\nEnter Volunteer ID: ");
    *lName = getInput<string>("\nEnter volunteers First name: ");
    *fName = getInput<string>("\nEnter volunteers Last name: ");
    *phone = getInput<string>("\nEnter phone number: ");
    *hours = getInput<double>("\nEnter hours worked: ");

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
