#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValiDate.h"
class clsFindCurrency :protected clsScreen
{
    enum _enFindBy
    {
        ByCode = 1,
    ByCountry = 2,

    };
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
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("Find Currency Screen ");
        string CurrencyInfo = "";
        short Choice;
        bool InValidChoice = false;
        do
        {
            if (InValidChoice)
            {
                cout << "\n\nInvalid Choice!! ";
            }
            cout << "\n\nFind By : [1] Code Or [2] Country : ";
            
            cin >> Choice;
            InValidChoice = true;
        } while (Choice<0|| Choice >2);
        switch ((_enFindBy) Choice)
        {
            
        case _enFindBy::ByCode:
        {
            cout << "\n\n Enter The Code : ";
            string Code = "";
            cin >> Code;
            while (! clsCurrency::IsCurrencyExistByCode(Code))
            {
                cout << "\n\nUser Name Was Not Found !! Please Try Again \n\nPlease Enter The Code :";
                cin >> Code;
            }
            clsCurrency Currency = clsCurrency::FindByCode(Code);
            if (Currency.IsEmpty())
            {
                cout << "\n\nthe Currency Was not Found";
            }
            else
            {
                _PrintCurrencyCard(Currency);
            }
            break;
        }
        case _enFindBy::ByCountry:
        {
            cout << "\n\n Enter The Country : ";
            string Country = "";
            cin >> Country;
            while (!clsCurrency::IsCurrencyExistByCountry(Country))
            {
                cout << "\n\nUser Name Was Not Found !! Please Try Again \n\nPlease Enter The Country :";
                cin >> Country;
            }
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            if (Currency.IsEmpty())
            {
                cout << "\n\nthe Currency Was not Found";
            }
            else
            {
                _PrintCurrencyCard(Currency);
            }
            break;
        }

        }
        
        
        
    }
};

