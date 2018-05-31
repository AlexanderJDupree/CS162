/*******************************************************************************
* Class: Character 

* Description: Character class inherits from GameObject and adds special 
               methods for inspecting, mutating, and constructing the name, 
               health, and SuperPower members.

* Author: Alexander DuPree
 
* Compiler: GNU GCC 5.4.0

* Date: 2018 - 05 - 26
*******************************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameObject.h"

class Character : public GameObject
{
public:

    Character();

    Character(const std::string& label, unsigned int instances, 
              const std::string& name, const std::string& superPower, 
              unsigned int health);

    // Inspectors
    const std::string& Name() const;
    const std::string& SuperPower() const;
    const unsigned int& Health() const;

    // Mutators
    Character* Name(const std::string& name);
    Character* SuperPower(const std::string& superPower);
    Character* Health(const unsigned int& health);

private:

    std::string name;
    std::string superPower;
    unsigned int health;

};

#endif // CHARACTER_H