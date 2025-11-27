#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
using namespace std;

class clsDeleteUser:protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {


        cout << "\nClient Card:";
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
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("Delete User Screen");
        string AccountNumber = "";
        cout << " PLease Enter UserName :";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(AccountNumber))
        {
            cout << "\nWrong UserName ,Please Try Again : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::Find(AccountNumber);
        _PrintUser(User);

        char Answer = 'n';
        cout << "\nDo You want To Delete This Client(Y/N):";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser Was Deleted Successfully :-) ";

            }
            else
            {
                cout <<"User Was Not Deleted : -(";
            }


        }
        else
        {
            cout << "The Proccess Was Canceled ";
        }




    }
};

