// IntSet implementation

#include "intSet.h"

const int IntSet::SIZE = 20;

IntSet::IntSet(const int& value) 
    : _used(SIZE), nums(std::vector<int>(SIZE, value)) {}

const int& IntSet::access(const size_t& position)
{
    return nums[position];
}

const int& IntSet::operator[](const size_t& position)
{
    return access(position);
}

bool IntSet::addElement(const int& value)
{
    if (_used < SIZE)
    {
        nums[_used++] = value;
        return true;
    }
    return false;
}

int IntSet::addElement(const size_t& copies, const int& value)
{
    unsigned int copied = 0;
    while (copied < copies && addElement(value))
    {
        ++copied;
    }

    return copied;
}

bool IntSet::removeLast()
{
    if (_used == 0)
    {
        return false;
    }

    nums[--_used] = -1;

    return true;
}

bool IntSet::removeFirst()
{
    if (_used == 0)
    {
        return false;
    }

    nums = std::vector<int>(++nums.begin(), nums.end());

    --_used;

    return true;
}

bool IntSet::findValue(const int& value)
{
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        if (*it == value)
        {
            return true;
        }
    }
    return false;
}

bool IntSet::operator==(const IntSet& intset)
{
    return nums == intset.nums;
}

bool IntSet::operator!=(const IntSet& intset)
{
    return !(*this == intset);
}

bool IntSet::operator<(const IntSet& intset)
{
    return nums < intset.nums;
}

bool IntSet::operator>(const IntSet& intset)
{
    return !(*this < intset);
}

IntSet& IntSet::operator=(const IntSet& origin)
{
    _used = origin._used;

    nums = origin.nums;

    return *this;
}