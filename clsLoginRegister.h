#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include"Global.h"
#include"clsDate.h"
#include<fstream>
using namespace std;



class clsLoginRegister :protected clsScreen
{
private:
   static  void _PrintLoginRegisterRecordLine(clsUser:: stLoginRegister LoginRegisterRecord)
     {
         cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.Date;
         cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
         cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
         cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
    }


public:
    static void ShowLoginRegisterScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pShowRegisterLoginScree))
        {
            return;
        }
        vector<clsUser::stLoginRegister>vLoginRegisterList = clsUser::GetLoginRegisterList();


        string Title = "\t   Login Register Screen";
        string SubTitle = "\t    (" + to_string(vLoginRegisterList.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegisterList.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser::stLoginRegister  Record: vLoginRegisterList)
            {

                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;


    }
	
};

