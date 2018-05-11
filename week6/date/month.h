/******************************************************************************
* Class: Date

* Description:

* Attributes and Methods:

* Modifications:

******************************************************************************/

#ifndef MONTH_H
#define MONTH_H

#include "dateTime.h"

class Month : public DateTime
{

public:
    Month() : DateTime() {}

    Month(const unsigned short& month) : DateTime(month, 1, 12) {};

};

#endif // MONTH_H
