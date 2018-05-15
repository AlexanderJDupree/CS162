/*******************************************************************************

* Class: Spacecraft

* Description: Spacecraft class represents a spacecraft object that could be 
               instantiated inside a game. Spacecraft containes relevant member
               data with complementing inspector mutator functions 

* Attributes and Methods:

 const int MAX_CREW - represents the maximum crew ship can hold

 Crew* crew[MAX_CREW] - array holds references to crew objects
 
 std::string m_type - represents the spacecrafts type i.e. freight, combat etc.

 double m_speed - represents current speed

 double m_maxSpeed - represents ships max attainable speed

 Direction m_direction - represents the ships current heading, in degrees

 struct invalid_speed - inherits from std::exception, provides virtual
                        what() method to specify our custom invalid speed 
                        exception
 Spacecraft()
 // Postcondition: sets type to generic, speed to 0, max speed to 100 and 
                   direction to 0

 Spacecraft(std::string type, double speed, double maxSpeed, double direction)
 //Postcondition: corresponding member attributes to the given arguements values

 const std::string& type() const
 // Postcondition: returns a const reference to m_type
 
 const double& speed() const
 // Postcondition: returns a const reference to m_speed
 
 const double& maxSpeed() const
 // Postcondition: returns a const reference to m_maxSpeed
 
 const Direction& direction() const;
 // Postcondition: returns a const refrence to m_direction;
 
 Spacecraft& type(const std::string& type);
 // Postcondition: sets m_type to type, returns *this
 
 Spacecraft& speed(const double& speed)
 // Postcondition: sets m_speed to speed arguments
 
 Spacecraft& maxSpeed(const double& speed)
 // Precondition: speed is a positive real number
 // Postcondition: sets m_max speed to speed arguement, if precondition is not 
 //                met throws invalid_speed custom exception. Returns *this
 
 Spacecraft& direction(const double& direction)
 // Precondition: direction is a double in the range of 0-360
 // Postcondition: uses m_direction mutator to set degree to direction
 
 Comparison operators are overloaded to compare ships MAX speed

 Stream operator is overloaded to print ship in a specific format

* Modifications:

*******************************************************************************/

#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <iostream>
#include <string>
#include "direction.h"

class Spacecraft
{

public:
   
    // Default constructor
    Spacecraft()
        : m_type("Generic"), m_speed(0), m_maxSpeed(100), 
          m_direction(Direction(0)) {}

    // Initializer constructor
    Spacecraft(std::string type, double speed, double maxSpeed, 
               double direction);

    // Deafult destructor is used
    ~Spacecraft() {};

    // Inspectors
    const std::string& getType() const;
    const double& getCurrentSpeed() const;
    const double& getMaxSpeed() const;
    const double& getCurrentDirection() const;

    // Mutators return reference to owning object to allow for inline chaining
    // of setting attributes
    Spacecraft& setType(const std::string& type);
    Spacecraft& setCurrentSpeed(const double& speed);
    Spacecraft& setMaxSpeed(const double& speed);
    Spacecraft& setCurrentDirection(const double& direction);

    // Operators
    bool operator==(const Spacecraft& ship) const;
    bool operator!=(const Spacecraft& ship) const;
    bool operator<(const Spacecraft& ship) const;
    bool operator>(const Spacecraft& ship) const;

private:

    std::string m_type;
    double m_speed;
    double m_maxSpeed;
    Direction m_direction;

 
    // Stream operator overload
    friend std::ostream& operator<<(std::ostream& out, const Spacecraft& ship);


};

struct invalid_speed : public std::exception
{
    const char* error;

    invalid_speed() : error("Invalid value for speed") {}

    invalid_speed(const char* msg) : error(msg) {}

    const char* what() const throw ()
    {
        return error;
    }
    
};

#endif // SPACECRAFT_H
