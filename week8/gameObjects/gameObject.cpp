// Implementation GameObject abstract base class
#include <cstring>
#include "gameObject.h"

GameObject::GameObject() : label(""), maxInstances(0) {}

GameObject::GameObject(const std::string& label, const unsigned int& maxInstances)
    : label(label), maxInstances(maxInstances) {}

// Inspectors
const std::string& GameObject::Label() const
{
    return label;
}

const unsigned int GameObject::MaxInstance() const 
{ 
    return maxInstances; 
}

// Mutators
GameObject* GameObject::Label(const std::string& label)
{
    this->label = label;
    return this;
}

GameObject* GameObject::MaxInstance(const unsigned int& maxInstance)
{
    this->maxInstances = maxInstance;
    return this;
}