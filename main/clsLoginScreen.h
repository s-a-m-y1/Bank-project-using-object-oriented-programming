#pragma once 
#include<iostream>
#include"clsScreen.h"
#include"clsMainScrean.h"
#include"Global.h"
#include"clsUser.h"
using namespace std;
class clsLoginScreen :protected clsScreen
{
private:
    static bool _login()
    {


        bool IsFeald = false;
        short counter = 3;
        string Username = "", Password = "";
        do
        {

            if (IsFeald)//This condition is met if it is true.
            {
                counter--;
                system("cls");
                cout << "________________):_____________" << endl;
                cout << "invalid login username/password \n";
                cout << "You have " << counter << " trials to login : " << endl;
                cout << "_______________^_^____________" << endl;
            }
            if (counter == 0)
            {
                cout << "\n________________________________" << endl;
                cout << "Sorry You've run out of adapters  Please Try again  ^_^  " << endl;
                cout << "\n________________________________" << endl;
                return false;
            }
            cout << "Enter Username : ";
            cin >> Username;

            cout << "Enter Password : ";
            cin >> Password;

            Current = clsUser::FindUser(Username, Password);
            IsFeald = Current.IsEmpty();//this is return true or false in  if true this empty object but if this object updated to return false  
        } while (IsFeald);
        Current.RegsterLogin();
        clsMainScreen::ShowMainMenue();// here in the  condition false 
        return true;
    };


public:
    static bool Login()
    {
        clsScreen::_DrawScreenHeader("\t Login Screen");
        return _login();
    }

};

