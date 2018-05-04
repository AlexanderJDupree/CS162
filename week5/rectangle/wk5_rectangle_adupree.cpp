/*******************************************************************************
* File: wk5_rectangle_adupree.cpp
*
* Description: Program to test and access the methods and member of the 
*              Rectangle class. User input will be used to populate the
*              Rectangles attributes then the rectangle will be printed to 
*              the console
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
static const int COLOR_SIZE = 12;
static const string COLORS[COLOR_SIZE] = {"black", "blue", "brown", "cyan", 
                                          "green", "magenta", "orange", "pink", 
                                          "red", "violet", "white", "yellow"};
////////////////////////////////VALIDATOR CLASS/////////////////////////////////

// TODO Port this into its own source and header file and flesh it out into a 
// a fully implemented validator class that returns an enumerated list of errors
// on invalid inputs

class Validator
{
public:
    bool integer(int data, int _min, int _max, int SIZE, int* invalidNum=NULL);

    bool String(std::string data, int SIZE, std::string* validStrings=NULL, 
                char* invalidChars=NULL);
private:
    
    template <typename T>
    bool find(T* searchField, T data, int SIZE);
};

bool Validator::integer(int data, int _min, int _max, int SIZE, int* invalidNum)
{
    if (data < _min || data > _max || find(invalidNum, data, SIZE))
    {
        return false;
    }

    return true;
}


template <typename T>
bool Validator::find(T* searchField, T data, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (data == searchField[i])
        {
            return true;
        }
    }
    return false;
}

/////////////////////////////// RECTANGLE CLASS ////////////////////////////////

/* Class: Rectangle
 * 
 * Description: Rectangle class provides user methods to access and mutate the 
 *              member attributes that belong to a rectangle. Rectangles 
 *              attributes are the length and width of the rectangle as well as 
 *              the colors of the edges and the surface
*/

class Rectangle
{
public:
    
    // Default constructor
    Rectangle() 
        : m_width(0), m_length(0), m_lineColor(""), m_fillColor("") {}

    // Initializer constructor
    Rectangle(int width, int length, string line, string fill);

    // Inspectors
    int width();
    int length();
    string lineColor();
    string fillColor();

    // Mutators
    void setWidth(int width);
    void setLength(int length);
    void lineColor(string lineColor);
    void fillColor(string fillColor);

private:
    int m_width;
    int m_length;
    string m_lineColor;
    string m_fillColor;
    
    // Stream operator overload
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);

};

Rectangle::Rectangle(int width, int length, string line, string fill)
    : m_width(width), m_length(length), m_lineColor(line), m_fillColor(fill) {}

// Inspectors
int Rectangle::width()
{
    return m_width;
}

int Rectangle::length()
{
    return m_length;
}

string Rectangle::lineColor()
{
    return m_lineColor;
}

string Rectangle::fillColor()
{
    return m_fillColor;
}

// Mutators
void Rectangle::setWidth(int width)
{
    m_width = width;
    return;
}

void Rectangle::setLength(int length)
{
    m_length = length;
    return;
}

void Rectangle::lineColor(string lineColor)
{
    m_lineColor = lineColor;
    return;
}

void Rectangle::fillColor(string fillColor)
{
    m_fillColor = fillColor;
    return;
}

// Stream operator overload

std::ostream& operator<<(std::ostream& out, const Rectangle& rect)
{
    out << "Width: " << rect.m_width << "\tLength: " << rect.m_length
        << "\nLine Color: " << rect.m_lineColor << "\tFill Color: " 
        << rect.m_fillColor << std::endl;
    return out;
}


//////////////////////////////END RECTANGLE CLASS///////////////////////////////

void getAttributes(int* width, int* length, string* line, string* fill);
// Calls templated getInput function to grab and store user values into the 
// correct placement values. 

void resetInputStream();
// Resets failed state, and flushes input buffer

template <typename T>
T getInput(string prompt);
// grabs input from the keyboard. Discards all characters after the first space

int main()
{
    int width(0);
    int length(0);
    string line("");
    string fill("");
    // Placeholder variables for holding input
    
    Rectangle rectangle;

    getAttributes(&width, &length, &line, &fill);

    
    return 0;
}

void getAttributes(int* width, int* length, string* line, string* fill)
{
    *width = getInput<int>("\nEnter width: ");
    *length = getInput<int>("Enter length: ");
    *line = getInput<string>("Enter line color (Color of the edges): ");
    *fill = getInput<string>("Enter fill color (Color of the surfaces): ");
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
