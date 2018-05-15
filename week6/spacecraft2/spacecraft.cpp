#include "spacecraft.h"

Spacecraft::Spacecraft(std::string type, double speed, double maxSpeed, 
        double direction) 
    : m_type(type), m_speed(speed), m_maxSpeed(maxSpeed), 
      m_direction(Direction(direction)) {}

// Inspectors
const std::string& Spacecraft::getType() const
{
    return m_type;
}

const double& Spacecraft::getCurrentSpeed() const
{
    return m_speed;
}

const double& Spacecraft::getMaxSpeed() const
{
    return m_maxSpeed;
}

const double& Spacecraft::getCurrentDirection() const
{
    return m_direction.degree();
}

// Mutators
Spacecraft& Spacecraft::setType(const std::string& type)
{
    m_type = type;
    return *this;
}

Spacecraft& Spacecraft::setCurrentSpeed(const double& speed)
{
    m_speed = speed;
    return *this;
}

Spacecraft& Spacecraft::setMaxSpeed(const double& speed)
{
    if (speed < 0)
    {
        throw invalid_speed("Max speed must be greater than 0");
    }
    m_maxSpeed = speed;
    return *this;
}

Spacecraft& Spacecraft::setCurrentDirection(const double& direction)
{
    m_direction.degree(direction);
    return *this;
}

// Operators
bool Spacecraft::operator==(const Spacecraft& ship) const
{
    return m_maxSpeed == ship.getMaxSpeed();
}

bool Spacecraft::operator!=(const Spacecraft& ship) const
{
    return !(*this == ship);
}

bool Spacecraft::operator<(const Spacecraft& ship) const
{
    return m_maxSpeed < ship.getMaxSpeed(); }

bool Spacecraft::operator>(const Spacecraft& ship) const
{
    return !(*this < ship);
}

// Stream operator overload
std::ostream& operator<<(std::ostream& out, const Spacecraft& ship)
{
    out << "\n\t\tSPACECRAFT: " << ship.getType() << "\nMax speed: " 
        << ship.getMaxSpeed() << "\nCurrent speed: " << ship.getCurrentSpeed() 
        << "\nDirection: " << ship.getCurrentDirection() << " degrees"
        << std::endl;
    return out;
}

/////////////////////////////////END SPACECRAFT CLASS///////////////////////////


