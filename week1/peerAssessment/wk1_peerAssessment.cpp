/*******************************************************************************
* File: wk1_peerAssessment.cpp
*
* Description: Program to demonstrate the use of loops to validate input of 
*              different data types
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-04-11
*
* Modifications:
*
*******************************************************************************/

#include <iostream>
#include <string>

int getInt(std::string errorMsg);
// Prints instructions to console, attempts to catch input into a declared 
// integer variable. Loops until input was successful. 

float getFloat(std::string errorMsg);
// Prints instructions to console, attempts to catch input into a declared float
// variable. Loops until input was successful. 

char getChar(std::string errorMsg);
// Prints instructions to console and catches the first character inserted.

std::string getString(std::string text);
// Prints instructions to console and uses getline to grab all characters until
// the newline character

void echoInput(int num1, float num2, char symbol, std::string text);
// Prints to console each of the data inputs the user entered. 

void resetInputStream();
// clears streams failed state and discards all characters until newline

bool isValidInput(std::string errorMsg);
// Uses the boolean attribute of a streams failed state to determine if input
// was successful. If stream is in a failed state we print out the errorMsg and
// call resetInputStream().

int main() 
{
    // Declarations
    int num1;
    float num2;
    char symbol;
    std::string text;

    // Input 
    num1 = getInt("Invalid input. Enter an integer.");
    num2 = getFloat("Invalid input. Enter a float.");
    symbol = getChar("Invalid input. Enter a character");
    text = getString("Invalid input. Enter a string.");

    // Output
    echoInput(num1, num2, symbol, text);
    
    return 0;
}

int getInt(std::string errorMsg)
{
    int input;
    // Declare variable to catch input

    std::cout << "Please enter an integer. (If you enter a decimal, your input"
              << " will be rounded down.)" << std::endl;
   
    do {
        std::cout << ">  ";
        std::cin >> input;
    } while (!isValidInput(errorMsg));
    // Loop until input is valid
    
    resetInputStream();
    // If the user entered an int followed by arbitrary characters those will be
    // left in the stream. So we have to flush the stream again. 

    return input;
}

float getFloat(std::string errorMsg)
{
    float input;
    // Declare variable to catch input

    std::cout << "Please enter a floating point number." << std::endl;
   
    do {
        std::cout << ">  ";
        std::cin >> input;
    } while (!isValidInput(errorMsg));
    // Loop until input is valid

    return input;
}

char getChar(std::string errorMsg)
{
    char input = '\0';
    // Declare variable to catch input
    
    std::cout << "Please enter a single character. (If you enter more than one,"
              << " only the first character will be kept.)" << std::endl;

    resetInputStream();
    do {
        std::cout << ">  ";
        std::cin.get(input);
        // Grab only the first character
    } while (!isValidInput(errorMsg));
    resetInputStream();
    // cin.get does not grab '\n' so we have to clear the buffer.
    
    return input;
}

std::string getString(std::string errorMsg)
{
    std::string input;
    // Declare variable to catch input
    
    std::cout << "Please enter a string of characters, or just one. Up to you."
              << std::endl;
    
    do {
        std::cout << "> ";
        std::getline(std::cin, input);
    } while (!isValidInput(errorMsg));

    return input;
}

void echoInput(int num1, float num2, char symbol, std::string text)
{
    std::cout << "\nYou entered:\n  Integer:\t" << num1 << "\n  Float:\t" <<num2
              << "\n  Char:\t\t'" << symbol << '\'' << "\nAnd your string:\n"
              << "\t\"" << text << '"' << std::endl;
    return;
}

void resetInputStream()
{
    // clears failure state
    std::cin.clear();
    // discard bad characters 
    std::cin.ignore(100, '\n');
    // An arbitrary number is used here to discard characters in the stream. 
    // We should be using std::numeric_limits<streamsize>::max() to completely 
    // flush the stream. However, that has not been covered in class yet.

    return;
}

bool isValidInput(std::string errorMsg)
{
    // stream failed to catch input and is in a failed state
    if (std::cin.fail()) 
    {
        std::cout << errorMsg << std::endl;
        resetInputStream();
        return false;
    }
    else 
    {
        return true;
    }
}
