#include<iostream>
#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsDepsitScreen :protected clsScreen
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

        clsScreen::_DrawScreenHeader("Depsit Screen ");

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

            double Dep = 0;
            cout << "please Enter A Depsit : ";
            Dep = clsInputValidate::ReadDblNumber();
            while (Dep <= 100)
            {
                cout << "Invaled Number :" << endl;
                Dep = clsInputValidate::ReadDblNumber();
            }

            char Anwer = 'N';
            cout << "Are You Sure Depsit : [Y N ]:";
            cin >> Anwer;

            if (Anwer == 'Y' || Anwer == 'y')
            {
                cout << "Done " << endl;
                Client.Deposit(Dep);
                cout << "New Balance : " << Client.GetAccountBalance() << endl;
            }




        }
    }

};



