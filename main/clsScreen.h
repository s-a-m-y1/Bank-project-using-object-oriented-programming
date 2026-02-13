#include<iostream>
#include"Global.h"
#include"clsDate.h"
#include"clsUser.h"
#pragma once
using namespace std;
class clsScreen
{


protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t_____________________________________________\n";
        cout << "\n\t\t\t\t\t\t " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t_____________________________________________\n\n";

        cout << "\t\t\t\t\tUser : " << Current.GetUserName() << endl;
        cout << "\t\t\t\t\tDate : " << Date.GetDay() << "/" << Date.GetMonth() << "/" << Date.GetYear() << endl << endl;

    }




    static bool CheckAccessRight(clsUser::EnPermisson Permssion)
    {
        if (!Current.CheckAccessPermssion(Permssion))
        {
            cout << "\t\t\t\t\t ==========================================" << endl;
            cout << "\t\t\t\t\tAccess  Denite ! contant your Admin" << endl;
            cout << "\t\t\t\t\t ==========================================" << endl;

            return false;

        }
        else

            return true;


    }


};