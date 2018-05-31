// Implementation for Collectible class

#include "collectible.h"

Collectible::Collectible() : GameObject(), name(""), strength(0) {}

Collectible::Collectible(const std::string& label, unsigned int instances,
                         const std::string& name, int strength)
                : GameObject(label, instances), name(name), strength(strength) {}

// Inspectors
const std::string& Collectible::Name() const
{
    return name;
}

const int& Collectible::Strength() const
{
    return strength;
}

// Mutators
Collectible* Collectible::Name(const std::string& name)
{
    this->name = name;
    return this;
}

Collectible* Collectible::Strength(const int& strength)
{
    this->strength = strength;
    return this;
}