/******************************************************************************
* Class: Random
*
* Description: Random class provides the user with a variety of methods to fill
* an array with unique or duplicative random elements. Random is a templated 
* class that can "randomize" an array of any primitive data type.
*
* Author: Alexander DuPree
*
* Modifications:
*
* 30-MAR-18 - Refactored Random code base. Got rid of "random" namespace and 
*             moved the functions into the class Random
*
* 06-APR-18 - Templated Random class, updated comments.
******************************************************************************/


#ifndef RANDARRAY_H
#define RANDARRAY_H

template<class T>
class Random
{

public:

    Random();
    // Constructor not implemented

    void fillUnique(T ara[], int _max, int _min, int SIZE);
    // fills array with random unique integers from _min - _max. Utilizes a
    // set to find unique integers then copies the sets values over to the
    // array. 

    void fillRandom(T ara[], int _max, int _min, int SIZE);
    // fillRandom will accept an array and generate random numbers between 
    // _min - _max. numbers may be duplicated

    void fillUniqueSorted(T ara[], int _max, int _min, int SIZE);
    // fillUniqueSorted accepts an array and generates random unique numbers in 
    // ascending order.
    
    void fillFloat(float ara[], int _max, int _min, int SIZE);
    // Takes in a floating point array and generates random numbers floating 
    // point numbers by diving rand() by RAND_MAX.

    void shuffle(T ara[], int SIZE);
    // Loops through the array and grabs the current index and replaces it with
    // random one. 

};

// explicit instantiations
template class Random<int>;
template class Random<short>;
template class Random<long>;
template class Random<float>;
template class Random<double>;
template class Random<char>;


#endif // RANDARRAY_H
