#include<iostream>
#include <iomanip>
#pragma once
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;
class clsUsersList :protected clsScreen
{
private:
    static void PrintDate(clsUser& Users)
    {
        cout << "| " << setw(12) << left << Users.GetUserName();
        cout << "| " << setw(25) << left << Users.FullName();
        cout << "| " << setw(12) << left << Users.GetPhone();
        cout << "| " << setw(20) << left << Users.GetEmail();
        cout << "| " << setw(10) << left << Users.GetPassword();
        cout << "| " << setw(12) << left << Users.GetPermisson();
    }

public:
    static void Printheader()
    {
        vector<clsUser>Users = clsUser::GetListUsers();
        string  Subject = "\t List Users Screen ";
        string  SusbTitle = "\t [ " + to_string(Users.size()) + " ] " + " Users(U)";
        clsScreen::_DrawScreenHeader(Subject, SusbTitle);
        cout << "\t\n=======================================================================================================" << endl;
        cout << "| " << setw(12) << left << "UserName";
        cout << "| " << setw(25) << left << "FullName";
        cout << "| " << setw(12) << left << "Phone";
        cout << "| " << setw(20) << left << "Email";
        cout << "| " << setw(10) << left << "Password";
        cout << "| " << setw(12) << left << "Permissions";
        cout << "\t\n=======================================================================================================" << endl;

        if (Users.empty())
            cout << "\t\t\t\tNo Clients Available In the System!";

        else
            for (clsUser& U : Users)
            {

                PrintDate(U);
                cout << endl;
            }

        cout << "\t\n=======================================================================================================" << endl;

    }




};
