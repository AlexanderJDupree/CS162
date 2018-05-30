// Implementation for Character class

#include "character.h"
#include <cstring>

Character::Character() 
    : GameObject(), name(new char('\0')), superPower(new char('\0')), health(0) {}

Character::Character(const char* label, unsigned int instances, const char* name,
                     const char* superPower, unsigned int health)
    : GameObject(label, instances), health(health)
{
    this->name = new char[sizeof(name) + 1];
    std::strcpy(this->name, name);

    this->superPower = new char[sizeof(superPower) + 1];
    std::strcpy(this->superPower, superPower);
}

// Inspectors
const char* Character::Name() const
{
    return name;
}

const char* Character::SuperPower() const
{
    return superPower;
}

const unsigned int& Character::Health() const
{
    return health;
} 

// Mutators
Character* Character::Name(const char* name)
{
    delete [] this->name;
    this->name = new char[sizeof(name) + 1];
    std::strcpy(this->name, name);
    return this;
}

Character* Character::SuperPower(const char* superPower)
{
    delete [] this->superPower;
    this->superPower = new char[sizeof(superPower) + 1];
    std::strcpy(this->superPower, superPower);
    return this;
}

Character* Character::Health(const unsigned int& health)
{
    this->health = health;
    return this;
}
