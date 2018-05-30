/*******************************************************************************
* File: character.h
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 26
*******************************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameObject.h"

class Character : public GameObject
{
public:

    Character();

    Character(const char* label, unsigned int instances, const char* name,
              const char* superPower, unsigned int health);

    // Inspectors
    const char* Name() const;
    const char* SuperPower() const;
    const unsigned int& Health() const;

    // Mutators
    Character* Name(const char* name);
    Character* SuperPower(const char* superPower);
    Character* Health(const unsigned int& health);

private:

    char* name;
    char* superPower;
    unsigned int health;

};

#endif // CHARACTER_H