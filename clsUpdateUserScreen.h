#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
using namespace std;
class clsUpdateUserScreen:protected clsScreen
{
private:

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission: ";
		User.Permissions = _ReadPermissionsToSet();
	}
	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'Y';
		cout << "Do You Want To give Him Full Access (Y/N) : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			return -1;

		}
		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{


			Permissions += clsUser::enPermissions::pListOfClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}
		return Permissions;

	}

	static void _PrintUser(clsUser User)
	{


		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName;
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUserName    : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\Permissions  : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:
	static void  ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");
		string UserName = "";
		cout << " PLease Enter User Name :";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nWrong User Name ,Please Try Again : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);
		char Answer = 'n';
		cout << "\nDo You want To Update This User(Y/N):";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			_ReadUserInfo(User);
			clsUser::enSaveResults SaveResult = User.Save();
			switch (SaveResult)
			{
			case clsUser::enSaveResults::svFaildUserExists:
			{
				cout << "\n Error Data Was Not Saved -(";
			}
			case clsUser::enSaveResults::svSucceeded:
			{
				cout << "\n Data Was Saved Succesfully  -)";
				_PrintUser(User);
			}

			}
		}
		else
		{
			cout << "\nThe Proccess Was Canceled";
		}

	}
};

