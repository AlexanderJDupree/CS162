/*******************************************************************************
* File: testObjects.cpp
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 26
*******************************************************************************/

#include "catch.hpp"
#include "gameObject.h"
#include "character.h"

SCENARIO("Test constructors for gameObject class", "[gameObject], [constructors]")
{
    GIVEN("A default gameObject class")
    {
        GameObject* object = new GameObject;

        THEN("Its values are default values")
        {
            REQUIRE(object->MaxInstance() == 0);
            REQUIRE(*object->Label() == '\0');
        }
        delete object;
    }
    GIVEN("An initialized gameObject class")
    {
        const char* LABEL = "Mr. Label";
        GameObject* object = new GameObject(LABEL, 4);

        THEN("Its values are the initialized values")
        {
            REQUIRE(object->MaxInstance() == 4);
            REQUIRE(*object->Label() == *LABEL);
        }
        delete object;
    }
}

SCENARIO("Test mutators for gameObjct class", "[gameObject], [mutators]")
{
    GIVEN("A default gameObject class")
    {
        GameObject* object = new GameObject;
        WHEN("Mutators are used to alter attributes")
        {
            const char* LABEL = "Action";
            object->Label(LABEL)->MaxInstance(5);
            THEN("The attributes are changed")
            {
                REQUIRE(*object->Label() == *LABEL);
                REQUIRE(object->MaxInstance() == 5);
            }
        }
    }
}

SCENARIO("Test character class constructors", "[character], [constructors]")
{
    GIVEN("A default Character class")
    {
        Character character;
        THEN("Its values are defaulte null values")
        {
            REQUIRE(character.Health() == 0);
            REQUIRE(*character.Name() == '\0');
            REQUIRE(*character.SuperPower() == '\0');
        }
    }
    GIVEN("An initialized character object")
    {
        const char* LABEL = "label";
        const char* NAME = "captain underpants";
        const char* SUPERPOWER = "invisibility";
        Character character(LABEL, 4, NAME, SUPERPOWER, 100);

        THEN("Its values match the initialized values")
        {
            REQUIRE(character.Health() == 100);
            REQUIRE(*character.Name() == *NAME);
            REQUIRE(*character.SuperPower() == *SUPERPOWER);
        }
    }
}

SCENARIO("Test mutators for Character class", "[character], [mutators]")
{
    GIVEN("A defulat Character class")
    {
        Character character;
        WHEN("Mutators are used to alter attributes")
        {
            const char* NAME = "captain underpants";
            const char* SUPERPOWER = "invisibility";

            character.Name(NAME)->SuperPower(SUPERPOWER)->Health(100);

            THEN("The attributes are changed")
            {
                REQUIRE(character.Health() == 100);
                REQUIRE(*character.Name() == *NAME);
                REQUIRE(*character.SuperPower() == *SUPERPOWER);
            }
        }
    }
}

SCENARIO("Test collectible class constructors", "[collectible], [constructors]")
{
    GIVEN("A default Collectible class")
    {

    }

}