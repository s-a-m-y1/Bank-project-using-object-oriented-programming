#include<iostream>
#pragma once
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;

class clsUpdateUserScreen :protected clsScreen
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
        }
        return Permisions;
    }


public:


    static void UpdateUserScreen()
    {


        clsScreen::_DrawScreenHeader("\t Update User Screen ");
        string Username = "";

        cout << "Please enter a User name : ";
        Username = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(Username))///
        {
            cout << "Invaled Username Please Try again : ";
            Username = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::FindUser(Username);

        cout << "Detals " << endl;
        _Print(User);
        cout << "\n==================" << endl;
        cout << "Are you sure Update this user :";
        char What = 'n';
        cin >> ws >> What;
        if (What == 'y' || What == 'Y')
        {
            _ReadClient(User);
            clsUser::Ensaveresult Saving = User.Save();
            switch (Saving)
            {
            case clsUser::Ensaveresult::EsaveSuceedad:
                cout << "User Updated Successfully " << endl;
                break;
            case clsUser::Ensaveresult::ESaveEmptyobject:
                cout << "Error User Was Not Updated Because It's Empty " << endl;
                break;
            case clsUser::Ensaveresult::svFaildAccountNumberExists:
                cout << "Error User Was Not Updated Because Username  Already Exists " << endl;
                break;

            }
        }
        else
        {
            cout << "Exit";
        }





    }







};