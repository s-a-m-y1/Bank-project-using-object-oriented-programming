#pragma once
#include<iostream>
#include"Global.h"
#include <iomanip>
#include"clsUser.h"
#include"clsScreen.h"
using namespace std;
class ShowLoginRegisterScreen :protected clsScreen
{

private:
	static void _PrintHeader(clsUser::St_DataSeachon Data)
	{
		cout << "| " << setw(35) << left << Data.DateTime;
		cout << "| " << setw(15) << left << Data.UserName;
		cout << "| " << setw(15) << left << Data.Password;
		cout << "| " << setw(15) << left << Data.Permisson;
	}

public:
	static void ShowListLogin()
	{
		if (!clsScreen::CheckAccessRight(clsUser::EnPermisson::P_Register))
		{
			return;
		}
		vector <clsUser:: St_DataSeachon >VData = clsUser::LoadLoginsessions();
		string Title = "\tShow Login Register Screen";
		string SubTitle = "\t\tTotal Users : " + to_string(VData.size()) + " ( U ).";
		clsScreen::_DrawScreenHeader(Title , SubTitle);
		cout << "\t\n=============================================================================================" << endl;
		cout << "| " << setw(35) << left << "DateTime";
		cout << "| " << setw(15) << left <<"UserName";
		cout << "| " << setw(15) << left << "Password";
		cout << "| " << setw(15) << left <<"Permisson";
		cout << "\t\n=============================================================================================" << endl;
		if (VData.size() == 0)
		{
			cout << "\t\t\t\tNo Users Available In the System!";
		}
		else
		{
			for (clsUser::St_DataSeachon U : VData)
			{
				_PrintHeader(U);
				cout << endl;
			}
		}
		cout << "\t\n=============================================================================================" << endl;
    }

};
	


