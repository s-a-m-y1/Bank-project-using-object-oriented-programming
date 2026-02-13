#include<iostream>
#pragma once
#include"clsUtile.h"
#include"clsDate.h"
#include"clsString.h"
#include"clsInputValidate.h"
class clsPerson
{
private:
    string _FirstName = "";
    string _LastName = "";
    string _Email = "";
    string _Phone = "";
public:

    clsPerson(string FI, string  La, string Em, string Ph)
    {
        _FirstName = FI;
        _LastName = La;
        _Email = Em;
        _Phone = Ph;
    }

    void SetFirstName(string F)
    {

        _FirstName = F;
    }
    string GetFirstName()
    {
        return _FirstName;
    }
    void SetLastName(string L)
    {
        _LastName = L;
    }
    string GetlastName()
    {
        return _LastName;
    }
    void SetEmail(string E)
    {
        _Email = E;
    }
    string GetEmail()
    {
        return _Email;
    }
    void SetPhone(string P)
    {
        _Phone = P;
    }
    string GetPhone()
    {
        return _Phone;
    }
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

};