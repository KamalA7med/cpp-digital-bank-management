#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include"Global.h"
#include"clsDate.h"
#include<fstream>
using namespace std;



class clsLoginScreen :protected clsScreen
{
private:
	

	
	static bool _Login()
	{
		bool LoginFailed = false;
		string UserName = "";
		string Password = "";
		short NumberOfTries = 3;
		do
		{
			if (LoginFailed)
			{
				cout << "\n\nInvalid UserName Or Password !! Please Try Again\n";
				cout << "You Have " << NumberOfTries << " Trails To Login\n";
				if (NumberOfTries == 0)
				{
					cout << "You Are Blocked After 3 Trials  :-(\n";
					
					return false;
				}
			}
			cout << "\nUserName : ";
			cin >> UserName;
			cout << "Password : ";
			cin >> Password;
			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.IsEmpty();
			
			NumberOfTries--;
			 
		} while (LoginFailed);

		CurrentUser.RegisterLogin();

			clsMainScreen::ShowMainMenueScreen();

			return true;
		
		
		
	};



public:
	static bool ShowLoginScreen()
	{
		
		system("cls");
		_DrawScreenHeader("LoginScreen");
	return _Login();
		
	}
};

