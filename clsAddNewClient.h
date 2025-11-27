#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
using namespace std;

class clsAddNewClient :protected clsScreen
{
private:
  static  void _Print(clsBankClient Client)
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

public:
    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        _DrawScreenHeader("Add Client Screen");
        cout << " PLease Enter Account Number :";
        string AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "The Account Number is already Used \n\nPlease Enter New Account NUmber : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::AddNewClient(AccountNumber);
        _ReadClientInfo(NewClient);
        clsBankClient::enSaveResult  SaveResult = NewClient.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::SaveFailed:
        {
            cout << "\n Error Data Was Not Saved -(";
            break;
        }
        case clsBankClient::enSaveResult::SaveSuccessed:
        {
            cout << "\n Data Was Saved Succesfully  -)";
            _Print(NewClient);
            break;
        }
        case clsBankClient::enSaveResult::SaveFailedAccountNumberExists:
        {
            cout << "\n Account NUmber Is Already used -(";
            break;
        }

        }
    }
};