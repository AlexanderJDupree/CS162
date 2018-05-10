/* File:    elevator.h
   Summary: Definition of the elevator class.

Member variables
    int m_maxFloor - highest floor the elevator can reach
    int m_floor - current location of the Elevator

Methods

    Elevator()
    // Precondition : No arguments are provided
    // Postcondition : Elevator object is instantiated, sets values to 0

    Elevator& floor(int floor)
    // Precondition: Elevator instance has been declared
    // Postcondition: m_floor value is set to floor argument
    
    Elevator& maxFloor(int floor)
    // Precondition : Elevator instance has been declared
    // Postcondition: m_maxFloor value is set to floor argument
    
    const int& floor() const
    // Precondition : Elevator instance has been declared
    // Postcondition : returns const reference to m_floor

    const int& maxFloor() const
    // Precondition : Elevator isntance has been declared
    // Postcondition : returns const referenece to m_maxFloor
    
    void goUp(int floors)
    // Precondition : floors is a positive integer
    // Postcondition : calls mutator floor to set floor to desired if possible

    void goDown(int floors)
    // Precondition : floors is a positive integer
    // Postcondition : calls mutator floor to set floor to desired if possible
    
 */

#ifndef ELEVATOR_H
#define ELEVATOR_H

class Elevator
{
public:
    
    // Default constructor
    Elevator() : m_maxFloor(0), m_floor(0) {};

    // Mutators
    Elevator& floor(int floor);
    Elevator& maxFloor(int floor);

    // Inspectors
    const int& floor() const;
    const int& maxFloor() const;

    // member functions
    void goUp(int floors);
    void goDown(int floors);

private:
    int m_maxFloor;
    int m_floor;

};

#endif
