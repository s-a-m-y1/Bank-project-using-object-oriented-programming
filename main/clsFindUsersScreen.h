#include<iostream>
#pragma once
#include<string>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;
class clsFindUsersScreen :protected clsScreen
{
private:
    static void _Print(clsUser& User)
    {

        system("cls");
        cout << "===================" << endl;
        cout << "Client Details" << endl;
        cout << "==================" << endl;
        cout << "FirstName: " << User.GetFirstName() << endl;
        cout << "LastName : " << User.GetlastName() << endl;
        cout << "FullName : " << User.FullName() << endl;
        cout << "Email : " << User.GetEmail() << endl;
        cout << "Phone : " << User.GetPhone() << endl;
        cout << "UserName  : " << User.GetUserName() << endl;
        cout << "Password : " << User.GetPassword() << endl;
        cout << "Permssion : " << User.GetPermisson() << endl;
        cout << "==================" << endl;
    }
public:

    static void FindUserScreen()
    {
        clsScreen::_DrawScreenHeader(" \t Find User Screen");
        string Username = "";
        cout << "Please Enter a Username : ";
        Username = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(Username))
        {
            cout << "Invaled Username Please Try again : ";
            Username = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::FindUser(Username);
        if (!User.IsEmpty())
        {
            cout << "\nUser Found :-)\n";

            _Print(User);
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

    }
};