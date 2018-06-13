/*******************************************************************************
* Class: LinkedList

* Description: LinkedList class is a basic associative container that provides
               constant time insertion and deletion operations. LinkedList 
               provides methods for insertion, deletion, inspection and mutation
               of elements
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 31
*******************************************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

class LinkedList
{
public:
    LinkedList();

    ~LinkedList();

    // Modifiers
    void listHeadInsert(int data);
    void listHeadInsert(int val1, int val2);
    void listReverse();
    void clear();

    // Capacity
    int howMany() const;
    int countCopies(const int& target) const;
    int listSum();
    bool isEmpty() const;
    bool listHeadRemove();

    // Inspectors
    nodePtr getHeadptr();
    int getData(nodePtr node);


private:

    nodePtr head;

    void reverse(nodePtr current, nodePtr previous);

};

#endif // LINKED_LIST_H