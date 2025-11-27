#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
using namespace std;
class clsDeleteClient:protected clsScreen
{
private:
    static  void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName;
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber;
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:
     static void DeleteClient()
    {
         if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
         {
             return;
         }
        _DrawScreenHeader("Delete Client Screen");
        string AccountNumber = "";
        cout << " PLease Enter Account Number :";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nWrong Account Number ,Please Try Again : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        char Answer = 'n';
        cout << "\nDo You want To Delete This Client(Y/N):";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nClient Was Deleted Successfully :-) ";
                
            }
            else
            {
                cout << "\nClient Was Not Deleted  :-( ";
            }


        }




    }
};

