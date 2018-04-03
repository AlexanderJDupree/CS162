/******************************************************************************
* File: wk1_reviewFuncs_adupree.cpp
* Description: Program performs a variety of operations on 10 random numbers.
               The operation to be performed is chosen by the user.
* Author: Alexander DuPree
* Date: 4/2/2018
* Compiler: GNU CC Compiler 5.4.0
* Modifications:
******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

void fillRandArray(int randAra[]);
// Fills the array with random integers from 0 - 99.
void computeSum(const int ara[], int &sum);
void computeAvg(const int ara[], float &avg);
void selectionSort(int ara[], int araSize, bool ascending = true);
// SelectionSort sorts an array recursively into ascending order by default.
// This can be changed to descending order by an adding the argument 'false' in
// the function call.
void getInput(int &input);
void printArray(const int ara[]);
void printChoices();
void printError();
// Prints error message and calls resetInputStream(). This prevents the user
// from entering a character instead of an integer and putting the program into
// an infinite loop.
void resetInputStream();
template <class T> void printAnswer(T ans, std::string header);
// Use of a template here so the answer parameter can be of different data
// types. This prevents having to create multiple print functions that
// essentially do the same thing.

int findSmallest(int ara[], int araSize);
// Returns the index where the smallest int is located
int findLargest(int ara[], int araSize);
// Returns the index where the largest int is located.

const int SIZE = 10;
// SIZE is declared globally to allow functions access to the Arrays size.

int main()
{
    int randAra[SIZE];
    int userInput,
        least,
        largest,
        sum;
    float average;

    fillRandArray(randAra);
    printArray(randAra);
    printChoices();

    do {
        getInput(userInput);
        switch(userInput)
        {
            case 1: computeSum(randAra, sum);
                    printAnswer<int>(sum, "The sum of the numbers is");
                    break;
            case 2: computeAvg(randAra, average);
                    printAnswer<float>(average, "The array's average is");
                    break;
            case 3: least = findSmallest(randAra, SIZE);
                    printAnswer<int>(randAra[least], "The smallest number is");
                    break;
            case 4: largest = findLargest(randAra, SIZE);
                    printAnswer<int>(randAra[largest],"The largest number is");
                    break;
            case 5: selectionSort(randAra, SIZE);
                    printArray(randAra);
                    break;
            case 6: selectionSort(randAra, SIZE, false);
                    printArray(randAra);
                    break;
            default: printError();
        }
    } while(userInput != 7);

    return 0;
}

void fillRandArray(int randAra[])
{
    int num;
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        num = rand() % 100;
        randAra[i] = num;
    }
    return;
}

void computeSum(const int ara[], int &sum)
{
    sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += ara[i];
    }
    return;
}

void computeAvg(const int ara[], float &avg)
{
    int sum;
    computeSum(ara, sum);
    avg = sum / static_cast<float>(SIZE);
    return;
}

void selectionSort(int ara[], int araSize, bool ascending)
{
    // Base case
    if (araSize == 0) { return; }

    int index = 0;
    if (ascending)
    {
        index = findLargest(ara, araSize);
    }
    else
    {
        index = findSmallest(ara, araSize);
    }

    int temp = ara[index];
    ara[index] = ara[araSize - 1];
    ara[araSize - 1] = temp;
    selectionSort(ara, araSize - 1, ascending);
}

void getInput(int &input)
{
    std::cin >> input;
    return;
}

void printArray(const int ara[])
{
    std::cout << "Array's contents: " << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << ara[i] << " ";
    }
    std::cout << std::endl;
    return;
}

void printChoices()
{
    std::cout << "\nNumber Processing\nWhat would you like to do?" << std::endl;
    std::cout << "  1\tCompute the sum.\n  2\tCompute the average.\n"
              << "  3\tFind the smallest number.\n  4\tFind the largest number.\n"
              << "  5\tSort the numbers, smallest to largest.\n"
              << "  6\tSort the numbers, largest to smallest.\n"
              << "  7\tExit the program." << std::endl;
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

template <class T>
void printAnswer(T ans, std::string header)
{
    std::cout << '\n' << header << ' ' << ans << std::endl;
    return;
}

int findSmallest(int ara[], int araSize)
{
    int smallest = 0;
    for (int i = 1; i < araSize; i++)
    {
        if (ara[i] <= ara[smallest])
        {
            smallest = i;
        }
    }
    return smallest;
}

int findLargest(int ara[], int araSize)
{
    int largest = 0;
    for (int i = 1; i < araSize; i++)
    {
        if (ara[i] >= ara[largest])
        {
            largest = i;
        }
    }
    return largest;
}
