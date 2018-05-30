// Implementation GameObject abstract base class
#include <cstring>
#include "gameObject.h"

GameObject::GameObject() : label(new char('\0')), maxInstances(0) {}

GameObject::GameObject(const char* label, const unsigned int& maxInstances)
{
    this->label = new char[sizeof(label) + 1];
    std::strcpy(this->label, label);

    this->maxInstances = maxInstances;
}

GameObject::~GameObject()
{
    delete [] label;
}

// Inspectors
const char* GameObject::Label() const
{
    return label;
}

const unsigned int GameObject::MaxInstance() const 
{ 
    return maxInstances; 
}

// Mutators
GameObject* GameObject::Label(const char* label)
{
    delete [] this->label;
    this->label = new char[sizeof(label) + 1];
    std::strcpy(this->label, label);
    return this;
}

GameObject* GameObject::MaxInstance(const unsigned int& maxInstance)
{
    this->maxInstances = maxInstance;
    return this;
}