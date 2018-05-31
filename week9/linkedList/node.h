/*******************************************************************************
* File: node.h
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 31
*******************************************************************************/

#ifndef NODE_H
#define NODE_H

class Node
{
public:

    Node();
    ~Node();

    // Inspectors
    const int& Data() const;
    Node* Next();

    // Mutators
    Node* Data(int data);
    Node* Next(Node* node);

private:

    int data;
    Node* next;
};

typedef Node* nodePtr;

#endif // NODE_H