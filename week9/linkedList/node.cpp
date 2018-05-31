// Implementation for Node class

#include "node.h"

#define NULL 0

Node::Node() : data(0), next(NULL) {}

Node::~Node() {}

// Inspectors
const int& Node::Data() const
{
    return data;
}

Node* Node::Next() 
{
    return next;
}

// Mutators
Node* Node::Data(int data)
{
    this->data = data;
    return this;
}

Node* Node::Next(Node* node)
{
    next = node;
    return this;
}