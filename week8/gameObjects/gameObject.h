/*******************************************************************************
* File: gameObject.h
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 26
*******************************************************************************/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject
{
public:
  GameObject();

  GameObject(const char *label, const unsigned int &maxInstances);

  virtual ~GameObject();

  // Inspectors
  const char* Label() const;
  const unsigned int MaxInstance() const;

  // Mutators
  GameObject* Label(const char* label);
  GameObject* MaxInstance(const unsigned int& maxInstance);

protected:

    char* label;
    unsigned int maxInstances;

};


#endif // GAME_OBJECT_H