// Implementation LinkedList class

#include <iostream>
#include "linkedList.h"

LinkedList::LinkedList() : head(NULL), tail(NULL) {}

LinkedList::~LinkedList()
{
    delete head;
    delete tail;
    head = NULL;
    tail = NULL;
}

LinkedList* LinkedList::insert(int data)
{
    nodePtr temp = new Node;
    temp->Data(data)->Next(head);
    head = temp;
    return this;
}

LinkedList* LinkedList::push_back(int data)
{
    nodePtr temp = new Node;

    if(tail == NULL)
    {
        setTail();
    }
    temp->Data(data);
    tail->Next(temp);
    tail = temp;
    return this;
}

size_t LinkedList::size() const
{
    size_t count = 0;
    nodePtr temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->Next();
    }
    return count;
}

bool LinkedList::empty() const
{
    return !(head);
}

void LinkedList::printList()
{
    nodePtr temp = head;
    while (temp != NULL)
    {
        std::cout << temp->Data() << " ";
        temp = temp->Next();
    }
    std::cout << std::endl;
    return;
}

void LinkedList::setTail()
{
    nodePtr temp = head;
    nodePtr prev = temp;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->Next();
    }
    tail = prev;
}
