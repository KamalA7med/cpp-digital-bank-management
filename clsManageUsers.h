#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
#include"clsUsersListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUser.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
using namespace std;
class clsManageUsers:protected clsScreen
{
private:
    enum enManageUsersMenueOptions
    {eListOfUsers=1,eAddNewUsers=2,
        eDeleteUser=3,eUpdateUser=4,
        eFindUser=5,eMainMenu=6

    };
    static  short  _ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Option = clsInputValidate::ReadIntNumberBetween(1, 6, "Invalid Choice!!\n\nChoose what do you want to do? [1 to 6]?");
        return Option;
    }
    static void _GoBackToManageUsersMenu()
    {
        cout << " \n\nPress Any Key To Back To The Main Menu......\n\n ";
        system("pause>0");
        ShowManageUsersScreen();
    }
    static void _ShowListOfUsersScreen()
    {
        clsUsersListScreen::ShowListOfUsersScreen();
    }
    static void _ShowAddNewUsersScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
        
    }
    static void _ShowDeleteUserScreen()
    {
        clsDeleteUser::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }


    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions Choice)
    {
        system("cls");
        switch (Choice)
        {
        case clsManageUsers::eListOfUsers:
        {
            _ShowListOfUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case clsManageUsers::eAddNewUsers:
        {
            _ShowAddNewUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case clsManageUsers::eDeleteUser:
        {
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case clsManageUsers::eUpdateUser:
        {
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case clsManageUsers::eFindUser:
        {
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case clsManageUsers::eMainMenu:
        {
            //Back To Main Menu
        }
        }

  }

public:
	static void ShowManageUsersScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            system("pause");
            return;
        }
        
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
	}
};

