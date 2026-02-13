#include<iostream>
#include"clsBankClient.h"
#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsFindClientScreen :protected clsScreen
{
private:
    static void _Print(clsBankClient& bank)
    {

        system("cls");
        cout << "===================" << endl;
        cout << "Client Details" << endl;
        cout << "==================" << endl;
        cout << "FirstName: " << bank.GetFirstName() << endl;
        cout << "LastName : " << bank.GetlastName() << endl;
        cout << "FullName : " << bank.FullName() << endl;
        cout << "Email : " << bank.GetEmail() << endl;
        cout << "Phone : " << bank.GetPhone() << endl;
        cout << "AccountNumber : " << bank.GetAccountNumber() << endl;
        cout << "PinCode : " << bank.Getpincode() << endl;
        cout << "AccountBalance : " << bank.GetAccountBalance() << endl;
        cout << "==================" << endl;
    }

public:
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRight(clsUser::EnPermisson::P_FindClient))
        {
            return;
        }

        clsScreen::_DrawScreenHeader("\t Find Client Screen");
        string AccountNumber = "";
        cout << "Enter A Account Number ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "The Client IS Not Exsist Please Enter A Client :";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _Print(Client);
    }
};