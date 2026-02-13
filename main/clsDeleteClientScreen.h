#include<iostream>
#include"clsBankClient.h"
#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsDeleteClientScreen :protected clsScreen
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
    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRight(clsUser::EnPermisson::P_DeleteClient))
        {
            return;
        }
        clsScreen::_DrawScreenHeader("\t Delete Client Screen");
        string AccountNumber = "";
        cout << "Enter A Account Number ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "The Client IS Exsist Please Enter A Client :";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);
        char What = 'n';
        cout << "Are you sure you want to delete this client [Y] [N] ? " << endl;
        cin >> ws >> What;
        if (toupper((What) == 'y'))
        {
            if (Client.Delete())
            {

                _Print(Client);
            }
            else
            {
                cout << "Error Client Was Not Deleted" << endl;
            }

        }
        else
        {
            cout << "Client Delete Cancelled " << endl;
        }


    }


};