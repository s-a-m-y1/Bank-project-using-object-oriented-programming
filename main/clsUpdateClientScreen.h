#include<iostream>
#pragma once
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsUpdateClientScreen :protected clsScreen
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
    static void ShowUpdateClientScreen()
    {


        if (!CheckAccessRight(clsUser::EnPermisson::P_UpdateClient))
        {
            return;
        }
        clsScreen::_DrawScreenHeader("\t Update Client Screen");
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
        _ReadClientInfo(Client);
        clsBankClient::Ensaveresult Saveing = Client.Save();
        switch (Saveing)
        {
        case clsBankClient::Ensaveresult::EsaveSuceedad:
            cout << "Client Updated Successfully " << endl;
            break;
        case clsBankClient::Ensaveresult::ESaveEmptyobject:
            cout << "Error Client Was Not Updated Because It's Empty " << endl;
            break;
        case clsBankClient::Ensaveresult::svFaildAccountNumberExists:
            cout << "Error Client Was Not Updated Because Account Number Already Exists " << endl;
            break;

        }

    }




};
