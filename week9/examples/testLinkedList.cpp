/*******************************************************************************
* File: testLinkedList.cpp
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

int main(int argc, char const *argv[])
{
    LinkedList list;

    list.insert(7);

    list.printList();

    list.insert(5);

    list.printList();

    list.push_back(6);

    list.printList();
    
    
    return 0;
}
