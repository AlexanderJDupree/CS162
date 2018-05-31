/*******************************************************************************
* Class: Collectible

* Description: Collectible class inherits from GameObject and adds special 
               methods for inspecting, mutating, and constructing the name and
               strength members.

* Author: Alexander DuPree
 
* Compiler: GNU GCC 5.4.0

* Date: 2018 - 05 - 26
*******************************************************************************/

#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include "gameObject.h"

class Collectible : public GameObject
{
public:

    Collectible();

    Collectible(const std::string& label, unsigned int instances, 
                const std::string& name, int strength);

    // Inspectors
    const std::string& Name() const;
    const int& Strength() const;

    // Mutators
    Collectible* Name(const std::string& name);
    Collectible* Strength(const int& strength);

private:

    std::string name;
    int strength;

};

#endif // COLLECTIBLE_H