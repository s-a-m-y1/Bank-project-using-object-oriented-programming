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
	static string ReadAccountNumber()
	{
		string AccountNumber = "";
		
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}
	static float ReadAccountbanance()
	{		
		float Accountbanance = 0;
		cout << "Enter Trancfare Amount :  ";
		Accountbanance = clsInputValidate::ReadFloatNumber();
		return Accountbanance;
	}
public:
	static void ShowTransfareScreen()
	{
		_DrawScreenHeader("Transfare Screen ");
		string AccountNumber = "";
		cout << "Please Enter Account Number to Transfare From :";
		AccountNumber = ReadAccountNumber();
		while (!clsBankClient::isClientExist(AccountNumber))
		{
			cout << "=================:)===================" << endl;
			cout << "Invaled Account number Try again :)"<<endl;
			cout << "=================:)===================" << endl;
			AccountNumber = ReadAccountNumber();
		}

		clsBankClient CLient1 = clsBankClient::Find(AccountNumber);
		_PrintClientCard(CLient1);

		cout << "Please Enter Account Number to Transfare To :";
		AccountNumber = ReadAccountNumber();
		
		while (!clsBankClient::isClientExist(AccountNumber)||AccountNumber==CLient1.GetAccountNumber())
		{
			cout << "=================:)===================" << endl;
			cout << "Invaled Account number Try again :)"<<endl;
			cout << "=================:)===================" << endl;
			AccountNumber = ReadAccountNumber();
		}

		clsBankClient CLient2 = clsBankClient::Find(AccountNumber);
		_PrintClientCard(CLient2);
   
		float ReadAmount = ReadAccountbanance();
		char What = 'n';
		cout << "Are you sure this Trancfare [Y / N] :  ";
		cin >> ws >> What;
		if (What == 'Y'||What=='y')
		{
			
			while (!CLient1.IsTransfer(ReadAmount, CLient2))
			{
				cout << "=================:)===================" << endl;
				cout << "We're sorry, an error occurred. Please try again." << endl;
				cout << "=================:)===================" << endl;
				ReadAmount = ReadAccountbanance();
			}
				cout << "=================:)===================" << endl;
				cout << "The transaction was successful. Please check your funds." << endl;
				cout << "=================:)===================" << endl;
				printf("\n");
				/*clsBankClient::RecordLine(CLient1, CLient2, ReadAmount);*/
				_PrintClientCard(CLient1);
				_PrintClientCard(CLient2);
		
		}
		else
		{
			
			cout << "=================:)===================" << endl;
			cout << "The operation was not completed :) " << endl;
			cout << "=================:)===================" << endl;
			return;
		}

			

	}
};

