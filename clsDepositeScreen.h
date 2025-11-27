#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
using namespace std;
class clsDepositeScreen : protected clsScreen
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
    static void  ShowDepositeScreen()
    {
        _DrawScreenHeader("Deposite Screen");
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
        double Amount = -1;
        while (Amount < 0)
        {
            cout << "\n\nEntre A Deposite Amount : ";
            Amount = clsInputValidate::ReadDoubleNumber("\n\nInValid Amount !! Please Try Again\n\nEntre A Deposite Amount :  ");
        }
         char Answer = 'n';
        cout << "\nDo You want To Deposite This Amount(Y/N):";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Client.Deposite(Amount);

            cout << "\n\nDone Successfully :-)\n\n";
            cout << Client.FullName << " Balance :" << Client.AccountBalance;

        }
        else
        {
            cout << "\n\nThe process Was Canceled ";
        }
    }
};