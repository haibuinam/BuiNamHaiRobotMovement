#pragma once
#include<iostream>
#include <fstream>
#include <vector>
#include"SquareGrid.h"
#include"Square.h"
#include"Robot.h"
#include"InputController.h"
#include"OutputController.h"
using namespace std;

class RobotController
{
private:
    const string DIMENSION_ACTION = "DIMENSION";
    const string MOVE_TO_ACTION = "MOVE_TO";
    const string LINE_TO_ACTION = "LINE_TO";
    const string EXIT_ACTION = "EXIT";

    Robot* robot = nullptr;
    SquareGrid* squareGrid = nullptr;
    InputController* inputController = nullptr;
    OutputController* outputController = nullptr;

public:
    RobotController();
    ~RobotController();

    bool InitData();

    void DoWork();

    bool isInputRowAndColumnValid(int inputRow, int inputCol);
};
