#include "InputController.h"

string InputController::GetMode()
{
       string mode;
       data >> mode;
       return mode;
}

int InputController::Get_int()
{
    int number = 0;
    while (!data.eof())
    {
        if (data >> number) {
            return number;
        }
        Skip_to_int();
    }
    //exception
    throw;
    return INT_MAX;
}

void InputController::Skip_to_int()
{
    if (data.fail()) {
        data.clear();
        bool removeCharacter = true;
        while (!data.eof())
        {
            char nextChar;
            data >> nextChar;
            if (isdigit(nextChar))
            {
                //put nextChar back
                data.unget();
                return;
            }
        }
    }
    throw(Exception("InputController: No valid integer found in input file"));
}

int InputController::Get_Index_Of_Grid(int minIndex, int maxIndex)
{
    while (isGood() && !data.eof())
    {
        try {
            int index = Get_int();
            if (minIndex <= index && index <= maxIndex) {
                return index;
            }
            cout << "Index of grid = "<<index<<" is illegal" << "\n";
        }
        catch (Exception& msg) {
            cout << msg.what() << "\n";
            return INT32_MAX;
        }
    }
    return INT32_MAX;
}
