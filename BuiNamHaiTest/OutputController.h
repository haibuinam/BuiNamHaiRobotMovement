#pragma once
#include<iostream>
#include"SquareGrid.h"

class OutputController
{
public:
    OutputController(){}

    void PrintResult(SquareGrid*& squareGrid) {
        if (!squareGrid) {
            cout << "error";
            return;
        }
        for (int indexRow = 0; indexRow < squareGrid->GetMaxRow(); indexRow++) {
            for (int indexCol = 0; indexCol < squareGrid->GetMaxColumn(); indexCol++) {
                cout << squareGrid->GetSquare(indexRow, indexCol) << "|";
            }
            cout << "\n";
        }
    }
};

