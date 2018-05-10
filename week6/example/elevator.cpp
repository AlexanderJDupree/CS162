// File : Elevator.cpp
// Summary: Implementation of Elevator class functions

#include "elevator.h"

// Mutators
Elevator& Elevator::floor(int floor)
{
    m_floor = floor;
    return *this;

}

Elevator& Elevator::maxFloor(int floor)
{
    m_maxFloor = floor;
    return *this;
}

// Inspectors
const int& Elevator::floor() const
{
    return m_floor;
}

const int& Elevator::maxFloor() const
{
    return m_maxFloor;
}

// member functions
void Elevator::goUp(int floors)
{
    this->floor(m_floor + floors);
    return;
}

void Elevator::goDown(int floors)
{
    this->floor(m_floor - floors);
    return;
}

