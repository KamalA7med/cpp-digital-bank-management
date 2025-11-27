#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
class clsTransferScreen:protected clsScreen
{

private:
    static void _PrintShortCard(clsBankClient Client)
    {
        cout << "\n\n____________________________________";
        cout << "\nName           : " << Client.FullName;
        cout << "\nAccount Number : " << Client.AccountNumber;
        cout << "\nBalance        : " << Client.AccountBalance;
        cout << "\n____________________________________"<<endl;
 }
    static clsBankClient _FindClient()
    {
        string AccountNumber = "";
        
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nWrong Account Number ,Please Try Again : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintShortCard(Client);
        return Client;
    }
public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("TransferScreen");
        cout << "\n PLease Enter Account Number To Transfer From :";
        clsBankClient SourceClient = _FindClient();
        cout << "\n PLease Enter Account Number To Transfer To :";
        
        clsBankClient DestiantionClient = _FindClient();
        while (SourceClient.AccountNumber == DestiantionClient.AccountNumber)
        {
            cout << "You Can Not Transfer Money To The Same Account!! Enter Another Account Number \n ";
            cout << "\n PLease Enter Account Number To Transfer To :";

             DestiantionClient = _FindClient();
        }
        float Amount;

        do
        {
            cout << "\nPlease Enter Amount Less Than [" << SourceClient.AccountBalance << "] :";
            cin >> Amount;
        } while (Amount>SourceClient.AccountBalance||Amount<0);
        char Answer;
        cout << "\n Are You sure (Y/N) :";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            if(SourceClient.Transfer(Amount,DestiantionClient))
            { 
                cout << "\n\nThe Process Done Successfully :-(";
                _PrintShortCard(SourceClient);
                _PrintShortCard(DestiantionClient);
            }
        }
        else
        {
            cout << "\n\nThe Process Was Canceled ";
        }
	}
};

