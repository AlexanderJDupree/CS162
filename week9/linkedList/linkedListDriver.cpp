/*******************************************************************************
* File: linkedListDriver.cpp
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 31
*******************************************************************************/

#include <iostream>
#include "linkedList.h"

int main()
{
    LinkedList list;

    list.insert(4);
    list.insert(5);
    
    std::cout << list.size() << std::endl;


    return 0;
}