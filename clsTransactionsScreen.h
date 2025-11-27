#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
#include"clsDepositeScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;
class clsTransactionsScreen:protected clsScreen
{
private:
    enum enTransactionsMenueOptions
    {
        eDeposite = 1,eWithdraw=2,eTotalBalance=3,eTransfer=4,eTransferLog=5,eMainMenu=6

    };
    static short ReadTransactionsMenueOption()
    {
        cout << "\t\t\t\tPlease Entre Your Choice Between [1] to [4] :";
       return  clsInputValidate::ReadIntNumberBetween(1, 6,"\n\t\t\t\tInValid Choice Please Try Again \n\n\t\t\t\tPlease Entre Your Choice Between [1] to [4] :");
        
    }
    static void _ShowDepositeScreen()
    {
        clsDepositeScreen::ShowDepositeScreen();
       
   }
    

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }
    static void _ShowTotalBalanceScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }
    static void _GoBackToTrancactionsMenue()
    {
        cout << " \n\nPress Any Key To Back To The Transactions Menu......\n\n ";
        system("pause.0");
        system("cls");
        ShowTransactionsMenue();
    }
    static void  _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        system("cls");
                    switch (TransactionsMenueOption)
        {
        case clsTransactionsScreen::eDeposite:
        {
            _ShowDepositeScreen();
            _GoBackToTrancactionsMenue();
            break;
        }
            
        case clsTransactionsScreen::eWithdraw:
        {
            _ShowWithdrawScreen();
            _GoBackToTrancactionsMenue();
            break;
        }
        case clsTransactionsScreen::eTotalBalance:
        {
            _ShowTotalBalanceScreen();
            _GoBackToTrancactionsMenue();
            break;
        }
        case clsTransactionsScreen::eTransfer:
        {
            _ShowTransferScreen();
            _GoBackToTrancactionsMenue();
            break;
        }
        case clsTransactionsScreen::eTransferLog:
        {
            _ShowTransferLogScreen();
            _GoBackToTrancactionsMenue();
            break;
        }
        case clsTransactionsScreen::eMainMenu:
        {
            
        }
        }
   }
public:
    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
        {
            system("pause");
            return;
        }

        
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer History.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};

