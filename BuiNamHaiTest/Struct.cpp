#include "Struct.h"

Line::Line(const Point& pointA, const Point& pointB)
{
    a = pointB.Y - pointA.Y;
    b = pointA.X - pointB.X;
    c = (pointA.X - pointB.X) * pointA.Y + (pointB.Y - pointA.Y) * pointA.X;

    m_pointA = pointA;
    m_pointB = pointB;
}

Point Line::GetIntersectionPoint(const Line& that)
{
    Point intersection;

    //Lines are parallel
    double slope = this->a * that.b - that.a * this->b;
    //if (slope == ZERO) {
    if (isParallel(that)) {
        intersection.X = INT_MAX;
        intersection.Y = INT_MAX;
        return intersection;
    }
    intersection.X = (this->c * that.b - that.c * this->b) / slope;
    intersection.Y = (this->a * that.c - that.a * this->c) / slope;
    return intersection;
}

bool Line::isParallel(const Line& that)
{
    double slope = this->a * that.b - that.a * this->b;
    return (slope == ZERO) ? true : false;
}

bool Line::isPointOnTheLineSegment(const Point& point)
{
    if (min(this->m_pointA.X, this->m_pointB.X) <= point.X
        && max(this->m_pointA.X, this->m_pointB.X) >= point.X
        && min(this->m_pointA.Y, this->m_pointB.Y) <= point.Y
        && max(this->m_pointA.Y, this->m_pointB.Y) >= point.Y)
    {
        return true;
    }
    return false;
}

double Line::GetDistanceBetweenTwoPoints(const Point& pointA, const Point& pointB)
{
    return sqrt((pointA.X - pointB.X) * (pointA.X - pointB.X) +
        (pointA.Y - pointB.Y) * (pointA.Y - pointB.Y));
}
