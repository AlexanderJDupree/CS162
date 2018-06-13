// Implementation LinkedList class

#include "linkedList.h"

#define NULL 0

LinkedList::LinkedList() : head(NULL) {}

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::listHeadInsert(int data)
{
    nodePtr temp = new Node;
    temp->setData(data)->setLink(head);
    head = temp;
    return;
}

void LinkedList::listHeadInsert(int val1, int val2)
{
    listHeadInsert(val1);
    listHeadInsert(val2);
    return;
}

void LinkedList::listReverse()
{
    nodePtr tail = head;

    while(tail->getLink() != NULL)
    {
        tail = tail->getLink();
    }

    if (tail == head)
    {
        return;
    }

    reverse(head, NULL);

    head = tail;
}

void LinkedList::clear()
{
    while(listHeadRemove());
    return;
}

int LinkedList::howMany() const
{
    int count = 0;
    nodePtr temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->getLink();
    }
    return count;
}

int LinkedList::countCopies(const int& target) const
{
    int count = 0;
    nodePtr temp = head;

    while (temp != NULL)
    {
        if(temp->getData() == target)
        {
            ++count;
        }
        temp = temp->getLink();
    }
    return count;
}

int LinkedList::listSum()
{
    int sum = 0;
    nodePtr temp = head;

    while (temp != NULL)
    {
        sum += temp->getData();
        temp = temp->getLink();
    }
    return sum;
}

bool LinkedList::isEmpty() const
{
    return !(head);
}

bool LinkedList::listHeadRemove()
{
    if (head != NULL)
    {
        nodePtr temp = head;
        head = head->getLink();
        delete temp;
        return true;
    }
    return false;
}

nodePtr LinkedList::getHeadptr()
{
    return head;
}

int getData(nodePtr node)
{
    return node->getData();
}

void LinkedList::reverse(nodePtr current, nodePtr previous)
{
    if (current->getLink() != NULL)
    {
        reverse(current->getLink(), current);
    }
    current->setLink(previous);
}