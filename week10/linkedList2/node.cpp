// Implementation for Node class

#include "node.h"

#define NULL 0

Node::Node() : data(0), next(NULL) {}

Node::~Node() {}

// Inspectors
const int& Node::getData() const
{
    return data;
}

Node* Node::getLink() 
{
    return next;
}

// Mutators
Node* Node::setData(int data)
{
    this->data = data;
    return this;
}

Node* Node::setLink(Node* node)
{
    next = node;
    return this;
}