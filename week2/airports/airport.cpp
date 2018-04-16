#include "airport.h" 
#include <stdexcept>
#include <iostream>

Airport::Airport(std::string ident, std::string type, std::string name, 
                 std::string elev, std::string  country) : m_ident(ident), 
    m_type(type), m_name(name), m_country(country)  
{
    if (isNumber(elev))
    {
        m_elevation = convertToInt(elev);
    }
    else
    {
        throw std::invalid_argument("elevation was not a valid integer");
    }
}
 
std::string Airport::identifier() 
{
    return m_ident;
}

std::string Airport::type() 
{
    return m_type;
}

std::string Airport::name() 
{
    return m_name;
}

std::string Airport::country() 
{
    return m_country;
}

int Airport::elevation() 
{
    return m_elevation;
}

// private
int Airport::convertToInt(const std::string& input)
{
    // num will be used to build the integer
    int num = 0;
    int sign = 1;
    unsigned int i = 0;

    // store the sign of the input. Then increment index to skip sign.
    if (input[0] == '-') 
    { 
        sign = -1; 
        i++;
    }
    for (; i < input.length(); i++)
    {
        // Drop decimal values
        if (input[i] == '.') { break; }
        
        // Build integer from left to right. 
        num = 10 * num + (input[i] - '0');
    }
    return num * sign;
}

bool Airport::isNumber(const std::string& input)
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
    for (unsigned int i = 0; i < invalidChars.length(); i++)
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
