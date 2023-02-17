#pragma once
#include<vector>
#include<queue>
#include<map>
#include"Square.h"
#include"SquareGrid.h"
#include"Constants.h"
using namespace std;
class Robot
{
private:
    Square* position = nullptr;
public:
    Robot() {}
    Robot(Square& square);
    ~Robot();

    void MoveTo(SquareGrid*& squareGrid, int newRow, int newCol);

    void Draw(Square*& square);

    void LineTo(SquareGrid*& squareGrid, int goalRow, int goalCol);

    void ShowCurrentIndex();

private:
    vector<Square*> GetAllNextSteps(SquareGrid*& squareGrid, int currentRow, int currentCol);
};


