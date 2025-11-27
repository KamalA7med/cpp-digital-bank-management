#include <iostream>
#include"clsInputValiDate.h"
#include "clsBankClient.h"
#include"clsutility.h"
#include<iomanip>
#include"clsMainScreen.h"
using namespace std;
class clsTotalBalancesScreen:protected clsScreen
{
private:
   static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
       
        cout << "\t\t| " << setw(15) << left << Client.AccountNumber;
        cout << "| " << setw(40) << left << Client.FullName;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
public:
   static  void ShowTotalBalances()
    {
       _DrawScreenHeader("Total Balances Screen");
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t\t| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalance();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
        cout << "\t\t\t\t\t   ( " << clsutility::NumberToText(TotalBalances) << ")";
    }
};

