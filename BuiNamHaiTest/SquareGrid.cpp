#include "SquareGrid.h"

SquareGrid::SquareGrid(int gridSize)
{
    m_row = gridSize;
    m_column = gridSize;
    initGrid();
}

SquareGrid::~SquareGrid()
{
    for (int indexRow = 0; indexRow < m_row; indexRow++) {
        delete[] m_squareGrid[indexRow];
    }
    delete[] m_squareGrid;
}

void SquareGrid::initGrid()
{
    m_squareGrid = new Square * [m_row];
    for (int indexRow = 0; indexRow < m_row; indexRow++) {
        m_squareGrid[indexRow] = new Square[m_column];
        for (int indexCol = 0; indexCol < m_column; indexCol++) {
            Square* square = new Square(indexRow, indexCol);
            m_squareGrid[indexRow][indexCol] = *square;
        }
    }
}

int SquareGrid::GetMaxRow() const
{
    return m_row;
}

int SquareGrid::GetMaxColumn() const
{
    return m_column;
}

int SquareGrid::GetMaxIndexRow()const
{
    return m_row - 1;
}

int SquareGrid::GetMaxIndexCol() const
{
    return m_column - 1;
}

Square& SquareGrid::GetSquare(int row, int col) const
{
    return m_squareGrid[row][col];
}


