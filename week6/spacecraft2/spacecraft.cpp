#include <cassert>
#include "spacecraft.h"


Spacecraft::Spacecraft(std::string type, double speed, double maxSpeed, 
                       double direction, int maxHealth, int health, int capacity, 
                       int weaponDamage, int ammo)
    : type(type), direction(Direction(direction)) 
{
    setCurrentSpeed(speed);
    setMaxSpeed(maxSpeed);
    setMaximumHealth(maxHealth);
    setCurrentHealth(health);
    setAmmoCapacity(capacity);
    setCurrentAmmo(ammo);
    setWeaponDamage(weaponDamage);

}

// Inspectors
const std::string& Spacecraft::getType() const
{
    return type;
}

const double& Spacecraft::getCurrentSpeed() const
{
    return speed;
}

const double& Spacecraft::getMaxSpeed() const
{
    return maxSpeed;
}

const double& Spacecraft::getCurrentDirection() const
{
    return direction.degree();
}
const int& Spacecraft::getMaximumHealth() const
{
    return maximumHealth;
}

const int& Spacecraft::getCurrentHealth() const
{
    return currentHealth;
}
const int& Spacecraft::getAmmoCapacity() const
{
    return ammoCapacity;
}

const int& Spacecraft::getWeaponDamage() const
{
    return weaponDamage;
}

const int& Spacecraft::getCurrentAmmo() const
{
    return currentAmmo;
}



// Mutators
Spacecraft& Spacecraft::setType(const std::string& type)
{
    this->type = type;
    return *this;
}

Spacecraft& Spacecraft::setCurrentSpeed(const double& speed)
{

    assert(speed >= 0);
    this->speed = speed;
    return *this;
}

Spacecraft& Spacecraft::setMaxSpeed(const double& speed)
{
    if (speed < 0)
    {
        throw invalid_speed("Max speed must be greater than 0");
    }
    maxSpeed = speed;
    return *this;
}

Spacecraft& Spacecraft::setCurrentDirection(const double& direction)
{
    this->direction.degree(direction);
    return *this;
}

Spacecraft& Spacecraft::setMaximumHealth(const int& maxHealth)
{
    assert(maxHealth >= 0 && maxHealth <= 100);
    maximumHealth = maxHealth;
    return *this;
}

Spacecraft& Spacecraft::setCurrentHealth(const int& health)
{
    assert(health <= 100);
    if (health < 0)
    {
        currentHealth = 0;
    }
    else
    {
        currentHealth = health;
    }
    return *this;
}

Spacecraft& Spacecraft::setAmmoCapacity(const int& capacity)
{
    assert(capacity >= 0 && capacity <= 50);
    ammoCapacity = capacity;
    return *this;
}

Spacecraft& Spacecraft::setWeaponDamage(const int& damage)
{
    assert(damage >= 1 && damage <= 30);
    weaponDamage = damage;
    return *this;
}

Spacecraft& Spacecraft::setCurrentAmmo(const int& ammo)
{
    assert(ammo >= 0 && ammo <=50);
    currentAmmo = ammo;
    return *this;
}

// Operators
bool Spacecraft::operator==(const Spacecraft& ship) const
{
    return maxSpeed == ship.getMaxSpeed();
}

bool Spacecraft::operator!=(const Spacecraft& ship) const
{
    return !(*this == ship);
}

bool Spacecraft::operator<(const Spacecraft& ship) const
{
    return maxSpeed < ship.getMaxSpeed(); }

bool Spacecraft::operator>(const Spacecraft& ship) const
{
    return !(*this < ship);
}

// Member functions
void Spacecraft::shoot(Spacecraft& ship)
{
    if (currentAmmo >= weaponDamage)
    {
        currentAmmo -= weaponDamage;
        ship.setCurrentHealth(ship.getCurrentHealth() - weaponDamage);
    }
    
    return;
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


