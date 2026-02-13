#include<iostream>
#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsclsWithdrawScreen :protected clsScreen
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

    static  string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:
    static void ShowDepsitScreen()
    {

        clsScreen::_DrawScreenHeader(" \tWithdraw Screen ");

        string AccountN = _ReadAccountNumber();
        while (!clsBankClient::isClientExist(AccountN))
        {
            cout << "Ivaled Acount Number [" << AccountN << "] Try ";
            AccountN = _ReadAccountNumber();
        }
        clsBankClient Client = clsBankClient::Find(AccountN);
        _Print(Client);
        double Check = Client.GetAccountBalance();
        if (Check == 0)
        {
            cout << "There is no balance" << endl;
            return;
        }
        else
        {
            double Withdraw = 0;
            cout << "Plaese Enter A Withdraw : ";
            Withdraw = clsInputValidate::ReadDblNumber();
            char What = 'n';
            cout << "Are You Sure Withdraw balance [Y - N]" << endl;
            cin >> ws >> What;
            if (What == 'y' || What == 'Y')
            {
                Client.Withdraw(Withdraw);
                cout << "Done Successfully New Balance is : " << Client.GetAccountBalance() << endl;

            }
            else
            {
                cout << "Withdraw Cancelled " << endl;
            }




        }
    }


};