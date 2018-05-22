// Implementation for Line class

#include "line.h"

// STATIC CONSTANT MEMBER
const double Line::UNDEFINED = std::numeric_limits<double>::max();

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
    m_point1.setX(x)->setY(y);
    return this;
}

Line* Line::point2(const Point& point)
{
    m_point2 = point;
    return this;
}

Line* Line::point2(const int& x, const int& y)
{
    m_point2.setX(x)->setY(y);
    return this;
}

// Member functions
double Line::slope() const
{
    float denominator = m_point2.getX() - m_point1.getX();
    if (denominator == 0)
    {
        return UNDEFINED;
    }

    float numerator = m_point2.getY() - m_point1.getY();

    double slope = numerator / denominator;

    return slope;
}

double Line::length() const
{
    // TODO add overflow handling
    double length = sqrt((pow(m_point2.getX() - m_point1.getX(), 2) 
                         + pow(m_point2.getY() - m_point1.getY(), 2)));
    return length;
}

// Operator Overloads
bool Line::operator == (const Line& line) const
{
    return length() == line.length();
}

bool Line::operator != (const Line& line) const
{
    return !(*this == line);
}

bool Line::operator < (const Line& line) const
{
    return length() < line.length();
}

bool Line::operator > (const Line& line) const
{
    return !(*this < line);
}

