#pragma once
#include "clsPerson.h"
#include"clsBankClient.h"
#include<iomanip>
#include <string>

class clsClientsListScreen:protected clsScreen
{
private:
     static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << "\t| " << setw(15) << left << Client.AccountNumber;
        cout << "| " << setw(20) << left << Client.FullName;
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }
public :
     static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListOfClients))
         {
             return;
         }
        vector<clsBankClient>vClients = clsBankClient::GetClientsList();
        string Title = "Clients List Srceen";
        string SubTitle = to_string(vClients.size()) + " Client(s)";

        _DrawScreenHeader(Title,SubTitle);
        cout << "\n\t____________________________________________________________________";
        cout << "____________________________\n" << endl;
        cout << "\t| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n\t____________________________________________________________________";
        cout << "____________________________\n" << endl;
        if (vClients.size() == 0) cout << "\t\t\t\tNo Clients Available In the System!";
        else for (clsBankClient Client : vClients)
        {
            _PrintClientRecordLine(Client);
            cout << endl;
        }
        cout << "\n\t____________________________________________________________________";
        cout << "____________________________\n" << endl;

    }
};

