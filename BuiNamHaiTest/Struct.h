#pragma once
#include"Constants.h"
#include <exception>
#include <string>
#include <climits>
#include <map>
using namespace std;
//common
struct Point {
    double X = 0;
    double Y = 0;
    Point() {
        X = 0;
        Y = 0;
    }
    Point(double x, double y) {
        X = x;
        Y = y;
    }
    bool operator==(const Point& that) {
        if (this->X == that.X && this->Y == that.Y) {
            return true;
        }
        return false;
    }
};

struct Line {
    //ax + by = c;
    double a = 0;
    double b = 0;
    double c = 0;
    Point m_pointA;
    Point m_pointB;
    Line() {}
    Line(const Point& pointA, const Point& pointB);

    Point GetIntersectionPoint(const Line& that);

    bool isParallel(const Line& that);

    bool isPointOnTheLineSegment(const Point& point);
    
    double GetDistanceBetweenTwoPoints(const Point& pointA, const Point& pointB);
};

//exception
//todo: handle delete object when throw
class Exception : public exception {
    string msg;
public:
    Exception(const string& mesage) : msg{mesage} {
    }
    virtual const char* what() const noexcept override
    {
        return msg.c_str();
    }
};


