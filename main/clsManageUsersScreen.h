#include<iostream>
#pragma once

#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUsersList.h"
#include"clsAddNewUser.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUsersScreen.h"
#include <iomanip>
using namespace std;
class clsManageUsersScreen :protected clsScreen
{
private:
    enum EnPerformopthion { EList = 1, EAdd = 2, EDelete = 3, EUpdate = 4, EFind = 5, EMain = 6 };
    static void _Clear1()
    {
        system("cls");
    }
    static void _GoBack()
    {
        cout << "\n\nPress any key to go back to Manageusers Menue...";
        system("pause>0");
        mainMenuScreen();
    }
    static short _ReadOpthion()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;

    }
    static void _ListUSersScreen()
    {
        clsUsersList::Printheader();

    }
    static void _AddNewUSersScreen()
    {
        clsAddNewUser::AddUserScreen();

    }
    static void _DeleteUsersScreen()
    {
        clsDeleteUserScreen::DeleteUSerScreen();

    }
    static void _UpdateUsersScreen()
    {
        clsUpdateUserScreen::UpdateUserScreen();

    }
    static void _FindUserScreen()
    {
        clsFindUsersScreen::FindUserScreen();

    }


    static  void Swiching(EnPerformopthion Choose)
    {
        switch (Choose)
        {
        case EnPerformopthion::EList:
            _Clear1();
            _ListUSersScreen();
            _GoBack();
            break;
        case EnPerformopthion::EAdd:
            _Clear1();
            _AddNewUSersScreen();
            _GoBack();
            break;
        case EnPerformopthion::EDelete:
            _Clear1();
            _DeleteUsersScreen();
            _GoBack();
            break;
        case EnPerformopthion::EUpdate:
            _Clear1();
            _UpdateUsersScreen();
            _GoBack();
            break;
        case EnPerformopthion::EFind:
            _Clear1();
            _FindUserScreen();
            _GoBack();
            break;
        case EnPerformopthion::EMain:
            return;

        }

    }

public:

    static void  mainMenuScreen()
    {
        if (!CheckAccessRight(clsUser::EnPermisson::P_ManageUsers))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users. \n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Users List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User .\n";
        cout << setw(37) << left << "" << "\t[3] Delete User .\n";
        cout << setw(37) << left << "" << "\t[4] Update User .\n";
        cout << setw(37) << left << "" << "\t[5] Find User .\n";
        cout << setw(37) << left << "" << "\t[6] Main Screen  .\n";
        cout << setw(37) << left << "" << "===========================================\n";

        Swiching((EnPerformopthion)_ReadOpthion());
    }



};

