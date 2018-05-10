/*******************************************************************************
 * File: testelevator.cpp
 * Description: Program to test the elevator class
 * Author: Alexander DuPree
 * Compiler:  GNU GCC 5.4.0
 * Date: 2018-05-10
 *******************************************************************************/

#include <iostream>
#include "elevator.h"

#define LOG(X) std::cout << X << std::endl;

int main()
{
    Elevator elevator;

    std::cout << "Elevator instantiated\nFloor: " << elevator.floor()
              << "\nMax Floor: " << elevator.maxFloor() << std::endl;

    elevator.floor(2).maxFloor(10);

    std::cout << "\nElevator new values\nFloor: " << elevator.floor()
              << "\nMax Floor: " << elevator.maxFloor() << std::endl;

    elevator.goUp(7);
    std::cout << "Elevator went up 7 floors\nFloor: " << elevator.floor()
              << std::endl;

    elevator.goDown(4);
    std::cout << "Elevator went down 4 floors\nFloor: " << elevator.floor();
    std::cout << std::endl;


    return 0;
}
