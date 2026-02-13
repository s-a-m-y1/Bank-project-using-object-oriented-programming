#include<iostream>
#include"clsDate.h"
#pragma once
#include"clsUser.h"
// Current is an object of clsUser
// It loads the data of the user and client using the FindUser function
clsDate Date = clsDate();
clsUser Current = clsUser::FindUser("", "");
