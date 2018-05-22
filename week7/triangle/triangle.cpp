// Implementation for Triangle class
#include "triangle.h"

Triangle::Triangle() 
    : point1(Point(0,0)), point2(Point(0,1)), point3(Point(1,0)) 
{
    adjustLines();
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    : point1(Point(x1, y1)), point2(Point(x2, y2)), point3(Point(x3, y3)) 
{
    adjustLines();
}

Triangle::Triangle(const Point& pointA, const Point& pointB, const Point& pointC)
    : point1(pointA), point2(pointB), point3(pointC) 
 {
     adjustLines();
 }

// Inspectors
const Point& Triangle::getPoint1() const
{
    return point1;
}

const Point& Triangle::getPoint2() const
{
    return point2;
}

const Point& Triangle::getPoint3() const
{
    return point3;
}

const Line& Triangle::getSide1() const
{
    return side1;
}

const Line& Triangle::getSide2() const
{
    return side2;
}

const Line& Triangle::getSide3() const
{
    return side3;
}

// Mutators
Triangle* Triangle::setPoint1(const int& x, const int& y)
{
    point1.x(x)->y(y);
    adjustLines();
    return this;
}

Triangle* Triangle::setPoint2(const int& x, const int& y)
{
    point2.x(x)->y(y);
    adjustLines();
    return this;
}

Triangle* Triangle::setPoint3(const int& x, const int& y)
{
    point3.x(x)->y(y);
    adjustLines();
    return this;
}

// Member functions
bool Triangle::rightTriangle()
{
    std::vector<double> sides = {side1.length(), side2.length(), side3.length()};
    std::sort(sides.begin(), sides.end());

    // sqrt(A^2 + B^2) == C
    return sqrt(pow(sides[0], 2) + pow(sides[1], 2)) == sides[2];
}

// Operator Overloads
bool Triangle::operator == (const Triangle& triangle) const
{
    std::vector<Line> sides = { side1, side2, side3 };
    std::vector<Line> comparisons = { triangle.getSide1(), 
                                      triangle.getSide2(), 
                                      triangle.getSide3() };

    std::sort(sides.begin(), sides.end());
    std::sort(comparisons.begin(), comparisons.end());
    for (int i = 0; i < 3; i++)
    {
        if (sides[i] != comparisons[i])
        {
            return false;
        }
    }
   
    return true;
}

bool Triangle::operator != (const Triangle& triangle) const
{
    return !(*this == triangle);
}

// Sub-routine
void Triangle::adjustLines()
{
    side1.point1(point1)->point2(point2);
    side2.point1(point2)->point2(point3);
    side3.point1(point3)->point2(point1);
}