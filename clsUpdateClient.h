#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
using namespace std;
class clsUpdateClient:protected clsScreen
{
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\n Please Enter New Information ";
        cout << "\n_______________________________________" << endl;
        cout << "First Name       : ";
        Client.FirstName = clsInputValidate::ReadString();
        cout << "Last Name        : ";
        Client.LastName = clsInputValidate::ReadString();
        cout << "Eamil            : ";
        Client.Email = clsInputValidate::ReadString();
        cout << "Phone            : ";
        Client.Phone = clsInputValidate::ReadString();
        cout << "PassWord         : ";
        Client.PinCode = clsInputValidate::ReadString();
        cout << "Acccount Balance : ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

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
   static void  UpdateClient()
    {
       if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
       {
           return;
       }
       _DrawScreenHeader("Update Client Screen");
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
        cout << "\nDo You want To Update This Client(Y/N):";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            _ReadClientInfo(Client);
            clsBankClient::enSaveResult SaveResult = Client.Save();
            switch (SaveResult)
            {
            case clsBankClient::enSaveResult::SaveFailed:
            {
                cout << "\n Error Data Was Not Saved -(";
            }
            case clsBankClient::enSaveResult::SaveSuccessed:
            {
                cout << "\n Data Was Saved Succesfully  -)";
                _PrintClient(Client);
            }

            }
        }

    }
};

