/*******************************************************************************
* File: gameObjectDriver.cpp
*
* Description: Driver program tests the constructors, inspectors, and mutators 
               for the GameObject and child classes
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 30
*******************************************************************************/

#include <iostream>
#include <limits>
#include <string>
#include "gameObject.h"
#include "character.h"
#include "collectible.h"

#define LOG(x) std::cout << '\n' << x << std::endl;

void printInterface();
// Prints testing interface options

void resetInputStream();
// resets streaam failed state, flushes input buffer

void testBaseConstructors();
// Runs the constructors test for the GameObject class

void testBaseMutators();
// Runs the Mutators test for the GameObject class

void testCharacterConstructors();
// Runs the constructors test for the Character class

void testCharacterMutators();
// Runs the Mutators test for the Character class

void testCollectibleConstructors();
// Runs the constructors test for the Collectible class

void testCollectibleMutators();
// Runts the Mutators test for the Collectible class

template <typename T>
void assert(const T& value, const T& otherValue, const std::string& caption);

template <typename T> 
T getInput(const char* prompt);
// grabs input from the keyboard. Discards all characters after the first spcae

int main()
{
    char input = '\0';


    do {
        printInterface();
        input = getInput<char>(">  ");

        
        switch (input)
        {
            case '1' : testBaseConstructors(); break;
            case '2' : testBaseMutators(); break;
            case '3' : testCharacterConstructors(); break;
            case '4' : testCharacterMutators(); break;
            case '5' : testCollectibleConstructors(); break;
            case '6' : testCollectibleMutators(); break;
            default : LOG("Invalid input");
        }
    } while(input != 'q');

    return 0;
}

void printInterface()
{
    std::cout << "\n\t\tGAME OBJECTS TESTS\n" << std::endl;
    std::cout << "GameObject Base class:\n  1.\tTest Constructors\n  2.\tTest "
              << "Mutators\n" << std::endl;
    std::cout << "Character class:\n  3.\tTest Constructors\n  4.\tTest "
              << "Mutators\n" << std::endl;
    std::cout << "Collectible class:\n  5.\tTest Constructors\n  6.\tTest "
              << "Mutators\n" << std::endl;
    std::cout << "(Inspectors are implicitly tested)" << std::endl;
    std::cout << "Press 'q' to quit" << std::endl;
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

void testBaseConstructors() 
{
    LOG("Testing Default Constructor")

    GameObject gameobject;

    assert<std::string>(gameobject.Label(), "", "\nDefault Label Values");
    assert<int>(gameobject.MaxInstance(), 0, "\nDefault Instance Values");

    LOG("------------------------------------------------------------");

    LOG("Testing Explicit Constructors");
    std::string label = getInput<std::string>("Enter Label:  ");
    unsigned int instances = getInput<unsigned int>("Enter max Instances: ");

    GameObject object(label, instances);

    assert<std::string>(object.Label(), label, "\nExplicit Label Values");
    assert<int>(object.MaxInstance(), instances, "\nExplicit Instance Values");

    LOG("------------------------------------------------------------");

    return;

}

void testBaseMutators()
{
    LOG("Testing Mutators")

    GameObject object;

    std::string label = getInput<std::string>("Enter Label:  ");
    unsigned int instances = getInput<unsigned int>("Enter max Instances: ");

    object.Label(label)->MaxInstance(instances);

    assert<std::string>(object.Label(), label, "\nExplicit Label Values");
    assert<int>(object.MaxInstance(), instances, "\nExplicit Instance Values");

    LOG("------------------------------------------------------------");

}

void testCharacterConstructors()
{
    LOG("Testing Default Constructor")

    Character character;

    assert<std::string>(character.Label(), "", "\nDefault Label Values");
    assert<int>(character.MaxInstance(), 0, "\nDefault Instance Values");
    assert<int>(character.Health(), 0, "\nDefault health values");
    assert<std::string>(character.Name(), "", "\nDefault Name");
    assert<std::string>(character.SuperPower(), "", "\nDefault Super Power");

    LOG("------------------------------------------------------------");

    LOG("Testing Explicit Constructors");
    std::string label = getInput<std::string>("Enter Label:  ");
    unsigned int instances = getInput<unsigned int>("Enter max Instances: ");
    std::string name = getInput<std::string>("Enter name: ");
    std::string superPower = getInput<std::string>("Enter superPower: ");
    unsigned int health = getInput<unsigned int>("Enter Health: ");

    character =  Character(label, instances, name, superPower, health);

    assert<std::string>(character.Label(), label, "\nExplicit Label Values");
    assert<int>(character.MaxInstance(), instances, "\nExplicit Instance Values");
    assert<int>(character.Health(), health, "\nExplicit health values");
    assert<std::string>(character.Name(), name, "\nExplicit Name");
    assert<std::string>(character.SuperPower(), superPower, "\nExplicit Super Power");

    LOG("------------------------------------------------------------");

    return;
}

void testCharacterMutators()
{
    LOG("Testing Mutators")

    Character character;

    std::string label = getInput<std::string>("Enter Label:  ");
    unsigned int instances = getInput<unsigned int>("Enter max Instances: ");
    std::string name = getInput<std::string>("Enter name: ");
    std::string superPower = getInput<std::string>("Enter superPower: ");
    unsigned int health = getInput<unsigned int>("Enter Health: ");

    character.Health(health)->Name(name)->SuperPower(superPower)->Label(label)->MaxInstance(instances);

    assert<std::string>(character.Label(), label, "\nExplicit Label Values");
    assert<int>(character.MaxInstance(), instances, "\nExplicit Instance Values");
    assert<int>(character.Health(), health, "\nExplicit health values");
    assert<std::string>(character.Name(), name, "\nExplicit Name");
    assert<std::string>(character.SuperPower(), superPower, "\nExplicit Super Power");

    LOG("------------------------------------------------------------");

    return;
}

void testCollectibleConstructors()
{
    LOG("Testing Default Constructor")

    Collectible collectible;

    assert<std::string>(collectible.Label(), "", "\nDefault Label Values");
    assert<int>(collectible.MaxInstance(), 0, "\nDefault Instance Values");
    assert<std::string>(collectible.Name(), "", "\nDefault Name");
    assert<int>(collectible.Strength(), 0, "\nDefault Strength value");

    LOG("------------------------------------------------------------");

    LOG("Testing Explicit Constructors");
    std::string label = getInput<std::string>("Enter Label:  ");
    unsigned int instances = getInput<unsigned int>("Enter max Instances: ");
    std::string name = getInput<std::string>("Enter Name: ");
    int strength = getInput<int>("Enter strength Value:  ");

    collectible = Collectible(label, instances, name, strength);

    assert<std::string>(collectible.Label(), label, "\nExplicit Label Values");
    assert<int>(collectible.MaxInstance(), instances, "\nExplicit Instance Values");
    assert<std::string>(collectible.Name(), name, "\nExplicit Name");
    assert<int>(collectible.Strength(), strength, "\nExplicit Strength Value");

    LOG("------------------------------------------------------------");

    return;
}

void testCollectibleMutators()
{
    LOG("Testing Mutators")

    Collectible collectible;

    std::string label = getInput<std::string>("Enter Label:  ");
    unsigned int instances = getInput<unsigned int>("Enter max Instances: ");
    std::string name = getInput<std::string>("Enter Name: ");
    int strength = getInput<int>("Enter strength Value:  ");

    collectible.Name(name)->Strength(strength)->Label(label)->MaxInstance(instances);

    assert<std::string>(collectible.Label(), label, "\nExplicit Label Values");
    assert<int>(collectible.MaxInstance(), instances, "\nExplicit Instance Values");
    assert<std::string>(collectible.Name(), name, "\nExplicit Name");
    assert<int>(collectible.Strength(), strength, "\nExplicit Strength Value");

    LOG("------------------------------------------------------------");

    return;
}

template <typename T>
void assert( const T& value, const T& otherValue, const std::string& caption)
{
    std::cout << caption << std::endl;
    std::cout << value << " == " << otherValue;
    if (value == otherValue)
    {
        std::cout << ": TRUE\nAssertion passed!" << std::endl;
    }
    else
    {
        std::cout << ": FALSE\nAssertion failed!" << std::endl;
        std::cin.get();
    }
    return;
}

template <typename T> 
T getInput(const char* prompt)
{
    T input;

    std::cout << prompt;
    std::cin >> input;
    resetInputStream();

    return input;
}

