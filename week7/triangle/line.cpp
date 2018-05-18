// Implementation for Line class

#include "line.h"

Line::Line() : m_point1(Point()), m_point2(Point()) {}

Line::Line(const Point& point1, const Point& point2) 
    : m_point1(point1), m_point2(point2) {}

Line::Line(const int& x1, const int& y1, const int& x2, const int& y2)
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
Line* Line::point1(const Point& point)
{
    m_point1 = point;
    return this;
}

Line* Line::point1(const int& x, const int& y)
{
    m_point1.x(x)->y(y);
    return this;
}

Line* Line::point2(const Point& point)
{
    m_point2 = point;
    return this;
}

Line* Line::point2(const int& x, const int& y)
{
    m_point2.x(x)->y(y);
    return this;
}

// Member functions
float Line::slope()
{
    float slope = m_point2.y() - m_point2.y() / 
                  static_cast<float>(m_point2.x() - m_point1.x());
    return slope;
}

// Operator Overloads
bool Line::operator == (const Line& line)
{
    return m_point1 == line.point1() && m_point2 == line.point2();
}