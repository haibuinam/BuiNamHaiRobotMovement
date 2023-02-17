#include "Square.h"
Square::Square(int row, int col)
{
    m_value = DEFAULT_CHARACTER;
    currentRow = row;
    currentCol = col;

    //init 5 point of square base on col and row
    topLeft.X = row;
    topLeft.Y = col;

    topRight.X = row;
    topRight.Y = col + LENGTH_OF_SQUARE;

    belowLeft.X = row + LENGTH_OF_SQUARE;
    belowLeft.Y = col;

    belowRight.X = row + LENGTH_OF_SQUARE;
    belowRight.Y = col + LENGTH_OF_SQUARE;

    center.X = (topLeft.X + belowRight.X) / 2;
    center.Y = (topLeft.Y + belowRight.Y) / 2;
}

Square::~Square()
{
}

int Square::GetCurrentRow()const
{
    return currentRow;
}

int Square::GetCurrentCol() const
{
    return currentCol;
}

Point Square::GetCenterPoint() const
{
    return center;
}

bool Square::isDraw()
{
    return (m_value == DRAW_CHARACTER) ? true : false;
}

void Square::SetValue(char value)
{
    m_value = value;
}

const vector<Line> Square::GetListSlide() const
{
    vector<Line> listOfSlide;
    Line topSquare(topLeft, topRight);
    Line rightSquare(topRight, belowRight);
    Line belowSquae(belowRight, belowLeft);
    Line leftSquare(belowLeft, topLeft);

    listOfSlide.push_back(topSquare);
    listOfSlide.push_back(rightSquare);
    listOfSlide.push_back(belowSquae);
    listOfSlide.push_back(leftSquare);
    return listOfSlide;
}

const vector<Point> Square::GetListPoint() const
{
    vector<Point> listOfPoint;
    listOfPoint.push_back(topLeft);
    listOfPoint.push_back(topRight);
    listOfPoint.push_back(belowRight);
    listOfPoint.push_back(belowLeft);
    return listOfPoint;
}

bool Square::operator==(const Square& that)
{
    if (this->currentCol == that.currentCol && this->currentRow == that.currentRow)
        return true;
    return false;
}

bool Square::operator!=(const Square& that)
{
    return !operator==(that);
}
