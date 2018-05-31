// Implementation for Character class

#include "character.h"

Character::Character() 
    : GameObject(), name(""), superPower(""), health(0) {}

Character::Character(const std::string& label, unsigned int instances, 
                     const std::string& name, const std::string& superPower, 
                     unsigned int health)
    : GameObject(label, instances), name(name), superPower(superPower), 
      health(health) {}


// Inspectors
const std::string& Character::Name() const
{
    return name;
}

const std::string& Character::SuperPower() const
{
    return superPower;
}

const unsigned int& Character::Health() const
{
    return health;
} 

// Mutators
Character* Character::Name(const std::string& name)
{
    this->name = name;
    return this;
}

Character* Character::SuperPower(const std::string& superPower)
{
    this->superPower = superPower;
    return this;
}

Character* Character::Health(const unsigned int& health)
{
    this->health = health;
    return this;
}
