/*******************************************************************************
* File: wk2_files2_foods_adupree.cpp
*
* Description: Program opens a file, copies its contents into a new file, then 
*              grabs the contents from the copied file and stores it into an 
*              array. This array is then sorted and copied into a new file. 
*              Finally, the user is prompted for a fruit to append to the 
*              original file. The word is appended and the program exits.
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-04-12
*
* Modifications:
*
*   TODO add cout lines to provide feedback for file manipulation.
*******************************************************************************/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <limits>
#include "sort.h"

void openFile(std::ofstream& fout, const char file[]);
// Attempts to open the file for writing, prints error message and exit with 
// status code of 1 upon failure.

void openFile(std::ifstream& fin, const char file[]);
// Overloaded openFile function for input file streams.

void copyFile(std::ifstream& fin, std::ofstream& fout, int& lineCount);
// Copies file from fin into fout

void extractData(std::ifstream& fin, std::string[], int lines, char delim='\n');
// Extracts data from the input file and stores it into an array until the 
// delimeter is found. Will repeat this process for the number of specified 
// lines or until EOF.

void writeArray(std::ofstream& fout, const std::string ara[], int size);
// Loops through ara and copies the contents into a file

void appendFile(std::ofstream& fout, const char file[], const std::string& word);
// Opens file with ios::app flag, append the word , then closes file

std::string getInput(std::string prompt);
// prints prompt then grabs the line of user input. Returns it as a string

char toLower(const char character);
// returns the lowercase equivalent of an alphabetic character.

int main()
{
    //Declarations
    std::ifstream fin;
    std::ofstream fout;
    const char FNAME[] = "goodFoods.txt";
    const char COPY[] = "copyOfGoodFoods.txt";
    const char SORTED[] = "sortedFoods.txt";
    std::string userInput;
    int size = 0;
    
    // IPO
    openFile(fin, FNAME);
    openFile(fout, COPY);

    copyFile(fin, fout, size);
    
    std::string foods[size];
    // create array based on the number of lines in FNAME file. 
    
    fin.close();
    fout.close();

    openFile(fin, COPY);
    openFile(fout, SORTED);

    extractData(fin, foods, size);

    Sort<std::string> sort; 
    // instantiate sorting object
    
    sort.quick(foods, 0, size - 1);
    // quick sort the array. size - 1 is used to give the function the proper
    // right most index.
    
    writeArray(fout, foods, size);

    fin.close();
    fout.close();

    userInput = getInput("\nEnter a fruit to be apended to the file:  "); 

    appendFile(fout, FNAME, userInput);

    return 0;
}

void openFile(std::ofstream& fout, const char file[])
{
    fout.open(file);
    if(fout.fail())
    {
        std::cout << "Failed to open " << file << std::endl;
        exit(1);
    }
    return;
}

void openFile(std::ifstream& fin, const char file[])
{
    fin.open(file);
    if(fin.fail())
    {
        std::cout << "Failed to open " << file << std::endl;
        exit(1);
    }
    return;
}

void copyFile(std::ifstream& fin, std::ofstream& fout, int& lineCount)
{
    std::string data;

    while(std::getline(fin, data))
    {
        fout << data << '\n';
        lineCount++;
    }

   return;
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
            ara[i] += toLower(data);
            // data is converted to lower case for sorting purposes
        }
    }
    return;
}

void writeArray(std::ofstream& fout, const std::string ara[], int size)
{
    for (int i = 0; i < size; i++)
    {
        fout << ara[i] << '\n';
    }
    return;
}

void appendFile(std::ofstream& fout, const char file[], const std::string& word)
{
    // Open file in append mode
    fout.open(file, std::ios::app);
    if (fout.fail())
    {
        std::cout << "Failed to open " << file << std::endl;
        exit(1);
    }

    fout << word << '\n';

    fout.close();

    return;
}

std::string getInput(std::string prompt)
{
    std::string input;
    bool repeat = true;

    do {

        std::cout << prompt;
        std::getline(std::cin, input);
        std::cout << "\nIs \"" << input << "\" the correct input? (Y/N): ";

        if (toLower(std::cin.get()) == 'y') 
        {
            repeat = false;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // ignores characters to end of line.
        
    } while (repeat);

    return input;
}

char toLower(const char character)
{
    char lower;
    if (character >= 'A' && character <= 'Z')
    {
        lower = character + 32;
        // 32 is the offset between 'A' and 'a'
    }
    else 
    {
        return character;
    }
    return lower;
}
