#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
class TransfersLogScreen:protected clsScreen
{


private:
    static void PrintDate(clsBankClient::St_DataLogtransfer  St_DataLogtransfe)
    {
        cout << "| " << setw(25) << left << St_DataLogtransfe.DataATime;
        cout << "| " << setw(12) << left << St_DataLogtransfe.ClientFrom;
        cout << "| " << setw(12) << left << St_DataLogtransfe.ClientTo;
        cout << "| " << setw(10) << left << St_DataLogtransfe.MoneyTrancfer;
        cout << "| " << setw(15) << left << St_DataLogtransfe.BC1;
        cout << "| " << setw(15) << left << St_DataLogtransfe.BC2;
        cout << "| " << setw(12) << left << St_DataLogtransfe.thisUser;
    }

public:
    static void Printheader()
    {
        vector<clsBankClient::St_DataLogtransfer>logs = clsBankClient::LoadDataToVector();
        string  Subject = "\t List Transfer  Screen ";
        string  SusbTitle = "\t [ " + to_string(logs.size()) + " ] " + " Users(U)";
        clsScreen::_DrawScreenHeader(Subject, SusbTitle);
        cout << "\t\n================================================================================================================" << endl;
        cout << "| " << setw(25) << left << "Data & Time";
        cout << "| " << setw(12) << left << "S.Acct";
        cout << "| " << setw(12) << left << "d.Acct";
        cout << "| " << setw(10) << left << "Amount";
        cout << "| " << setw(15) << left << "s.Balance";
        cout << "| " << setw(15) << left << "d.Balance";
        cout << "| " << setw(12) << left << "User";
        cout << "\t\n===============================================================================================================" << endl;

        if (logs.empty())
            cout << "\t\t\t\tNo transfers Available In the System!";

        else
            for (clsBankClient::St_DataLogtransfer& U : logs)
            {

                PrintDate(U);
                cout << endl;
            }

        cout << "\t\n================================================================================================================" << endl;

    }


};

