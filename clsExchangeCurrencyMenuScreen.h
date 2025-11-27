#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValiDate.h"
#include"clsShowListOfCurrencies.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRate.h"
#include"clsShowEchangeCurrencyScreen.h";
using namespace std;


class clsExchangeCurrencyMenuScreen :protected clsScreen
{
private:
   static short _ReadMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Option = clsInputValidate::ReadIntNumberBetween(1, 5, "Invalid Choice!!\n\nChoose what do you want to do? [1 to 5]?");
        return Option;
    }
    enum enCurrencyExchangeOption
    {
        elistOfCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5
    };
    static void _BackToExchangeCurrenciesMenue()
    {
        cout << " \n\nPress Any Key To Back To The Currencies Menu......\n\n ";
        system("pause>0");
        ShowExchangeMenuScreen();
    }
    static void _ShowListOfCurrencies()
    {
        clsShowListOfCurrencies::ShowListOfCurrencies();
    }
    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrency::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateCurrencyRateScreen()
    {
        clsUpdateCurrencyRate::ShowUpdateCurrencyRateScrren();
    }
    static void  _ShowCurrencyCalculatorScreen()
    {
        clsShowEchangeCurrencyScreen::ShowEchangeCurrencyScreen();
            
        
    }
    static void _PerformExchangeCurrenciesMenuChoice(enCurrencyExchangeOption Option)
    {
        system("cls");
        switch (Option)
        {
        case clsExchangeCurrencyMenuScreen::elistOfCurrencies:
        {
            _ShowListOfCurrencies();
            _BackToExchangeCurrenciesMenue();
            break;
        }

        case clsExchangeCurrencyMenuScreen::eFindCurrency:
        {
            _ShowFindCurrencyScreen();
            _BackToExchangeCurrenciesMenue();
            break;
        }
        case clsExchangeCurrencyMenuScreen::eUpdateRate:
        {
            _ShowUpdateCurrencyRateScreen();
            _BackToExchangeCurrenciesMenue();
            break;
        }
        case clsExchangeCurrencyMenuScreen::eCurrencyCalculator:
        {
            _ShowCurrencyCalculatorScreen();
            _BackToExchangeCurrenciesMenue();
            break;
        }
        default:
        {

        }

        }
    }
public:

    static void ShowExchangeMenuScreen()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformExchangeCurrenciesMenuChoice((enCurrencyExchangeOption)_ReadMenuOption());
    }
};