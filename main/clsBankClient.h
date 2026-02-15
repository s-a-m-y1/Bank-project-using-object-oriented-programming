#include<iostream>
#pragma once
#include"clsPerson.h"
#include<vector>
#include<fstream>
#include"clsInputValidate.h"
class clsBankClient :public clsPerson
{
private:
    enum EnMode { EmptyMode = 0, UpdateMode = 1, AddNewClient = 2 };
    EnMode _mode;
    string _AccountNumber = "";
    string _pinCode = "";
    float _AccountBalance = 0;
    bool  _markFordeleted = false;
    static clsBankClient _ConvartLine(string Line, string Sprator = "#//#")
    {
        vector<string >Vvector;
        Vvector = clsString::Split(Line, Sprator);
        return clsBankClient(EnMode::UpdateMode, Vvector[0], Vvector[1], Vvector[2], Vvector[3], Vvector[4], Vvector[5], stof(Vvector[6]));
    }
    static clsBankClient _ConvartEmptyLine()
    {

        return clsBankClient(EnMode::EmptyMode, "", "", "", "", "", "", 0);

    }
    static  vector<clsBankClient> _LoadClientFromFile()

    {
        vector<clsBankClient>Vclient;
        fstream Load;
        Load.open("Client.txt", ios::in);
        if (Load.is_open())
        {
            string line = "";
            while (getline(Load, line))
            {

                clsBankClient Client = _ConvartLine(line);
                Vclient.push_back(Client);
            }
            Load.close();

        }

        return Vclient;
    }
    static string LineRecord(clsBankClient& Client, string Spretor = "#//#")
    {
        string Line = "";
        Line = Client.GetFirstName() + Spretor
            + Client.GetlastName() + Spretor +
            Client.GetEmail() + Spretor +
            Client.GetPhone() + Spretor +
            Client.GetAccountNumber() + Spretor +
            Client.Getpincode() + Spretor +
            to_string(Client.GetAccountBalance());

        return Line;
    }
    static void _SaveDataToFile(vector<clsBankClient>& Pass)
    {
        fstream Write;
        Write.open("Client.txt", ios::out);
        if (Write.is_open())
        {

            for (clsBankClient& C : Pass)
            {
                if (C.GetmarkFordeleted() == false)
                {

                    Write << LineRecord(C) << endl;
                }

            }

            Write.close();
        }
    }
    void _update()
    {
        vector<clsBankClient>_Vcient = _LoadClientFromFile();
        for (clsBankClient& C : _Vcient)
        {
            if (C.GetAccountNumber() == _AccountNumber)
            {
                C = *this;
                break;
            }
        }
        _SaveDataToFile(_Vcient);
    }
    void _AddDataLineToFile(string Line)
    {
        // clsBankClient client 
        fstream Pass;
        Pass.open("Client.txt", ios::app | ios::out);
        if (Pass.is_open())
        {
            Pass << Line << endl;
            Pass.close();
        }

    }
    void _AddNew()
    {
        _AddDataLineToFile(LineRecord(*this));
    }
public:
    clsBankClient(EnMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _mode = Mode;
        _AccountNumber = AccountNumber;
        _pinCode = PinCode;
        _AccountBalance = AccountBalance;
    }
    void SetAccountBalance(float Balance)
    {
        _AccountBalance = Balance;

    }
    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    string GetAccountNumber()
    {
        return _AccountNumber;
    }
    void SetPinCode(string Pin)
    {
        _pinCode = Pin;
    }
    string Getpincode()
    {
        return _pinCode;
    }
    bool GetmarkFordeleted()
    {
        return _markFordeleted;
    }
    bool IsUpdateMode()
    {
        return (_mode == EnMode::UpdateMode);

    }

    bool Delete()
    {
        vector<clsBankClient >Client = _LoadClientFromFile();
        for (clsBankClient& C : Client)
        {
            if (C.GetAccountNumber() == _AccountNumber)
            {
                C._markFordeleted = true;
                _SaveDataToFile(Client);

                *this = _ConvartEmptyLine();
                return true;
            }
        }
        return false;
    }


    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Client.txt", ios::in);//Read 
        if (MyFile.is_open())
        {

            string Line = "";
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvartLine(Line);
                if (AccountNumber == Client._AccountNumber)
                {
                    return Client;
                }
            }
            MyFile.close();
        }
        MyFile.close();
        return _ConvartEmptyLine();

    }
    static clsBankClient Find(string AccountNumber, string PinDode)
    {
        fstream MyFile;
        MyFile.open("Client.txt", ios::in);//Read 
        if (MyFile.is_open())
        {

            string Line = "";
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvartLine(Line);
                if (AccountNumber == Client._AccountNumber && PinDode == Client._pinCode)
                {
                    return Client;
                }

            }
            MyFile.close();
        }
        MyFile.close();
        return _ConvartEmptyLine();

    }
    enum Ensaveresult { ESaveEmptyobject = 0, EsaveSuceedad = 1, svFaildAccountNumberExists = 2 };
    Ensaveresult Save()
    {
        switch (_mode)
        {
        case EnMode::EmptyMode:
            return Ensaveresult::ESaveEmptyobject;
            break;
        case EnMode::UpdateMode:
            _update();
            return Ensaveresult::EsaveSuceedad;
            break;
        case EnMode::AddNewClient:
            if (isClientExist(_AccountNumber))
            {
                return Ensaveresult::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                _mode = EnMode::UpdateMode;
                return Ensaveresult::EsaveSuceedad;
            }


        }

    }

    static  bool isClientExist(string& AccountNumber)
    {
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        return(Client.IsUpdateMode());

    }
    static  clsBankClient Add(string AcountNumber)
    {
        return  clsBankClient(EnMode::AddNewClient, "", "", "", "", AcountNumber, "", 0);
    }

    static vector<clsBankClient>GetclientList()
    {

        return _LoadClientFromFile();
    }
    static double GetTotalBalances()
    {

        double TotalBalances = 0;
        vector<clsBankClient>VClient = clsBankClient::GetclientList();
        for (clsBankClient C : VClient)
        {
            TotalBalances += C._AccountBalance;

        }
        return TotalBalances;
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {

            return false;
        }
        else

            _AccountBalance -= Amount;
        Save();
        return true;



    }

    bool IsTransfer(float Amount , clsBankClient& Client)
    {
        if (Amount > _AccountBalance || Amount <= 0 || this->GetAccountNumber() == Client.GetAccountNumber())
        {
            return false;
        }
        else
        
            Withdraw(Amount);
            Client.Deposit(Amount);
            return true;

   }

};