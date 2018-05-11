/******************************************************************************
* Class: Date

* Description:

* Attributes and Methods:

* Modifications:

******************************************************************************/

#ifndef YEAR_H
#define YEAR_H

#include "dateTime.h"

class Year : public DateTime
{

public:
    Year() : DateTime() {}

    Year(const unsigned short& year) : DateTime(year, 1900, 2100) {}

};

#endif // YEAR_H
