/*******************************************************************************
* File: linkedList.h
*
* Description: 
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

    LinkedList* push_back(int data);
    LinkedList* insert(int data);

    void printList();

private:

    nodePtr head;
    nodePtr tail;

    void setTail();

};

#endif // LINKED_LIST_H