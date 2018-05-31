/*******************************************************************************
* Class: GameObject

* Description: GameObject represents the base/parent class for the charcter and
               collectible classes. GameObject provides methods to inspect, 
               mutate, and construct its member of label and max instances

* Author: Alexander DuPree
 
* Compiler: GNU GCC 5.4.0

* Date: 2018 - 05 - 26
*******************************************************************************/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>

class GameObject
{
public:
  GameObject();

  GameObject(const std::string& label, const unsigned int &maxInstances);

  // Inspectors
  const std::string& Label() const;
  const unsigned int MaxInstance() const;

  // Mutators
  GameObject* Label(const std::string& label);
  GameObject* MaxInstance(const unsigned int& maxInstance);

protected:

    std::string label;
    unsigned int maxInstances;

};


#endif // GAME_OBJECT_H