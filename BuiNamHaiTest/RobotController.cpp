#include "RobotController.h"

RobotController::RobotController()
{
    inputController = new InputController();
    outputController = new OutputController();
    InitData();
}

RobotController::~RobotController()
{
    delete robot;
    delete squareGrid;
    delete inputController;
    delete outputController;
}

bool RobotController::InitData()
{
    while (inputController->isGood())
    {
        string chosse;
        int size = { 0 };
        chosse = inputController->GetMode();
        if (chosse == DIMENSION_ACTION) {
            size = inputController->Get_int();
        }
        
        squareGrid = new SquareGrid(size);
        robot = new Robot(squareGrid->GetSquare(DEFAULT_ROW, DEFAULT_COL));
        break;
    }
    if (!squareGrid && !robot)
    {
        throw(Exception("RobotController.cpp error (nullptr)"));
        return false;
    }
    return true;
}

void RobotController::DoWork()
{
    if (squareGrid->GetMaxRow() < DEFAULT_SIZE) {
        cout << "Size of grid > " << DEFAULT_SIZE<<"\n";
        return;
    }
    if (!squareGrid || !robot) {
        cout << "robot or squareGrid is null " << "\n";
        return;
    }

    bool isContinue = true;
    while (isContinue && inputController->isGood())
    {
        string chosse;
        chosse = inputController->GetMode();
        if (chosse == MOVE_TO_ACTION) {
            int newRow = inputController->Get_Index_Of_Grid(0, squareGrid->GetMaxIndexRow());
            int newCol = inputController->Get_Index_Of_Grid(0, squareGrid->GetMaxIndexCol());

            if (isInputRowAndColumnValid(newRow, newCol))
            {
                robot->MoveTo(squareGrid, newRow, newCol);
                outputController->PrintResult(squareGrid);
                robot->ShowCurrentIndex();
            }
        }
        else if (chosse == LINE_TO_ACTION) {
            int goalRow = inputController->Get_Index_Of_Grid(0, squareGrid->GetMaxIndexRow());
            int goalCol = inputController->Get_Index_Of_Grid(0, squareGrid->GetMaxIndexCol());

            if (isInputRowAndColumnValid(goalRow, goalCol)) {
                robot->LineTo(squareGrid, goalRow, goalCol);
                outputController->PrintResult(squareGrid);
                cout << "goalRow = " << goalRow << " " << "goalCol = " << goalCol << "\n";
            }
        }
        else if (chosse == EXIT_ACTION) {
            isContinue = false;
        }
    }
}

bool RobotController::isInputRowAndColumnValid(int inputRow, int inputCol)
{
    return (inputRow <= squareGrid->GetMaxIndexRow() && inputCol <= squareGrid->GetMaxIndexCol()) ? true : false;
}
