/*******************************************************************************
* File: wk2_files1_presidents.cpp
*
* Description: Program allows the user to see the name of the nth president. 
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
* 
* Date: 2018-04-13
*
* Modifications:
*******************************************************************************/

#include <fstream>  // ifstream
#include <iostream> // cout, cin streams
#include <sstream>  // stringstream
#include <cstdlib>  // exit()
#include <string>   // string object
#include <limits>   // numeric_limits<streamsize>::max()

int getInput(int _min, int _max);
// Asks for integer input between the min/max range. Loops until input is valid

void extractData(std::ifstream& fin, std::string[], int lines, char delim='\n');
// Extracts data from the input file and stores it into an array until the 
// delimeter is found. Will repeat this process for the number of specified 
// lines or until EOF.

void displayResult(std::string caption, std::string result);
// prints the caption and the result of the value at the index of the users 
// input

void resetInputStream();
// clears streams failed state and discards all characters until newline

void buildCaption(std::stringstream& caption, int choice);
// adds the correct ordinal indicator for the caption. Assumes choice is an 
// integer between 0 - 100

bool continueLoop(std::string prompt);
// Asks user to repeat program, evaluates input and returns true or false.

int main()
{
    // Declarations
    const int SIZE = 45;
    const char FNAME[] = "presidents.txt";

    int choice;
    std::ifstream fin;
    std::stringstream caption;
    std::string presidents[SIZE];

    fin.open(FNAME);
    if (fin.fail())
    {
        std::cout << "Failed to open " << FNAME << std::endl;
        exit(1);
    }
    
    // Input
    extractData(fin, presidents, SIZE);

    do {

        caption.str("");
        // Resets string stream
        choice = getInput(1, SIZE);

        // Process
        buildCaption(caption, choice);

        // Output
        displayResult(caption.str(), presidents[choice - 1]);
    } while (continueLoop("\nRepeat program? (Y/N):  "));
   
    return 0;
}

int getInput(int _min, int _max)
{
    int num = 0;

    std::cout << "Enter a number between " << _min << " - " << _max << " to see" 
              << " the name of that President:  ";

    // while cin failed or the input is not within range, continue to try again.
    while ((std::cin >> num || std::cin.fail()) && (num < _min || num > _max))
    {
        std::cout << "\nInvalid. Enter a number between " << _min << " - " 
                  << _max << ": ";
        resetInputStream();
    }
    return num;

}

void extractData(std::ifstream& fin, std::string ara[], int lines, char delim)
{
    char data;
    for (int i = 0; i < lines; i++)
    {
        if (fin.eof())
        {
            break;
        }
        while(fin.get(data) && data != delim)
        {
            ara[i] += data;
        }
    }
    return;
}

void displayResult(std::string caption, std::string result)
{
    std::cout << caption << result << std::endl;
    return;
}

void resetInputStream()
{
    // clears failure state
    std::cin.clear();
    // discard bad characters to the limit of a stream OR to the newline 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return;
}

void buildCaption(std::stringstream& caption, int choice)
{
    std::string ordinal;
    switch (choice % 10)
    {
        case 1: ordinal = "st"; break;
        case 2: ordinal = "nd"; break;
        case 3: ordinal = "rd"; break;
        default: ordinal = "th"; break;
    }

    // 11th, 12th, and 13th do not follow the same ordinal rules as the rest of
    // the number line.
    if (choice >= 11 && choice <= 13)
    {
        ordinal = "th";
    }
    caption << "The " << choice << ordinal << " President was: ";
    return;
}

bool continueLoop(std::string prompt)
{
    char input;
    
    std::cout << prompt;

    resetInputStream();
    input = std::cin.get();
    if (input == 'y' || input == 'Y')
    {
        return true;
    }

    return false;
}
