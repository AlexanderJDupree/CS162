#include <cstdlib>
#include <ctime>
#include <set>
#include "RandArray.h"

template<class T>
Random<T>::Random() { return; }

template<class T>
void Random<T>::fillUnique(T ara[], int _max, int _min, int SIZE)
{
    int ceiling;
    if (_min < 0) { ceiling = _max + (_min * -1); }
    else { ceiling = _max; }
 
    unsigned int m_size = SIZE;
    std::set<int> randSet; 
    srand(time(NULL));
    while (randSet.size() < m_size)
    {
        randSet.insert((rand() % ceiling) + _min);
    }
    // Copy the values from the unique set over to the rand array.
    std::set<int>::iterator it = randSet.begin();
    for (unsigned int i = 0; i < m_size; i++)
    {
        ara[i] = (*it);
        it++;
    }
    Random::shuffle(ara, SIZE);
    return;
}

template<class T>
void Random<T>::fillRandom(T ara[], int _max, int _min, int SIZE)
{
    int ceiling;
    if (_min < 0) { ceiling = _max + (_min * -1); }
    else { ceiling = _max; }
    
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        ara[i] = (rand() % ceiling) + _min;
    }
    return;
}

template<class T>
void Random<T>::fillUniqueSorted(T ara[], int _max, int _min, int SIZE)
{
    int ceiling;
    if (_min < 0) { ceiling = _max + (_min * -1); }
    else { ceiling = _max; }
 
    unsigned int m_size = SIZE;
    std::set<int> randSet; 
    srand(time(NULL));
    while (randSet.size() < m_size)
    {
        randSet.insert((rand() % ceiling) + _min);
    }
    // Copy the values from the unique set over to the rand array.
    std::set<int>::iterator it = randSet.begin();
    for (unsigned int i = 0; i < m_size; i++)
    {
        ara[i] = (*it);
        it++;
    }
    return;
}

template<class T>
void Random<T>::fillFloat(float ara[], int _max, int _min, int SIZE)
{
    if (_max == _min) { return; }
    // prevents divide by zero 
    
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        ara[i] = _min + rand() / (static_cast<float> (RAND_MAX/(_max - _min)));
    }
    return;
}

template<class T>
void Random<T>::shuffle(T ara[], int SIZE)
{
    srand (time(NULL));

    // Run from the last element in the array to the first.
    for (int i = SIZE - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
        // Swap last element with a random element.
        std::swap(ara[i], ara[j]);
    }
    return;
}
