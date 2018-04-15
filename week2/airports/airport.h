/*******************************************************************************
 * File: airport.h
 * Description: 
 * Author: Alexander DuPree
 * Compiler:  GNU GCC 5.4.0
 * Date: 2018-04-14
 *******************************************************************************/

#ifndef AIRPORTS_H
#define AIRPORTS_H

#include <string>

class Airport
{
public:
    
    //Default constructor initializes to null values.
    Airport() : m_ident(""), m_type(""), m_name(""), m_country(""), 
                m_elevation(0) {}

    // Full constructor
    Airport(std::string ident, std::string type, std::string name,
            std::string elev, std::string country);

    // Getters
    std::string identifier();

    std::string type();

    std::string name();

    std::string country();

    int elevation();

private:

    std::string m_ident;
    std::string m_type;
    std::string m_name;
    std::string m_country;

    int m_elevation;

    int convertToInt(const std::string& input);
    // Loops through VALIDATED input string and builds an integer

    bool isNumber(const std::string& input);
    // loops through input string checking for invalid characters.    
};

#endif // AIRPORTS_H
