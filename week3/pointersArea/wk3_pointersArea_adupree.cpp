/*******************************************************************************
* File: wk3_pointersArea_adupree.cpp
*
* Description: 
*   Write a program that computes the area of a rectangle, using only pointer 
*   variables.
*
*   The program should declare pointers for the width, length and area. The user
*   should input the values for width and length. After computing the area, the 
*   program should output the area.
*
*   DO NOT USE ANY "regular" variables.
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-04-19
*
* Modifications:
*******************************************************************************/

#include <iostream>
#include <limits>

/* Rectangle struct helps keep our data in the form of pointer restricted to the 
   scope of the Rectangle object. Rectangle constructor takes the values of x 
   and y assigns them to its base and height pointer. The area is computed by
   multiplying base * height. */
struct Rectangle
{
    int* base;
    int* height;
    int* area;

    // Default Constructor
    Rectangle() : base(NULL), height(NULL), area(NULL) {}

    // Initializer Constructor
    Rectangle(int x, int y) 
    {
        base = new int;
        height = new int;
        area = new int;

        *base = x;
        *height = y;
        *area = (*base) * (*height);
    }

    ~Rectangle()
    {
        delete base;
        delete height;
        delete area;
    }
};

template <typename T>
void getInput(T* input, std::string prompt);
// Modifies the contents of the int pointer. prompt is not a "regular" variable
// as use a string literal to pass in the prompt

void resetInputStream();
// Clears the input streams failed state, flushes the buffer

void printRectangle(Rectangle* rectangle);
// Prints the length, width and area of the rectangle

int main()
{
    // Initialize length and width to a new int with a value of 0
    int* length = new int(0);
    int* width = new int(0);
    char* repeat = new char;

    do {
        getInput(length, "Enter the length (feet): ");
        getInput(width, "Enter the width (feet): ");

        Rectangle* rectangle = new Rectangle(*length, *width);

        printRectangle(rectangle);
        
        getInput(repeat, "\nRepeat the program? (Y/N): ");

    } while (*repeat != 'n' && *repeat != 'q');
    

    return 0;
}

void resetInputStream()
{
    // clears failure state
    std::cin.clear();

    // discard bad characters 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return;
}

template <typename T>
void getInput(T* input, std::string prompt)
{
    std::cout << prompt;
    std::cin >> *input;
    resetInputStream();
    return;
}

void printRectangle(Rectangle* rectangle)
{
    std::cout << "A rectangle with a base of " << *rectangle->base << " and a "
              << "height of " << *rectangle->height << " has an area of " 
              << *rectangle->area << " feet." << std::endl;
}
