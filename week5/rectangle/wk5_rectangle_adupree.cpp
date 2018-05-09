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

    //Validators
    bool validateDimension(const int& data);
    // Returns true of data is greater than 0, else throws argument error

    bool validateColor(const string& color);
    // Returns true if color is contained within the accepted colors vector
    // else, throws invalid argument error

    static const std::vector<string> COLORS;
    // List of valid colors, shared between objects

    // Stream operator overload
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);

};

Rectangle::Rectangle(int width, int length, string line, string fill)
{
    if (validateDimension(width) && validateDimension(length) && 
        validateColor(line) && validateColor(fill))
    {
        m_width = width;
        m_length = length;
        m_lineColor = line;
        m_fillColor = fill;
    }

}
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
    if (validateDimension(width))
    {
        m_width = width;
    }
    return *this;
}

Rectangle& Rectangle::length(const int& length)
{    
    if (validateDimension(length))
    {
        m_length = length;
    }
    return *this;
}

Rectangle& Rectangle::lineColor(const string& lineColor)
{
    if (validateColor(lineColor))
    {
        m_lineColor = lineColor;
    }
    return *this;
}

Rectangle& Rectangle::fillColor(const string& fillColor)
{
    if (validateColor(fillColor))
    {
        m_fillColor = fillColor;
    }
    return *this;
}

// Validators
bool Rectangle::validateDimension(const int& data)
{
    if (data >= 0)
    {
        return true;
    }
    else
    {
        throw std::invalid_argument("Dimension was less than 0");
    }
}

bool Rectangle::validateColor(const string& color)
{
    std::vector<string>::const_iterator it;
    for (it = COLORS.begin(); it != COLORS.end(); ++it)
    {
        if (color == *it)
        {
            return true;
        }
    }
    throw std::invalid_argument("Invalid color, check accepted colors");
}

std::vector<string> const Rectangle::COLORS = {"black", "blue", "brown", "cyan", 
                                           "green", "magenta", "orange", "pink", 
                                           "red", "violet", "white", "yellow"};

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

void printError(const string& error);
// Prints error to console

void getAttributes(int* width, int* length, string* line, string* fill);
// Calls templated getInput function to grab and store user values into the 
// correct placement values. 

void resetInputStream();
// Resets failed state, and flushes input buffer

string toLower(const string& word);
// Converts the word into lower case

template <typename T>
T getInput(string prompt);
// grabs input from the keyboard. Discards all characters after the first space

int main()
{
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
       
        try
        {
 
        switch(input)
        {
            // Print rectangle
            case '1': std::cout << rectangle; break;

            // Enter all new attributes
            case '2': getAttributes(&width, &length, &line, &fill);
                      rectangle = Rectangle(width, length, toLower(line), 
                                            toLower(fill));
                      std::cout << rectangle;
                      break;

            // Set width
            case '3': width = getInput<int>("Enter new width: ");
                      rectangle.width(width);
                      break;
                                           
            // Set length
            case '4': length = getInput<int>("Enter new length: ");
                      rectangle.length(length);
                      break;

            // Set line color
            case '5': line = getInput<string>("Enter a color: ");
                      rectangle.lineColor(line);
                      break;
                      
            // Set fill color
            case '6': fill = getInput<string>("Enter a color: ");
                      rectangle.fillColor(fill);
        }

        }
        catch(std::invalid_argument& err)
        {
            printError(err.what());
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

void printError(const string& error)
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

template <typename T>
T getInput(std::string prompt)
{
    T input;

    std::cout << prompt;
    std::cin >> input;
    resetInputStream();

    return input;
}

