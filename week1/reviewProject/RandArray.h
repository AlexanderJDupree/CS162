/******************************************************************************
* RandArray class purpose is to generate an array of random unique positive
* integers from 0 - n. It utilizes a set container to achieve this, and then
* Shuffles the array. RandArray utilizes name space Random to further abstract
* Its functions from the user. The user just has to call Random::randomize()
* to generate a set of unique random positive integers.
******************************************************************************/


#ifndef RANDARRAY_H
#define RANDARRAY_H

namespace Random
{
    class RandArray
    {
    public:
        RandArray(const int SIZE);
        // Constructor sets m_size to equal parameter SIZE.

        void unique(int ara[], int _max, int _min);
        // fills array with random unique integers from _min - _max. Utilizes a
        // set to find unique integers then copies the sets values over to the
        // array. Assumes size of ara is the same size of m_size.

        void random(int ara[], int _max, int _min);
        // fills the dynamic array with random integers from _min - _max.

        void shuffle(int ara[]);
        // shuffles a m_randAra to make it unsorted. Used in conjunction with
        // fillUnique. The nature of using a set to fill an array requires
        // that we shuffle it afterwards.

    private:
        unsigned int m_size;
    };

    void fillUnique(int ara[], int _max, int _min, int SIZE);
    // fillUnique is to be called by the user in main, requires an array, the
    // desired highest value, and the size of the array. Randomize will then
    // use the methods in the RandArray class to generate a list of unique,
    // random integers.
    
    void fillRandom(int ara[], int _max, int _min, int SIZE);
    // fillRandom will accept an array and generate random numbers between 
    // _min - _max. numbers may be duplicated
    
    void fillUniqueSorted(int ara[], int _max, int _min, int SIZE);
    // fillUniqueSorted accepts an array and generates random unique numbers in 
    // ascending order.
}

#endif // RANDARRAY_H
