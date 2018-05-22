/*******************************************************************************
* File: library.h

* Description: 

* Author: Alexander DuPree

* Compiler:  GNU GCC 5.4.0

* Date: 2018-05-22
*******************************************************************************/

#ifndef LIBRAY_H
#define LIBRARY_H

#include "book.h"
#include "music.h"
#include "video.h"

class Library
{
public:

    Library();



private:

    const int SIZE = 2;

    Book books[SIZE];
    Music albums[SIZE];
    Video videos[SIZE];
    
}

#endif // LIBRARY_H
