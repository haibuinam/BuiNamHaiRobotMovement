#pragma once
#include<iostream>
#include <fstream>
#include <string>
#include"SquareGrid.h"
#include"Square.h"
#include"Struct.h"
using namespace std;
class InputController
{
private:
    ifstream data;

public:
    InputController() : data{ "Data.txt" } {}

    bool isGood() {
        return data.good();
    }

    string GetMode();

    int Get_int();

    void Skip_to_int();
   
    //todo handle index out of value
    int Get_Index_Of_Grid(int minIndex, int maxIndex);
};

