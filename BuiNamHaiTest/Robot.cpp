#include "Robot.h"

Robot::Robot(Square& square)
{
    position = &square;
}

Robot::~Robot()
{
    delete position;
}

void Robot::MoveTo(SquareGrid*& squareGrid, int newRow, int newCol)
{
    if (!squareGrid) {
        throw(Exception("Robot.cpp error (nullptr)"));
        return;
    }
    position = &(squareGrid->GetSquare(newRow, newCol));
}

void Robot::ShowCurrentIndex()
{
    cout << "Current position of robot: ";
    cout << "ROW = " << position->GetCurrentRow() << " " << "COL = " << position->GetCurrentCol() << "\n";
}

void Robot::Draw(Square*& square)
{
    if (!square) {
        throw(Exception("Robot.cpp::Draw error"));
        return;
    }
    square->SetValue(DRAW_CHARACTER);
}

void Robot::LineTo(SquareGrid*& squareGrid, int goalRow, int goalCol) {
    {
        Square* goal = &(squareGrid->GetSquare(goalRow, goalCol));
        if (position == goal) {
            cout << "Current position and Goal are the same" << "\n";
            return;
        }

        if (!goal || !squareGrid) {
            throw(Exception("Robot.cpp::LineTo error"));
            return;
        }

        Line lineFromCurrentPositionToGoal(position->GetCenterPoint(), goal->GetCenterPoint());
        map<Square*, bool> Visited;

        while (position != goal)
        {
            Draw(position);
            Visited[position] = true;

            vector<Square*> NextSteps = GetAllNextSteps(squareGrid, position->GetCurrentRow()
                , position->GetCurrentCol());

            vector<Square*> SquareValid;

            for (int i = 0; i < NextSteps.size(); i++) {
                if (NextSteps[i] == goal) {
                    position = goal;
                }

                bool isValid = false;
                bool isPointPassThroughSquare = false;
                int count = 0;

                //get list of square (4 slide)
                vector<Line> fourSlideOfSquare = NextSteps[i]->GetListSlide();
                vector<Point> pointOfSquare = NextSteps[i]->GetListPoint();

                for (auto& slide : fourSlideOfSquare) {
                    Point point = slide.GetIntersectionPoint(lineFromCurrentPositionToGoal);
                    if (slide.isPointOnTheLineSegment(point) && lineFromCurrentPositionToGoal.isPointOnTheLineSegment(point)) {
                        ++count;
                    }
                    for (auto& pointTemp : pointOfSquare) {
                        if (pointTemp == point) {
                            isPointPassThroughSquare = true;
                        }
                    }
                }

                if (count >= 2 && !isPointPassThroughSquare) {
                    isValid = true;
                }
                // 3 la so diem cat trong truong hop doan thang di qua 1 ddiem o gocs cua hinh vuong 
                else if (count >= 3 && isPointPassThroughSquare) {
                    isValid = true;
                }

                if (isValid && !Visited[NextSteps[i]]) {
                    Draw(NextSteps[i]);
                    Visited[NextSteps[i]] = true;

                    SquareValid.push_back(NextSteps[i]);
                }
            }
            //get square min Distance From Current Center To Goal Center
            double minDistanceFromCenterAToCenterB = INT32_MAX;
            for (auto step : SquareValid) {
                Line line;
                double length = line.GetDistanceBetweenTwoPoints(position->GetCenterPoint(), step->GetCenterPoint());
                if (minDistanceFromCenterAToCenterB > length) {
                    minDistanceFromCenterAToCenterB = length;
                    position = step;
                }
            }
        }
        Draw(position);
    }
}

vector<Square*> Robot::GetAllNextSteps(SquareGrid*& squareGrid, int currentRow, int currentCol)
{
    // Initialize direction vectors
    vector<int> paddingRow = { -1, -1, -1,  0, 0,  1, 1, 1 };
    vector<int> paddingCol = { -1,  0,  1, -1, 1, -1, 0, 1 };
    vector<Square*> NextSteps;

    if (!squareGrid) {
        throw(Exception("Robot.cpp::GetAllNextSteps error"));
        return NextSteps;
    }

    //we are allowed to move in eight directions only (base on a line from center of A to center of B )
    int eightDirections = 8;
    for (int i = 0; i < eightDirections; i++) {
        int nextRow = currentRow + paddingRow[i];
        int nextCol = currentCol + paddingCol[i];
        if (nextRow < squareGrid->GetMaxRow() && nextCol < squareGrid->GetMaxColumn()
            && nextRow >= 0 && nextCol >= 0) {

            Square* nextStep = &(squareGrid->GetSquare(nextRow, nextCol));
            NextSteps.push_back(nextStep);
        }
    }
    return NextSteps;
}
    

