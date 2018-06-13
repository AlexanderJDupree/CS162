/*******************************************************************************
* Class: Node
*
* Description: Node class provides the atomic structure for our LinkedList 
               container. Each Node contains an integer data and a node pointer
               next. Node class provides methods for inspecting and mutating 
               each member.
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
    const int& getData() const;
    Node* getLink();

    // Mutators
    Node* setData(int data);
    Node* setLink(Node* node);

private:

    int data;
    Node* next;
};

typedef Node* nodePtr;

#endif // NODE_H