/*******************************************************************************
* File: wk5_spacecraft_adupree.cpp
*
* Description: Program defines and tests Spacecraft class by allowing the user 
*              to manipulate member functions and variable of the Spacecraft
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-05-07
*******************************************************************************/

#include <iostream>
#include <string>
#include <limits>
#include "spacecraft.h"

void pauseConsole();
// Prints "press enter to continue" and uses cin.get() to pause the program

void printError(std::string error);
// Prints error to console

void resetInputStream();
// Resets failed state, and flushes input buffer

void defineSpacecraft(Spacecraft* ship);
// prompts the user to enter values for private member variables

void showSpacecraft(const Spacecraft& ship, std::string caption);
// Prints the ships data to console

void shipCombat(Spacecraft* ship1, Spacecraft* ship2);

const Spacecraft* compareSpeed(const Spacecraft& ship1, const Spacecraft& ship2);
// Compares the maximum speed of 2 Spacecraft objects. Returns a pointer to the
// faster object and NULL if the ships speed are the same

template <typename T>
T getInput(std::string prompt);
// grabs input from the keyboard. Discards all characters after the first space

int main()
{
    Spacecraft ship1;
    Spacecraft ship2("Combat", 0, 520, 180, 100, 100, 50, 30, 50);

    showSpacecraft(ship1, "Ship 1, default data");
    showSpacecraft(ship2, "\nShip 2, explicit constructor");

    pauseConsole();

    try
    {
        defineSpacecraft(&ship1);
    }
    catch (std::exception& err)
    {
        // This block executes when user enters data that is out of bounds
        printError(err.what());
        pauseConsole();
    }

    showSpacecraft(ship1, "\nShip 1, new data");
    showSpacecraft(ship2, "\nShip 2, same data");

    pauseConsole();

    const Spacecraft* fastest = compareSpeed(ship1, ship2);
    if (fastest)
    {
        showSpacecraft(*fastest, "\nShip with fastest max speed");
    }
    else
    {
        printError("\nShips are the same speed");
    }

    shipCombat(&ship2, &ship1);

    return 0;
}

void pauseConsole()
{
    std::cout << "\nPress enter to continue." << std::endl;
    std::cin.get();
    return;
}

void printError(std::string error)
{
    std::cout << error << std::endl;
    return;
}

void resetInputStream()
{
    // reset failed state
    std::cin.clear();

    // discard characters to the limit of the stream size OR to newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
}

void defineSpacecraft(Spacecraft* ship)
{
    std::cout << "\nEnter ship attributes" << std::endl;
    std::string type = getInput<std::string>("Enter ship type: ");
    double maxSpeed = getInput<double>("Enter ships max speed: ");
    double speed = getInput<double>("Enter ships current speed: ");
    double direction = getInput<double>("Enter ships direction(0 - 360): ");
    int maxHealth = getInput<int>("Enter ships maximum health (0 - 100): ");
    int currentHealth = getInput<int>("Enter current health: ");
    int ammoCapacity = getInput<int>("Enter ammo capcaity (0 - 50): ");
    int weaponDamage = getInput<int>("Enter weapons damage (0 - 30): ");
    int currentAmmo = getInput<int>("Enter current ammo reserves: ");

    *ship = Spacecraft(type, speed, maxSpeed, direction, maxHealth, 
                       currentHealth, ammoCapacity, weaponDamage, currentAmmo);

    return;
}

void showSpacecraft(const Spacecraft& ship, std::string caption)
{
    std::cout << caption << std::endl;
    std::cout << ship;
    return;
}

void shipCombat(Spacecraft* ship1, Spacecraft* ship2)
{
    std::cout << '\n'<< ship1->getType() << " ship engages " << ship2->getType()
              << " ship in combat\n" << std::endl;
    pauseConsole();
    ship1->shoot(*ship2);
    if(ship2->getCurrentHealth() <= 0)
    {
        std::cout << ship2->getType() << " ship was destroyed!" << std::endl;
    }
    else
    {
        showSpacecraft(*ship1, "Ship 1 status after combat");
        showSpacecraft(*ship2, "Ship 2 status after combat");
    }
    return;
}

const Spacecraft* compareSpeed(const Spacecraft& ship1, const Spacecraft& ship2)
{
    if (ship1 == ship2)
    {
        return NULL;
    }
    else if (ship1 < ship2)
    {
        return &ship2;
    }
    else
    {
        return &ship1;
    }

}

template <typename T>
T getInput(std::string prompt)
{
    T input;

    std::cout << prompt;
    std::cin >> input;
    resetInputStream();

    return input;
}

