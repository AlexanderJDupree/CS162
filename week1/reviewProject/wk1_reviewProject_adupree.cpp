/*******************************************************************************
* File: reviewProjectDriver.cpp
*
* Description: review project makes use of my Random library to create an array
*              of 20 unique integers from 1-40. It then prints and interface 
*              for the user to interact with that array with limited options.
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-04-05
*
* Modifications:
*******************************************************************************/

#include <iostream>
#include <string>
#include "RandArray.h"

void printChoices();
// Displays interface for user to interact with the array

void printError();
// Displays an error message, used for invalid input.

void resetInputStream();
// resets the input stream and discards invalid characters

void getInput(int& input);
// Grabs modifies referenced int with the value inputted at the keyboard

void printAra(const int ara[], const int SIZE, std::string text);
// Displays text caption and then loops through the array, printing each element

void copyAra(const int ara1[], int ara2[], int SIZE);
// Loops through ara1 and copies it contents into ara2

void bubbleSort(int ara[], int SIZE);
// Recursively bubble sorts ara into ascending order

void printIndex(int ara[], int index, std::string text);
// Prints the element at ara[index]. To get the 'median' value we need to run 
// the array through bubbleSort() first then give it the median index. 

void guessNumber(const int ara[], int SIZE);
// Gives the user a range to guess from and loops until user enters a number 
// exists in the array.

bool checkGuess(const int ara[], int SIZE, int guess);
// Loops through ara, if guess matches any value in ara returns true

int main()
{
    const int SIZE = 20;
    int randAra[SIZE];
    int sortedAra[SIZE];
    int input;
    
    Random<int> randomizer;
    // Instantiate Randomizer object
    
    randomizer.fillUnique(randAra, 40, 1, SIZE);
    // Fills the array with random unique integers

    copyAra(randAra, sortedAra, SIZE);
    bubbleSort(sortedAra, SIZE);

    printAra(randAra, SIZE, "Arrays contents: ");
    printChoices();
    do {
        getInput(input);
        switch(input)
        {
            case 1: printAra(randAra, SIZE, "Original array: "); 
                    break;
            case 2: printAra(sortedAra, SIZE, "Sorted Array: ");
                    break;
            case 3: printIndex(sortedAra, SIZE / 2, "The median value is "); 
                    break;
            case 4: guessNumber(sortedAra, SIZE);
                    printChoices();
                    break;
            case 5: break;
            default: printError();
        }
    } while (input != 5);
    
    
    return 0;
}

void printChoices()
{
    std::cout << "\nArray Processing\nWhat would you like to do?" << std::endl;
    std::cout << "  1.\tPrint the array\n  2.\tSort the array\n"
              << "  3.\tPrint median value\n  4.\tPlay a number game\n"
              << "  5.\tExit the program" << std::endl;
    return;
}

void printError()
{
    std::cout << "\nInvalid input." << std::endl;
    resetInputStream();
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

void printAra(const int ara[], const int SIZE, std::string text)
{
    std::cout << text << std::endl;
    for(int i = 0; i < SIZE; i++)
    {
        std::cout << ara[i] << ' ';
    }
    std::cout << std::endl;
    return; }

void getInput(int& input)
{
    std::cin >> input;
    return;
}

void copyAra(const int ara1[], int ara2[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        ara2[i] = ara1[i];
    }
    return;
}

void bubbleSort(int ara[], int SIZE)
{
    // Base Case
    if (SIZE == 1) { return; }

    for (int i = 0; i < SIZE -1; i++)
    {
        if (ara[i] > ara[i+1])
        {
            int temp = ara[i];
            ara[i] = ara[i+1];
            ara[i+1] = temp;
        }
    }
    bubbleSort(ara, SIZE - 1);
}

void printIndex(int ara[], int index, std::string text)
{
    std::cout << text << ara[index] << std::endl;
    return;
}
            
void guessNumber(const int ara[], int SIZE)
{
    bool status = true;
    int guess = -1;
    // set guess to -1 for data validation purposes.
    
    std::cout << "Pick a number between " << ara[0] << " - " << ara[SIZE-1] 
              << " and I'll tell you if it's in the array." << std::endl;
    do {
        std::cout << "> ";
        getInput(guess);
        if (!std::cin)
        {
            std::cout << "\nInvalid number" << std::endl;
            resetInputStream();
        }
        else if (guess == ara[0] || guess == ara[SIZE-1])
        {
            std::cout << "\nYou can't use that number, I gave it to you.\n";
        }
        else 
        {
            status = checkGuess(ara, SIZE, guess);
            if (status) 
            {
                std::cout << "That number wasn't in the array, try again!.\n";
            }
        }
    } while (status);
    std::cout << "Good job! " << guess << " was in the array!" << std::endl;
    return;
}

bool checkGuess(const int ara[], int SIZE, int guess)
{
    for (int i = 1; i < SIZE - 1; i++)
    {
        if (ara[i] == guess)
        {
            return false;
        }
    }
    return true;
}

