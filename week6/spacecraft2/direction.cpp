/*******************************************************************************
*******************************************************************************/

#include "direction.h"

Direction::Direction(double direction) 
{
    degree(direction);
    // Uses member mutator degree for setting member variable. 
}

const double& Direction::degree() const
{
    return m_degree;
}

void Direction::degree(double direction)
{
    if (!validate(direction))
    {
        throw invalid_direction("Direction must be 0-360 degrees");
    }
    
    m_degree = direction;
    return;
}

bool Direction::validate(double direction)
{
    if (direction < 0 || direction > 360)
    {
        return false;
    }
    return true;
}

