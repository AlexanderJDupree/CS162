/*******************************************************************************
* File: wk1_peerAssessment.cpp
*
* Description: Program to demonstrate the use of loops to validate input of 
*              different data types. All data types, functions and methods have
*              been discussed either in class or in required textbook readings.
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
// We use a do-while loop, even though it is unnecessary, in the unlikely
// scenario keyboard input isn't recognized as a character.

std::string getString(std::string errorMsg);
// Prints instructions to console and uses getline to grab all characters until
// the newline character. do-while loop is implemented here again in the 
// unlikely chance the characters fail to be stored in the input variable.

void echoInput(int num1, float num2, char symbol, std::string text);
// Prints to console each of the data inputs the user entered. 

void resetInputStream();
// clears streams failed state and discards all characters until newline

bool isValidInput(std::string errorMsg);
// Uses the boolean attribute of a streams failed state to determine if input
// was successful. If stream is in a failed state we print out the errorMsg and
// call resetInputStream().

bool isNumber(const std::string& input);
// Loops through the input string checking for invalid characters. Then we loop
// through the invalid characters for exception cases. I.E. a negative float is 
// allowed one '-' and '.' character despite it not being a numerical character.
// If all characters are allowed and or exceptional we return true. 

int converttoint(const std::string& input);
// loops through validated input string and builds an integer by taking
// advantage of a encoding offset. i.e. the characters '0' - '9' are 48 - 57 on 
// the ascii and utf-8 tables. this means we can take each character from the 
// input string and minus 48 from it and get the represented integer.

float convertToFloat(const std::string&input);
// Takes in a VALIDATED input string and follows the converToInt() algorithim 
// except it also keeps track of decimal places after the '.' character and then
// integrates the correct number of decimal digits into the number before 
// returning it.

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
    int num;
    std::string input;
    // string used for data validation 

    std::cout << "Please enter an integer. (If you enter a decimal, your input"
              << " will be rounded down.)" << std::endl;
   
    while (true)
    {
        std::cout << ">  ";
        std::getline(std::cin, input);

        if (isNumber(input)) { break; }
        else 
        {
            std::cout << errorMsg << std::endl;
        }
    }
    // Loop until input is valid then break.
    
    num = convertToInt(input);

    return num;
}

float getFloat(std::string errorMsg)
{
    float num;
    std::string input;
    // string used for data validation 


    std::cout << "\nPlease enter a floating point number." << std::endl;
   
    while (true)
    {
        std::cout << ">  ";
        std::getline(std::cin, input);

        if (isNumber(input)) { break; }
        else 
        {
            std::cout << errorMsg << std::endl;
        }
    }
    // Loop until input is valid then break.
    
    num = convertToFloat(input);

    return num;
}

char getChar(std::string errorMsg)
{
    char input;
    // Declare variable to catch input
    
    std::cout << "\nPlease enter a single character. (If you enter more than "
              << "one, only the first character will be stored.)" << std::endl;

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
    
    std::cout << "\nPlease enter a string of characters, or just one. Up to you."
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

bool isNumber(const std::string& input)
{
    std::string invalidChars = "";

    // collect non-digit characters into invalidChars array
    for (unsigned int i = 0; i < input.length(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            invalidChars += input[i];
        }
    }

    int dots = 0;
    int dashes = 0;

    // review invalid chars for exceptions
    for (unsigned int i = 0; i < invalidChars.length(); i ++)
    {
        switch(invalidChars[i])
        {
            case '.' : dots++; break;
            case '-' : dashes++; break;
            default : return false;
        }
        if (dots > 1 || dashes > 1) { return false; }
    }

    return true;
}

int converttoint(const std::string& input)
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
        if (input[i] == '.') { break; }
        
        // build integer from left to right. 
        num = 10 * num + (input[i] - '0');
    }
    return num * sign;
}

float convertToFloat(const std::string& input)
{
    // num will be used to build the float
    float num = 0;
    int sign = 1;
    unsigned int i = 0;

    // j is used to keep track of indexes after the decimal point
    unsigned int j = 0;

    // store the sign of the input. Then increment index to skip sign.
    if (input[0] == '-')
    {
        sign = -1;
        i++;
    }
    for (; i <= input.length(); i++)
    {
        if (input[i] == '.') { break; }
        
        num = 10 * num + (input[i] - '0');
    }
    // Continue building number without decimal values
    for (j = i + 1; j < input.length(); j++)
    {
       num = 10 * num + (input[j] - '0'); 
    }
    
    // Evaluate number of decimal places
    int decimalDigits = 1;
    for (int k = (j-1) - i; k > 0; k--)
    {
        decimalDigits *= 10;
    }
    // Integrate decimal digits back into number
    num = (num / decimalDigits) * sign;
    
    return num;
}
