/*******************************************************************************
* Class: Direction

* Description: Direction class provides basic data validation for ensuring 
              variables that represent a direction can only be between 0 - 360
              degrees. 

* Attributes and Methods:
 
 double m_degree - Represents the current heading in degrees. 

 struct invalid_direction - inherits from std::exception, provides virtual
 what() method to specify our custom invalid direction exception

 Direction() 
 //Postcondition: Sets m_degree to 0

 Direction(double direction) 
 //Postcondition: validates direction argument, sets m_degree to direction. 
                  Throws custom invalid_direction exception if validation fails

 const double& degree() const
 // Postcondition: returns a const reference to m_degree
 
 void degree(double direction)
 // Precondition: direction is a double between 0 - 360
 // Postcondition: Calls validate, sets m_degree to direction
 
 bool validate(double direction)
 // Precondition: direction is a valid double
 // Postcondition: returns true if direction is between 0 - 360, else false

* Modifications:

              TODO inspector to return a string representing a cardinal 
              direction

              TODO inspector to return the direction in radians

*******************************************************************************/

#ifndef DIRECTION_H
#define DIRECTION_H

#include <exception>

class Direction 
{
public:
    
    // Default constructor
    Direction() : m_degree(0) {}

    // Initializer constructor
    Direction(double direction);
        
    // Inspector
    const double& degree() const;

    // Mutator
    void degree(double direction);

    bool validate(double direction);
    
private:

    double m_degree;

    struct invalid_direction : public std::exception
    {
        const char* error;

        invalid_direction() : error("Invalid value for direction") {}

        invalid_direction(const char* msg) : error(msg) {}

        const char* what() const throw ()
        {
            return error;
        }
        
    };
};



#endif // DIRECTION_H

