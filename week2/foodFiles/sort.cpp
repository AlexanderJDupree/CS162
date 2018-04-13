#include "sort.h"

template<class T>
void Sort<T>::counting(int ara[], const int SIZE, const int _max, const int _min)
{
    int offset = _min * -1;
    const int RANGE = _max + offset + 1;

    // initialize count array to 0
    int count[RANGE];
    for (int i = 0; i < RANGE; i++)
    {
        count[i] = 0;
    }

    // count values in the original array
    for (int i = 0; i < SIZE; i++)
    {
        count[ara[i] + offset]++;
    }

    // sum the count;
    for (int i = 1; i <= RANGE; i++)
    {
        count[i] += count[i - 1];
    }
    
    // sort the original array into temp array;
    int temp[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
       temp[count[ara[i] + offset] - 1] = ara[i];
       count[ara[i] + offset]--;
    }

    // Copy sorted values over to original array
    for (int i = 0; i < SIZE; i++)
    {
        ara[i] = temp[i];
    }
}

template<class T>
void Sort<T>::bubble(T ara[], int SIZE)
{
    bool isSwap = false;

    // Base case
    if (SIZE == 1) { return; }

    for (int i = 0; i < SIZE - 1; i++)
    {
        if (ara[i] > ara[i+1])
        {
            T temp = ara[i];
            ara[i] = ara[i+1];
            ara[i+1] = temp;
            isSwap = true;
        }
    }
    if (isSwap) { bubble(ara, SIZE - 1); }
    else { return; }
}

template<class T>
void Sort<T>::selection(T ara[], int SIZE)
{
    // Base case
    if (SIZE == 0) { return; }

    int largest = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (ara[i] > ara[largest])
        {
            largest = i;
        }
    }
    T temp = ara[largest];
    ara[largest] = ara[SIZE-1];
    ara[SIZE-1] = temp;
    selection(ara, SIZE - 1);
}

template<class T>
void Sort<T>::insertion(T ara[], int start, int SIZE)
{
    // base case
    if (start >= SIZE ) { return; }

    int i;
    // i is declared in function scope so we can use it later on
    
    for(i = start; i > 0; i--)
    {
        if (ara[start] > ara[i-1]) { break; }
    }

    // Shift every element larger than ara[start] over one position.
    for (int j = start; j > i; j--)
    {
        T temp = ara[j-1];
        ara[j-1] = ara[j];
        ara[j] = temp;
    }
    insertion(ara, start + 1, SIZE);
}

template<class T>
void Sort<T>::quick(T ara[], int left, int right)
{
    // Base case
    if (left >= right) { return; }

    int part = partition(ara, left, right);
    
    quick(ara, left, part - 1);
    // Quick sort left partition
    
    quick(ara, part + 1, right);
    // Quick sort right partition
}

// private 

template<class T>
int Sort<T>::partition(T ara[], int left, int right)
{
    /* Partition takes the right most element as the pivot, places the pivot in
       correct index in the array and arranges elements greater than pivot to 
       the right and less than or equal to pivot to the left */

    const T pivot = ara[right];
    int i = left - 1;
    // index of smaller element

    for (int j = left; j <= right - 1; j++)
    {
        // if current element is smaller or equal to pivot we switch with i
        if (ara[j] <= pivot)
        {
            i++;
            T temp = ara[i];
            ara[i] = ara[j];
            ara[j] = temp;
        }
    }
    // Swap pivot to the correct index in the array
    T temp = ara[i+1];
    ara[i+1] = ara[right];
    ara[right] = temp;

    return (i + 1);
}

