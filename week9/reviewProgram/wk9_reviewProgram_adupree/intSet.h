/*******************************************************************************
* File: intSet.h
*
* Description: IntSet is an abstract data container that provides methods to add
               modify, and remove ints from a list. 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 06 - 11
*******************************************************************************/

#ifndef INTSET_H
#define INTSET_H

#include <vector>
#include <cstdlib>

class IntSet
{
public:

    IntSet() : _used(0), nums(std::vector<int>(SIZE)) {}

    IntSet(const int& value);

    const size_t& used() { return _used; }

    const int& access(const size_t& position);

    // Modifiers
    bool addElement(const int& value);

    int addElement(const size_t& copies, const int& value);

    bool removeLast();

    bool removeFirst();

    bool findValue(const int& value);

    // Operator overloads
    const int& operator[](const size_t& position);
    bool operator==(const IntSet& intset);
    bool operator!=(const IntSet& intset);
    bool operator<(const IntSet& intset);
    bool operator>(const IntSet& intset);
    
    IntSet& operator=(const IntSet& origin);

private:

    static const int SIZE;

    size_t _used;

    std::vector<int> nums;
};


#endif // INSTSET_H