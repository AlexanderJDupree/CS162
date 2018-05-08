/*******************************************************************************
 * File: wk5_spacecraft_adupree.cpp
 * Description: Program defines and tests Spacecraft class by allowing the user 
 *              to manipulate member functions and variable of the Spacecraft
 * Author: Alexander DuPree
 * Compiler:  GNU GCC 5.4.0
 * Date: 2018-05-07
 *******************************************************************************/
#include <iostream>
#include <exception>
#include <string>

/*******************************************************************************
* Class: Direction
*
* Description: Direction class provides basic data validation for ensuring 
*              variables that represent a direction can only be between 0 - 360
*              degrees. 
*
*              TODO inspector to return a string representing a cardinal 
*              direction
*
*              TODO inspector to return the direction in radians
*******************************************************************************/

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

};

Direction::Direction(double direction) 
{
    if(!validate(direction))
    {
        throw std::invalid_argument("Direction must be 0-360 degrees");
    }

    m_degree = direction;
}

const double& Direction::degree() const
{
    return m_degree;
}

void Direction::degree(double direction)
{
    if (!validate(direction))
    {
        throw std::invalid_argument("Direction must be 0-360 degrees");
    }
    
    m_degree = direction;
    return;
}

bool Direction::validate(double direction)
{
    if (direction < 0 || direction > 360)
    {
        return false;
    }
    return true;
}

/////////////////////////////END DIRECTION CLASS////////////////////////////////

/*******************************************************************************
* Class: Spacecraft 
*
* Description: Spacecraft class represents a spacecraft object that could be 
*              instantiated inside a game. Spacecraft containes relevant member
*              data with complementing inspector mutator functions
*
*******************************************************************************/



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
    const std::string& type() const;
    const double& speed() const;
    const double& maxSpeed() const;
    const Direction& direction() const;

    // Mutators return reference to owning object to allow for inline chaining
    // of setting attributes
    Spacecraft& type(const std::string& type);
    Spacecraft& speed(const double& speed);
    Spacecraft& maxSpeed(const double& speed);
    Spacecraft& direction(const double& direction);

private:

    std::string m_type;
    double m_speed;
    double m_maxSpeed;
    Direction m_direction;
 
    // Stream operator overload
    friend std::ostream& operator<<(std::ostream& out, const Spacecraft& ship);


};

Spacecraft::Spacecraft(std::string type, double speed, double maxSpeed, 
        double direction) 
    : m_type(type), m_speed(speed), m_maxSpeed(maxSpeed), 
      m_direction(Direction(direction)) {}

// Inspectors
const std::string& Spacecraft::type() const
{
    return m_type;
}

const double& Spacecraft::speed() const
{
    return m_speed;
}

const double& Spacecraft::maxSpeed() const
{
    return m_maxSpeed;
}

const Direction& Spacecraft::direction() const
{
    return m_direction;
}

// Mutators
Spacecraft& Spacecraft::type(const std::string& type)
{
    m_type = type;
    return *this;
}

Spacecraft& Spacecraft::speed(const double& speed)
{
    m_speed = speed;
    return *this;
}

Spacecraft& Spacecraft::maxSpeed(const double& speed)
{
    if (speed < 0)
    {
        throw std::invalid_argument("Max speed must be greater than 0");
    }
    m_maxSpeed = speed;
    return *this;
}

Spacecraft& Spacecraft::direction(const double& direction)
{
    m_direction.degree(direction);
    return *this;
}

// Stream operator overload
std::ostream& operator<<(std::ostream& out, const Spacecraft& ship)
{
    out << "\n\t\tSPACECRAFT: " << ship.type() << "\nMax speed: " 
        << ship.maxSpeed() << "\nCurrent speed: " << ship.speed() 
        << "\nDirection: " << ship.direction().degree() << " degrees"
        << std::endl;
    return out;
}

/////////////////////////////////END SPACECRAFT CLASS///////////////////////////

int main()
{
    Spacecraft ship1;
    Spacecraft ship2("Combat", 0, 520, 180);

    std::cout << ship1 << ship2;

    ship1.type("Freight").speed(10).maxSpeed(100).direction(302.123);
    std::cout << ship1;
    return 0;
}
                           

    


