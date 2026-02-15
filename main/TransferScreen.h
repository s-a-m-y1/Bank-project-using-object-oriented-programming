#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"Global.h"
#include"clsBankClient.h"
#include"clsScreen.h"
class TransferScreen :protected clsScreen
{
private:
	static void _PrintClientCard(clsBankClient& Client)
	{
		cout << "=======:)=========" << endl;
		cout << " Fullname : " << Client.FullName() << endl;
		cout << " Account Number : " << Client.GetAccountNumber() << endl;
		cout << " Account Balance  : " << Client.GetAccountBalance() << endl;
		cout << "=======:)=========" << endl;
		cout << endl;
	}
public:
	static void ShowTransfareScreen()
	{
		_DrawScreenHeader("Transfare Screen ");
		double Pass = 0;
		double pass2 = 0;
		double ReadAccountbanance = 0;
		string AccountNumber = "";

		cout << "Please Enter Account Number to Transfare From :";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::isClientExist(AccountNumber))
		{
			cout << "Invaled Account number Try again :)";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient CLient1 = clsBankClient::Find(AccountNumber);
		_PrintClientCard(CLient1);

		cout << "Please Enter Account Number to Transfare To :";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::isClientExist(AccountNumber))
		{
			cout << "Invaled Account number Try again :)";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client2 = clsBankClient::Find(AccountNumber);
		_PrintClientCard(Client2);
		///...............................//
		cout << "Enter Trancfare Amount :  ";
		ReadAccountbanance = clsInputValidate::ReadDblNumber();
		while (ReadAccountbanance > CLient1.GetAccountBalance() || ReadAccountbanance <= 0)
		{
			cout << "Amount Exceeds the available Balance , Enter A Nother Amount : ";
			ReadAccountbanance = clsInputValidate::ReadDblNumber();
		}
		char What = 'n';
		cout << "Are you sure this Trancfare [Y / N] :  ";
		cin >> ws >> What;
		if (What == 'Y'||What=='y')
		{
			///...............[-]................//
			Pass = CLient1.GetAccountBalance();
			Pass -= ReadAccountbanance;
			CLient1.SetAccountBalance(Pass);
			///...............................//
			/// 
			///...............[+]................//
			pass2 = Client2.GetAccountBalance();
			pass2 += ReadAccountbanance;
			Client2.SetAccountBalance(pass2);
			///...............................//
		}
		else
		{
			cout << "Is not oprethon :) " << endl;
			return;
		}

		///_________________________________________________________??/
		clsBankClient::Ensaveresult savingclient1 = CLient1.Save();
		clsBankClient::Ensaveresult savingclient2 = Client2.Save();
///_________________________________________________________?//
			if (savingclient1== clsBankClient::Ensaveresult::EsaveSuceedad&& savingclient2 == clsBankClient::Ensaveresult::EsaveSuceedad)
			{
				cout << "Trancfare Done Suceedad :) " << endl<<endl;
				cout << "Client Card :) " << endl;
				_PrintClientCard(CLient1);
				cout << endl;
				_PrintClientCard(Client2);
			}
			else if (savingclient1 == clsBankClient::Ensaveresult::ESaveEmptyobject && savingclient2 == clsBankClient::Ensaveresult::ESaveEmptyobject)
			{
				cout << "Trancfare Failed Empty Object :) " << endl;
			}
			else if (savingclient1 == clsBankClient::Ensaveresult::svFaildAccountNumberExists && savingclient2 == clsBankClient::Ensaveresult::svFaildAccountNumberExists)
			{
				cout << "Trancfare Failed Account Number Exists :) " << endl;

			}
		

	}
};

