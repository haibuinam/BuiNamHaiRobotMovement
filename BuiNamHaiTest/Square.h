#pragma once
#include<iostream>
#include<vector>
#include"Constants.h"
#include "Struct.h"
using namespace std;

class Square
{
private:
    Point topLeft;
    Point topRight;
    Point belowLeft;
    Point belowRight;
    Point center;
    
    int currentRow{ 0 };
    int currentCol{ 0 };
    char m_value{ ' ' };
public:
    Square() = default;
    Square(int row, int col);

    ~Square();

    int GetCurrentRow() const;
    int GetCurrentCol() const;

    Point GetCenterPoint() const ;

    void SetValue(char value);

    bool isDraw();

    const vector<Line> GetListSlide() const;
    const vector<Point> GetListPoint() const;

    bool operator==(const Square& that);
    bool operator!=(const Square& that);

    friend ostream& operator<<(ostream& os, const Square& square) {
        os << square.m_value << "";
        return os;
    }
};

