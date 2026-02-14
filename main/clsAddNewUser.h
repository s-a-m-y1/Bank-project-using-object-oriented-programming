#include<iostream>
#pragma once
#include<string>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;
class clsAddNewUser :protected clsScreen//this is base class 
{
private:

    static void _ReadClient(clsUser& AddUser)
    {
        cout << "Enter A First Name : ";
        AddUser.SetFirstName(clsInputValidate::ReadString());
        cout << "Please Enter a Last Name : ";
        AddUser.SetLastName(clsInputValidate::ReadString());
        cout << "Please Eneter A Email : ";
        AddUser.SetEmail(clsInputValidate::ReadString());
        cout << "Please Enter A Phone : ";
        AddUser.SetPhone(clsInputValidate::ReadString());
        cout << "please Enter A Password : ";
        AddUser.SetPassword(clsInputValidate::ReadString());
        /// Read Permssion Here !!!!!!!!
        AddUser.SetPermisson(ReadPermisionsToSet());
    }

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

    static int ReadPermisionsToSet()
    {
        char What = 'n';
        int Permisions = 0;
        cout << "Do you want full Access [y/n] ? ";
        cin >> ws >> What;
        if (What == 'y' || What == 'Y')
        {
            Permisions += clsUser::EnPermisson::P_Full;
            return Permisions;

        }
        cout << "Do you want List Client Access [y/n] ? ";
        cin >> ws >> What;
        if (What == 'y' || What == 'Y')
        {
            Permisions += clsUser::EnPermisson::P_ListClient;

        }
        cout << "Do you want Add new Client Access [y/n] ? ";
        cin >> ws >> What;
        if (What == 'y' || What == 'Y')
        {
            Permisions += clsUser::EnPermisson::P_AddClient;

        }
        cout << "Do you want Delete Client Access [y/n] ? ";
        cin >> ws >> What;
        if (What == 'y' || What == 'Y')
        {
            Permisions += clsUser::EnPermisson::P_DeleteClient;

        }
        cout << "Do you want Update Client Access [y/n] ? ";
        cin >> ws >> What;
        if (What == 'y' || What == 'Y')
        {
            Permisions += clsUser::EnPermisson::P_UpdateClient;

        }
        cout << "Do you want Find Client Access [y/n] ? ";
        cin >> ws >> What;
        if (What == 'y' || What == 'Y')
        {
            Permisions += clsUser::EnPermisson::P_FindClient;

        }
        cout << "Do you want Tranactions Access [y/n] ? ";
        cin >> ws >> What;
        if (What == 'y' || What == 'Y')
        {
            Permisions += clsUser::EnPermisson::P_Tranactions;

        }
        cout << "Do you want Manage Users Access [y/n] ? ";
        cin >> ws >> What;
        if (What == 'y' || What == 'Y')
        {
            Permisions += clsUser::EnPermisson::P_ManageUsers;
            // Permisions |= clsUser::EnPermisson::P_ManageUsers;
        }
        cout << "Do you want Login Register Users Access [y/n] ? ";
        cin >> ws >> What;
        if (What == 'y' || What == 'Y')
        {
            Permisions += clsUser::EnPermisson::P_Register;
            // Permisions |= clsUser::EnPermisson::P_ManageUsers;
        }
        return Permisions;
    }
public:


    static void AddUserScreen()
    {
        clsScreen::_DrawScreenHeader("Add  user Screen");
        string Username = "";
        cout << "Please Enter a Username : ";
        Username = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(Username))
        {
            cout << "inValed Username try again :) ";
            Username = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::GetAddNewUserobject(Username);//this is contrac for the Add New user handel  username
        _ReadClient(User);
        clsUser::Ensaveresult saving = User.Save();
        switch (saving)
        {
        case clsUser::Ensaveresult::EsaveSuceedad:
            cout << " Deone Add Suceedad  Show Detales : " << endl;
            _Print(User);
            break;
        case clsUser::Ensaveresult::svFaildAccountNumberExists:
            cout << " ! Sorry There is Data Is False Please try again. (: " << endl;
            break;
        case clsUser::Ensaveresult::ESaveEmptyobject:
            cout << " ! Sorry, this process did not work. Please try again. (: " << endl;
            break;
        }
    }

};
