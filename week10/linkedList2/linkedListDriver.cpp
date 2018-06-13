/*******************************************************************************
* File: linkedListDriver.cpp
*
* Description: Program performs basic manipulations of a Linkedlist and 
               prints the results of each 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 31
*******************************************************************************/

#include <iostream>
#include "linkedList.h"

void printList(LinkedList& list);
void printSize(LinkedList& list);
void printSum(LinkedList& list);
void printCopyCount(LinkedList& list, const int& target);
void printIsEmpty(LinkedList& list);
void removeHead(LinkedList& list);

int main()
{
    LinkedList list;

    printIsEmpty(list);

    removeHead(list);

    std::cout << "\nInsert 4, and 7 into linked list" << std::endl;

    list.listHeadInsert(7, 4);

    printList(list);

    printSize(list);

    removeHead(list);

    printList(list);

    printSize(list);

    std::cout << "\nClear list" << std::endl;

    list.clear();

    printSize(list);

    std::cout << "\nInsert 3 into linked list twice" << std::endl;

    list.listHeadInsert(3, 3);

    printList(list);

    printSize(list);

    printSum(list);

    printCopyCount(list, 3);

    std::cout << "\nClearing list" << std::endl;

    list.clear();

    std::cout << "\nInsert 1, 2, and 3 into linked list" << std::endl;

    list.listHeadInsert(3);
    list.listHeadInsert(2);
    list.listHeadInsert(1);

    printList(list);

    std::cout << "\nReverse list order" << std::endl;

    list.listReverse();

    printList(list);
    
    return 0;
}

void printList(LinkedList& list)
{
    nodePtr temp = list.getHeadptr();

    while (temp != NULL)
    {
        std::cout << "Node Address: " << temp << "\nData: " << temp->getData() 
                  << '\n' << std::endl;
        temp = temp->getLink();
    }
    return;
}

void printSize(LinkedList& list)
{
    std::cout << "List size: " << list.howMany() << std::endl; 
    return;
}

void printSum(LinkedList& list)
{
    std::cout << "\nThe sum of all elements in the list is: " << list.listSum() 
              << std::endl;
    return;
}

void printCopyCount(LinkedList& list, const int& target)
{
    std::cout << "\nThe target: " << target << " appears " 
              << list.countCopies(target) << " times in the list." << std::endl;
    return;
}

void printIsEmpty(LinkedList& list)
{
    if (list.isEmpty())
    {
        std::cout << "The list is empty" << std::endl;
    }
    else
    {
        std::cout << "The list is not empty" << std::endl;
    }
    return;
}

void removeHead(LinkedList& list)
{
    if (list.listHeadRemove())
    {
        std::cout << "\nHead node removal successful" << std::endl;
    }
    else
    {
        std::cout << "\nHead node removal failure" << std::endl;
    }
    return;
}