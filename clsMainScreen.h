#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValiDate.h"
#include"clsScreen.h"
#include"clsClientsListScreen.h"
#include"clsAddNewClient.h"
#include"clsDeleteClient.h"
#include"clsUpdateClient.h"
#include"clsFindClient.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsers.h"
#include"Global.h"
#include"clsUser.h"
#include"clsLoginScreen.h"
#include"clsLoginRegister.h"
#include"clsExchangeCurrencyMenuScreen.h"
using namespace std;
class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenuOptions
	{
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7,eLoginRegister=8,eCurrencyExchange=9, eExit = 10

	};
    static short _ReadMainMenueOption()
    {

        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        return  clsInputValidate::ReadIntNumberBetween(1, 10, "Invalid Choice \n \nEnter Your Choice From [1] To [8] : ");
   }
    static  void _GoBackToMainMenu()
    {
        
        cout << " \n\nPress Any Key To Back To The Main Menu......\n\n ";
        system("pause>0");
        ShowMainMenueScreen();
     }
    static void _ShowExhangeCurrencyMenuScreen()
    {
        clsExchangeCurrencyMenuScreen::ShowExchangeMenuScreen();
    }
    static  void _ShowAllClientsScreen()
    {
        clsClientsListScreen::ShowClientsList();
    }
     static void _ShowAddClientsScreen()
    {
         clsAddNewClient::ShowAddNewClientScreen();
    }
     static void _ShowDeleteClientsScreen()
     {
         clsDeleteClient::DeleteClient();
     }
     static void _ShowLoginregisterScreen()
     {
         clsLoginRegister::ShowLoginRegisterScreen();
    }
     static void _ShowFindClientsScreen()
     {
         clsFindClient::FindClient();
     }
     static void _ShowUpdateClientsScreen()
     {
         clsUpdateClient::UpdateClient();
     }
     static void _ShowTransactionsMenueScreen()
     {
         clsTransactionsScreen::ShowTransactionsMenue();
     }
     static void _ShowManageUsersScreen()
     {
         clsManageUsers::ShowManageUsersScreen();
     }
     static void  _LogOut()
     {
         CurrentUser=clsUser::Find("", "");
         
     }

    static void   _PerfromMainMenueOption(enMainMenuOptions Choice)
    {
        system("cls");
        switch (Choice)
        {
        case enMainMenuOptions::eListClients:
        {
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
        {
         _ShowAddClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eDeleteClient:
        {
            _ShowDeleteClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eFindClient:
        {
            _ShowFindClientsScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOptions::eUpdateClient:
        {
            _ShowUpdateClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eShowTransactionsMenue:
        {
            _ShowTransactionsMenueScreen();
            ShowMainMenueScreen();
            break;
        }
        case enMainMenuOptions::eManageUsers:
        {
            _ShowManageUsersScreen();
            ShowMainMenueScreen();
            break;
        }
        case enMainMenuOptions::eLoginRegister:
        {
            _ShowLoginregisterScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eCurrencyExchange:
        {
            _ShowExhangeCurrencyMenuScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eExit:
        {
            _LogOut();
            
            break;
        }
        }
  }

public:
    static void ShowMainMenueScreen()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenuOptions)_ReadMainMenueOption());
    }


};

