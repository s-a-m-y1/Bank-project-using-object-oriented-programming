#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using  namespace std;

class clsDeleteUserScreen :protected clsScreen
{
private:

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
public:

    static void DeleteUSerScreen()
    {


        clsScreen::_DrawScreenHeader("\tDelete User Screen");

        string Username = "";
        cout << "Enter a Username : ";
        Username = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(Username))
        {
            cout << "Invaled Username please Try agian :";
            Username = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::FindUser(Username);
        _Print(User);

        char What = 'n';
        cout << "Are you sure delete user : [y/n]";
        cin >> ws >> What;
        if (What == 'y' || What == 'Y')
        {
            cout << "Delete Sucessfully :) " << endl;
            if (User.DeleteUSer())
            {
                cout << "User Deleted Successfully." << endl;
                _Print(User);
            }

        }
        else
        {

            cout << "Operation Cancelled." << endl;
        }



    }

};