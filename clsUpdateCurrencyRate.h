#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
class clsUpdateCurrencyRate:protected clsScreen
{
private:
    static void _PrintCurrencyCard(clsCurrency Currency)
    {


        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry     : " << Currency.Country();
        cout << "\nCode        : " << Currency.CurrencyCode();
        cout << "\nName        : " << Currency.CurrencyName();
        cout << "\nRate[1$]    : " << Currency.Rate();
        cout << "\n___________________\n";

    }
public:
    static void ShowUpdateCurrencyRateScrren()
    {
        _DrawScreenHeader("Update Currency Rate ");
        string Code;
        cout << "\n\nEnter Currrency Code : ";
        cin >> Code;
        while (!clsCurrency::IsCurrencyExistByCode(Code))
        {
            cout << "\n\nUser Name Was Not Found !! Please Try Again \n\nPlease Enter The Code :";
            cin >> Code;
        }
        clsCurrency Currency = clsCurrency::FindByCode(Code);
        _PrintCurrencyCard(Currency);
        cout << "Are You Sure You Want to Update The Rate Of This Currency (Y/N) : ";
            char Answer;
            cin >> Answer;
            if (toupper(Answer) == 'Y')
            {
                cout << "\n-------------------------------------------\n";
                cout << "Enter The New Rate : ";
                float NewRate;
                cin >> NewRate;
                Currency.UpdateRate(NewRate);
                cout << "\nThe Currency Updated Succesfully : ";
                _PrintCurrencyCard(Currency);


            }
            else
            {
                cout << "\nThe Operation Was Canceled : ";
            }
        

    }



};

