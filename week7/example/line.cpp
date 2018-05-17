// Implementation for Line class

#include "line.h"

Line::Line() : m_point1(Point()), m_point2(Point()) {}

Line::Line(Point point1, Point point2) : m_point1(point1), m_point2(point2) {}

Line::Line(int x1, int y1, int x2, int y2)
    : m_point1(Point(x1, y1)), m_point2(Point(x2, y2)) {}

//Accessors
const Point& Line::point1() const
{
    return m_point1;
}

const Point& Line::point2() const
{
    return m_point2;
}


// Mutators
Line* Line::point1(Point point)
{
    m_point1 = point;
    return this;
}

Line* Line::point1(int x, int y)
{
    m_point1.x(x)->y(y);
    return this;
}

Line* Line::point2(Point point)
{
    m_point2 = point;
    return this;
}

Line* Line::point2(int x, int y)
{
    m_point2.x(x)->y(y);
    return this;
}

// Member functions
float Line::slope()
{
    float slope = m_point2.y() - m_point1.y() /
                 (float)(m_point2.x() - m_point1.x());
    return slope;
}