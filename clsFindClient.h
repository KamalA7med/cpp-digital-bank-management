#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
using namespace std;
class clsFindClient: protected clsScreen
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
public :
    static void FindClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        _DrawScreenHeader("Find Client Screeen");
        string AccountNumber = "";
        cout << "Please Enter The Account Number :";
        cin >> AccountNumber;
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n\nAccount Number Was Not Found !! Please Try Again \n\nPlease Enter The Account Number :";
            cin >> AccountNumber;
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        if (Client.IsEmpty())
        {
            cout << "\n\nThe Client Was Not Found  :-( ";
        }
        else
        {
            cout << "\n\nThe Client Was Found  :-)\n ";
            _PrintClient(Client);
        }
    }
};

