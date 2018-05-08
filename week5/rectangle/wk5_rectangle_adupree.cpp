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

#include <exception>
#include <iostream>
#include <vector>
#include <limits>
#include <string>

typedef std::string string;

static const int INT_MAX = std::numeric_limits<int>::max();

/////////////////////////////// RECTANGLE CLASS ////////////////////////////////

/******************************************************************************* 
* Class: Rectangle
* 
* Description: Rectangle class provides user methods to access and mutate the 
*              member attributes that belong to a rectangle. Rectangles 
*              attributes are the length and width of the rectangle as well as 
*              the colors of the edges and the surface
*
*******************************************************************************/

class Rectangle
{
public:
    
    // Default constructor
    Rectangle() 
        : m_width(0), m_length(0), m_lineColor(""), m_fillColor("") {}

    // Initializer constructor
    Rectangle(int width, int length, string line, string fill);

    // Default destructor is used
    ~Rectangle() {}

    // Inspectors
    const int& width() const;
    const int& length() const;
    const string& lineColor() const;
    const string& fillColor() const;

    // Mutators
    Rectangle& width(const int& width);
    Rectangle& length(const int& length);
    Rectangle& lineColor(const string& lineColor);
    Rectangle& fillColor(const string& fillColor);

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
const int& Rectangle::width() const
{
    return m_width;
}

const int& Rectangle::length() const
{
    return m_length;
}

const string& Rectangle::lineColor() const
{
    return m_lineColor;
}

const string& Rectangle::fillColor() const
{
    return m_fillColor;
}

// Mutators
Rectangle& Rectangle::width(const int& width)
{
    m_width = width;
    return *this;
}

Rectangle& Rectangle::length(const int& length)
{
    m_length = length;
    return *this;
}

Rectangle& Rectangle::lineColor(const string& lineColor)
{
    m_lineColor = lineColor;
    return *this;
}

Rectangle& Rectangle::fillColor(const string& fillColor)
{
    m_fillColor = fillColor;
    return *this;
}

// Stream operator overload
std::ostream& operator<<(std::ostream& out, const Rectangle& rect)
{
    out << "\n\t\tRECTANGLE\nWidth: " << rect.width() << "\t\tLength: " 
        << rect.length() << "\nLine Color: " << rect.lineColor() 
        << "\tFill Color: " << rect.fillColor() << std::endl;
    return out;
}


//////////////////////////////END RECTANGLE CLASS///////////////////////////////

void printChoices();
// Prints the user interface

void printError(string error);
// Prints error to console

void getAttributes(int* width, int* length, string* line, string* fill);
// Calls templated getInput function to grab and store user values into the 
// correct placement values. 

void resetInputStream();
// Resets failed state, and flushes input buffer

string toLower(const string& word);
// Converts the word into lower case

bool validateDimension(int data, int _min, int _max);
// Returns true of data is within the inclusive min/mix range

bool validateColor(string color, const std::vector<string>& COLORS);
// Returns true if color is contained within the accepted colors vector

template <typename T>
T getInput(string prompt);
// grabs input from the keyboard. Discards all characters after the first space

int main()
{
    const std::vector<string> COLORS = {"black", "blue", "brown", "cyan", 
                                        "green", "magenta", "orange", "pink", 
                                        "red", "violet", "white", "yellow"};
    int width(0);
    int length(0);
    string line("");
    string fill("");
    char input;
    // Placeholder variables for holding input
    
    Rectangle rectangle;


    do 
    {
        printChoices();
        input = getInput<char>("");
        
        switch(input)
        {
            case '1': std::cout << rectangle; break;
            case '2': getAttributes(&width, &length, &line, &fill);

                      if (validateDimension(width, 0, INT_MAX) && 
                          validateDimension(length, 0, INT_MAX) && 
                          validateColor(toLower(line), COLORS) && 
                          validateColor(toLower(fill), COLORS))
                      {
                          rectangle = Rectangle(width, length, line, fill);
                          std::cout << rectangle;
                          break;
                      }

                      printError("\nInvalid input!");
                      break;

            case '3': width = getInput<int>("Enter new width: ");
                      if (validateDimension(width, 0, INT_MAX))
                      {
                          rectangle.width(width);
                          break;
                      }
                      printError("Invalid width, must be greater than 0");
                      break;
                      
            case '4': length = getInput<int>("Enter new length: ");
                      if (validateDimension(length, 0, INT_MAX))
                      {
                          rectangle.length(length);
                          break;
                      }
                      printError("Invalid length, must be greater than 0");
                      break;

            case '5': line = getInput<string>("Enter a color: ");
                      if (validateColor(toLower(line), COLORS))
                      {
                          rectangle.lineColor(line);
                          break;
                      }
                      printError("Invalid, please use a primary color");
                      break;
                      
            case '6': fill = getInput<string>("Enter a color: ");
                      if (validateColor(toLower(fill), COLORS))
                      {
                          rectangle.fillColor(fill);
                      }
                      printError("Invalid, please use a primary color");
        }

    } while (input != 'q' && input != 'Q');
   
    return 0;
}

void printChoices()
{
    std::cout << "\n\t\tRECTANGLE DRIVER\n\n  1.\tPrint Rectangles attributes\n"
              << "  2.\tCreate new rectangle\n  3.\tChange Rectangle width\n"
              << "  4.\tChange Rectangle length\n  5.\tChange Rectangle line "
              << "color\n  6.\tChange Rectangle fill color\nEnter 'q' to quit"
              << std::endl;
    return;
}

void printError(string error)
{
    std::cout << error << std::endl;
    return;
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

string toLower(const string& word)
{
    string lower = "";
    for (unsigned int i = 0; i < word.length(); i++)
    {
        if (word[i] > 'A' && word[i] < 'Z')
        {
            lower += word[i] + 32;
        }
        else
        {
            lower += word[i];
        }
    }
    return lower;
}

bool validateDimension(int data, int _min, int _max)
{
    return data >= _min && data <= _max;
}

bool validateColor(string color, const std::vector<string>& COLORS)
{
    std::vector<string>::const_iterator it;
    for (it = COLORS.begin(); it != COLORS.end(); ++it)
    {
        if (color == *it)
        {
            return true;
        }
    }
    return false;
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

