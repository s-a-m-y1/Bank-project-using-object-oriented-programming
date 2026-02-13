#include<iostream>
#include"clsBankClient.h"
#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsAddNewClientScreen :protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& client)
    {
        cout << "Enter A fristname : ";
        client.SetFirstName(clsInputValidate::ReadString());
        cout << "Enter A Lastname : ";
        client.SetLastName(clsInputValidate::ReadString());
        cout << "Enter A Email : ";
        client.SetEmail(clsInputValidate::ReadString());
        cout << "Enter A phone : ";
        client.SetPhone(clsInputValidate::ReadString());
        cout << "Enter A Pincode : ";
        client.SetPinCode(clsInputValidate::ReadString());
        cout << "Enter A Accoount Balance : ";
        client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
    }

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

    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRight(clsUser::EnPermisson::P_AddClient))
        {
            return;
        }
        clsScreen::_DrawScreenHeader("\t Add New Client Screen");
        string AccountNumber = "";
        cout << "Enter A Account Number ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::isClientExist(AccountNumber))
        {
            cout << "The Client IS Exsist Please Enter A Client :";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Add(AccountNumber);
        _ReadClientInfo(Client);
        clsBankClient::Ensaveresult Saveing = Client.Save();
        switch (Saveing)
        {
        case clsBankClient::Ensaveresult::EsaveSuceedad:
            _Print(Client);
            break;
        case clsBankClient::Ensaveresult::svFaildAccountNumberExists:
            cout << "The Account Error : " << endl;
            break;
        case clsBankClient::ESaveEmptyobject:
            cout << "Error Account " << endl;
            break;

        }

    }


};




