#include "spacecraft.h"

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
        throw invalid_speed("Max speed must be greater than 0");
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
    return m_maxSpeed < ship.maxSpeed(); }

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


