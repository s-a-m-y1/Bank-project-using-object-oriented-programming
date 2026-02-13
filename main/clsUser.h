#include<iostream>
#include<vector>
#pragma once
#include<fstream>
#include"clsString.h"
#include"clsPerson.h"
#include<string>
using namespace std;
class clsUser :public clsPerson
{

private:
    //__________dateMembers________________//
    enum _EnMode { Eempty = 0, Eupdate = 1, EAdd = 2 };
    _EnMode _Mode;
    string _UserName = "";//This is "" Garbge value
    string _Password = "";
    int _Permisson = 0;
    bool _MarkForDelete = false;
    //_____________Constractor___________Empty?____//

    static clsUser _ConvertEmptyToUserObject()
    {

        return clsUser(_EnMode::Eempty, "", "", "", "", "", "", 0);

    }

    string _prepareLoginRecordingLine()
    {
        string Line = "";
        Line += _UserName + " - " + _Password + " - " + to_string(_Permisson) + " - DateTime : " + clsDate::GetSystemDateTimeString();
        return Line;
    }

    static clsUser _ConvertLineToUserObject(string Line, string Sepretor = "/")
    {

        vector<string> VUser = clsString::Split(Line, Sepretor);
        if (VUser.size() >= 7)
        {
            return clsUser(_EnMode::Eupdate, VUser[0], VUser[1], VUser[2], VUser[3], VUser[4], VUser[5], stoi(VUser[6]));
        }
        return _ConvertEmptyToUserObject();

    }

    string _LineToSend(clsUser User, string Sepretor = "/")
    {
        string Line = "";
        Line += User.GetFirstName() + Sepretor + User.GetlastName() + Sepretor + User.GetEmail() + Sepretor + User.GetPhone() + Sepretor + User._UserName + Sepretor + User._Password + Sepretor + to_string(User._Permisson);
        return Line;
    }

    static vector<clsUser>_LoadDateFromFile()
    {
        vector<clsUser>VDate;
        fstream Loading;
        Loading.open("Users.txt", ios::in);//;
        if (Loading.is_open())
        {
            string Line = "";
            while (getline(Loading, Line))
            {
                VDate.push_back(_ConvertLineToUserObject(Line));
            }
            Loading.close();
        }
        return VDate;
    }

    void _saveData(vector<clsUser>& Vuser)
    {
        fstream SaveNew;
        SaveNew.open("Users.txt", ios::out);
        if (SaveNew.is_open())
        {
            for (clsUser& User : Vuser)
            {
                if (User._MarkForDelete == false)
                {
                    SaveNew << _LineToSend(User) << endl;
                }
            }
            SaveNew.close();
        }

    }
    static void _AddNewUser(string LiNE)
    {
        fstream Add;
        Add.open("Users.txt", ios::out | ios::app);
        if (Add.is_open())
        {
            Add << LiNE << endl;

            Add.close();
        }
    }
    void _Adddata()
    {
        _AddNewUser(_LineToSend(*this));
    }
    void _Update()
    {
        vector<clsUser>Vuser = _LoadDateFromFile();
        for (clsUser& U : Vuser)
        {
            if (U.GetUserName() == _UserName)
            {
                U = *this;
                break;
            }
        }

        _saveData(Vuser);
    }

public:
    enum EnPermisson { P_Full = -1, P_ListClient = 1, P_AddClient = 2, P_DeleteClient = 4, P_UpdateClient = 8, P_FindClient = 16, P_Tranactions = 32, P_ManageUsers = 64 };
    bool IsEmpty()
    {
        return (_Mode == _EnMode::Eempty);
    }
    bool IsUpdatet()
    {
        return (_Mode == _EnMode::Eupdate);
    }
    void RegsterLogin()
    {
        fstream Load;
        string Line = _prepareLoginRecordingLine();
        Load.open("sessions.txt", ios::out | ios::app);
        if (Load.is_open())
        {
            Load << Line << endl;
        }
        Load.close();
    }

    clsUser(_EnMode Mode, string firstName, string LastName, string Email, string Phone, string UserName, string Password, int Permisson) :clsPerson(firstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permisson = Permisson;

    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }
    string GetUserName()
    {
        return _UserName;
    }
    void SetPassword(string Password)
    {

        _Password = Password;
    }
    string GetPassword()
    {
        return _Password;
    }
    void SetPermisson(int Per)
    {
        _Permisson = Per;
    }
    int GetPermisson()
    {
        return _Permisson;
    }


    static clsUser FindUser(string Username, string password)
    {
        fstream read;
        read.open("Users.txt", ios::in);
        if (read.is_open())
        {
            string Line = "";
            while (getline(read, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (Username == User.GetUserName() && password == User.GetPassword())
                {
                    read.close();
                    return User;
                }

            }

            read.close();
        }
        return _ConvertEmptyToUserObject();
    }

    static clsUser FindUser(string Username)
    {
        fstream read;
        read.open("Users.txt", ios::in);
        if (read.is_open())
        {
            string Line = "";
            while (getline(read, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (Username == User.GetUserName())
                {
                    read.close();
                    return User;
                }

            }

            read.close();
        }
        return _ConvertEmptyToUserObject();
    }

    bool DeleteUSer()
    {
        vector<clsUser > VUser = _LoadDateFromFile();
        for (clsUser& U : VUser)
        {
            if (U.GetUserName() == _UserName)
            {
                U._MarkForDelete = true;

                _saveData(VUser);

                *this = _ConvertEmptyToUserObject();
                return true;
            }

        }
        return false;
    }
    enum Ensaveresult { ESaveEmptyobject = 0, EsaveSuceedad = 1, svFaildAccountNumberExists = 2 };

    Ensaveresult Save()
    {
        switch (_Mode)
        {
        case _EnMode::Eempty:
        {
            return Ensaveresult::ESaveEmptyobject;
            break;
        }
        case _EnMode::Eupdate:
        {
            _Update();
            return Ensaveresult::EsaveSuceedad;
            break;
        }
        case _EnMode::EAdd:
            if (IsUserExist(GetUserName()))
            {
                return Ensaveresult::svFaildAccountNumberExists;
            }
            else
            {
                _Adddata();
                _Mode = _EnMode::Eupdate;
                return Ensaveresult::EsaveSuceedad;
            }
            break;

        }


        return Ensaveresult::ESaveEmptyobject;


    }

    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::FindUser(UserName);//المشكله هنا 
        return (User.IsUpdatet());
    }

    static clsUser GetAddNewUserobject(string Username)
    {
        return clsUser(_EnMode::EAdd, "", "", "", "", Username, "", 0);

    }
    static vector<clsUser>GetListUsers()
    {
        return _LoadDateFromFile();

    }
    bool CheckAccessPermssion(EnPermisson Permssion)
    {
        if (this->GetPermisson() == EnPermisson::P_Full)return true; // this is full access of system  in this object  // 
        if ((Permssion & this->GetPermisson()) == Permssion) return true;//this is check is the permisson this object he vs enpermisson and this permisson this object why Equal the permssion What I will pass by
        else
            return false; //if is not Equel return false '''
    }

};