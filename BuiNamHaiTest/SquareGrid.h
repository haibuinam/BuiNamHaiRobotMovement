#pragma once
#include<iostream>
#include"Square.h"
#include"InputController.h"
#include"Constants.h"
class SquareGrid
{
private:
    int m_row;
    int m_column;
    Square** m_squareGrid = nullptr;

    void initGrid();
public:
    SquareGrid(int gridSize);
    ~SquareGrid();
    
    int GetMaxRow() const;
    int GetMaxColumn() const;
    
    int GetMaxIndexRow() const;
    int GetMaxIndexCol() const; 

    Square& GetSquare(int row, int col) const;
};

