/******************************************************************************
* Class: Sort
*
* Description: Sort class provides the user with a variety of methods to sort an 
* array of a primitive data type. Current sort methods are bubble, selection, 
* insertion, and quick sort. 
* 
* Modifications:
*
* 07-APR-18 - Refactored Sort class. Got rid of "sort" namespace and moved the 
*             custom sort into the sort class as a private member.
*
* 07-APR-18 - Templated all sort methods except custom sort
*
* 08-APR-18 - Implemented recursive quick sort function. quick sort relies on 
*             the partition function to perform its sort. partition is a private
*             member function
*
* TODO Add heap, merge, and other sort methods
* TODO Modify custom sort to be implemented as a proper counter sort
* TODO Figure out a way to accept custom objects and sort them if their 
*      comparison operators are overloaded
******************************************************************************/

#ifndef SORT_H
#define SORT_H

#include <string>

template<class T>
class Sort
{

public:

    void counting(int ara[], const int SIZE, const int _max, const int _min);
    // Best Case: 
    // Worst Case: 
    // Average: 
    // Space: 
    
    void bubble(T ara[], int SIZE);
    // Best Case: O(n)
    // Worst Case: O(n^2)
    // Average: O(n^2)
    // Space: O(1)

    void selection(T ara[], int SIZE);
    // Best Case: O(n^2) comparisons, O(n) swaps
    // Worst Case: O(n^2) comparisons, O(n) swaps
    // Average: O(n^2) comparisons, O(n) swaps
    // Space: O(1) 

    void insertion(T ara[], int start, int SIZE);
    // Best Case: O(n)
    // Worst Case: O(n^2)
    // Average: O(n^2)
    // Space: O(1)

    void quick(T ara[], int left, int right);
    // Best Case: O(n log n)
    // Worst Case: O(n^2)
    // Average: O(n log n)
    // Space: log n best, n avg

private:

    int partition(T ara[], int left, int right);
    // Chooses right element as pivot value and partitions all values left or 
    // right of the pivot based on less than or greater than comparisons.

};

// explicit instantiations
template class Sort<int>;
template class Sort<short>;
template class Sort<long>;
template class Sort<float>;
template class Sort<double>;
template class Sort<char>;
template class Sort<std::string>;

#endif // SORT_H
