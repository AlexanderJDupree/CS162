/*******************************************************************************
* File: wk5_spacecraft_adupree.cpp
*
* Description: Program defines and tests Spacecraft class by allowing the user 
*              to manipulate member functions and variable of the Spacecraft
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-05-07
*******************************************************************************/

#include <iostream>
#include <exception>
#include <string>
#include <limits>

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
    degree(direction);
    // Uses member mutator degree for setting member variable. 
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

// Operators
bool Spacecraft::operator==(const Spacecraft& ship) const
{
    return m_maxSpeed == ship.maxSpeed();
}

bool Spacecraft::operator!=(const Spacecraft& ship) const
{
    return !(*this == ship);
}

bool Spacecraft::operator<(const Spacecraft& ship) const
{
    return m_maxSpeed < ship.maxSpeed();
}

bool Spacecraft::operator>(const Spacecraft& ship) const
{
    return !(*this < ship);
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

void pauseConsole();
// Prints "press enter to continue" and uses cin.get() to pause the program

void printError(std::string error);
// Prints error to console

void resetInputStream();
// Resets failed state, and flushes input buffer

void defineSpacecraft(Spacecraft* ship);
// prompts the user to enter values for private member variables

void showSpacecraft(const Spacecraft& ship, std::string caption);
// Prints the ships data to console

const Spacecraft* compareSpeed(const Spacecraft& ship1, const Spacecraft& ship2);
// Compares the maximum speed of 2 Spacecraft objects. Returns a pointer to the
// faster object and NULL if the ships speed are the same

template <typename T>
T getInput(std::string prompt);
// grabs input from the keyboard. Discards all characters after the first space

int main()
{
    Spacecraft ship1;
    Spacecraft ship2("Combat", 0, 520, 180);

    showSpacecraft(ship1, "Ship 1, default data");
    showSpacecraft(ship2, "\nShip 2, explicit constructor");

    pauseConsole();

    try
    {
        defineSpacecraft(&ship1);
    }
    catch (std::invalid_argument& err)
    {
        // This block executes when use attempts to enter an invalid heading in 
        // degrees.
        printError(err.what());
        pauseConsole();
    }

    showSpacecraft(ship1, "\nShip 1, new data");
    showSpacecraft(ship2, "\nShip 2, same data");

    pauseConsole();

    const Spacecraft* fastest = compareSpeed(ship1, ship2);
    if (fastest)
    {
        showSpacecraft(*fastest, "\nShip with fastest max speed");
    }
    else
    {
        printError("\nShips are the same speed");
    }

    return 0;
}

void pauseConsole()
{
    std::cout << "\nPress enter to continue." << std::endl;
    std::cin.get();
    return;
}

void printError(std::string error)
{
    std::cout << error << std::endl;
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

void defineSpacecraft(Spacecraft* ship)
{
    std::cout << "\nEnter ship attributes" << std::endl;
    std::string type = getInput<std::string>("Enter ship type: ");
    double speed = getInput<double>("Enter ships current speed: ");
    double maxSpeed = getInput<double>("Eneter ships max speed: ");
    double direction = getInput<double>("Enter ships current heading in degrees: ");

    ship->type(type).speed(speed).maxSpeed(maxSpeed).direction(direction);

    return;
}

void showSpacecraft(const Spacecraft& ship, std::string caption)
{
    std::cout << caption << std::endl;
    std::cout << ship;
    return;
}

const Spacecraft* compareSpeed(const Spacecraft& ship1, const Spacecraft& ship2)
{
    if (ship1 == ship2)
    {
        return NULL;
    }
    else if (ship1 < ship2)
    {
        return &ship2;
    }
    else
    {
        return &ship1;
    }

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

