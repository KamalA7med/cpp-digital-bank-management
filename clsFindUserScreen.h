#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
using namespace std;
class clsFindUserScreen :protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {


        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName;
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\Permissions  : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("Find User Screeen");
        string UserName = "";
        cout << "Please Enter The User Name :";
        cin >> UserName;
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\n\nUser Name Was Not Found !! Please Try Again \n\nPlease Enter The Account Number :";
            cin >> UserName;
        }
        clsUser User = clsUser::Find(UserName);
        if (User.IsEmpty())
        {
            cout << "\n\nThe User Was Not Found  :-( ";
        }
        else
        {
            cout << "\n\nThe User Was Found  :-)\n ";
            _PrintUser(User);
        }
    }
};

