
#include<iostream>
#include"RobotController.h"
using namespace std;

int main()
{
    try {

        RobotController* robotController = new RobotController();
        robotController->DoWork();
    }
    catch (Exception& msg) {
        cout << msg.what() << "\n";
    }

    return 0;
}
