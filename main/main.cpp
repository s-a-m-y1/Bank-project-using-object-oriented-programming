#include<iostream>  
#include"clsLoginScreen.h"
using namespace std;
int main()
{

    while (true)
    {
        if (!clsLoginScreen::Login())
            break;
    }
    system("pause>null");
    return 0;
}