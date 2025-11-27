#pragma once
#include "clsCurrency.h"
#include"clsBankClient.h"
#include<iomanip>
#include <string>
#include"clsScreen.h"
#include"clsInputValiDate.h"
class clsShowEchangeCurrencyScreen:protected clsScreen
{
private :
    static float _ReadAmount()
    {
        cout << "\nEntre Amount : ";
       float Amount= clsInputValidate::ReadFloatNumber();
       return Amount;
    }
    static void _PrintCurrencyCard(clsCurrency Currency)
    {


        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry     : " << Currency.Country();
        cout << "\nCode        : " << Currency.CurrencyCode();
        cout << "\nName        : " << Currency.CurrencyName();
        cout << "\nRate[1$]    : " << Currency.Rate();
        cout << "\n___________________\n\n";

    }
    static clsCurrency _GetCurrencyObject(string Message)
    {
        cout << Message;
        string CurrencyCode;
        cin >> CurrencyCode;
        while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode))
        {
            cout << "\n\nCurrency Code Was Not Found !! Please Try Again \n\nPlease Enter The Code :";
            cin >> CurrencyCode;
        }
        return clsCurrency::FindByCode(CurrencyCode);

    }
   static void  _PrintExchangeResults(clsCurrency SourceCurrency,clsCurrency DestinationCurrency,float Amount)
    {
        cout << "\n\nConvert From " + SourceCurrency.CurrencyCode() + " To USD : ";
        cout << "\n------------------------------";
        _PrintCurrencyCard(SourceCurrency);
     float Amount_In_USD=SourceCurrency._GetAmount_In_USD(Amount);
     cout << Amount << " " << SourceCurrency.CurrencyCode() << " = " << Amount_In_USD << " USD ";
     if (DestinationCurrency.CurrencyCode() == "USD")
     {

         return;
     }
     cout << "\n\nConvert From USD To " + DestinationCurrency.CurrencyCode() + " : ";
     cout << "\n------------------------------";
     _PrintCurrencyCard(DestinationCurrency);
      float Amount_In_DestinationCurrency = SourceCurrency._GetAmount_In_DestinationCurrency(DestinationCurrency,Amount);

     cout << Amount << " " << SourceCurrency.CurrencyCode() << " = " << Amount_In_DestinationCurrency << " " << DestinationCurrency.CurrencyCode();



    }
    
public:
    static void ShowEchangeCurrencyScreen()
    {
        
        char DoAnotherOperation = 'Y';
        while (toupper(DoAnotherOperation) == 'Y')
        {
            system("cls");
                _DrawScreenHeader("Update Currency Rate ");
            clsCurrency SourceCurrency = _GetCurrencyObject("\n\nEnter Currency 1 Code : ");
            
            clsCurrency DestinationCurrency = _GetCurrencyObject("\n\nEnter Currency 2 Code : ");
            float Amount=_ReadAmount();
            
            _PrintExchangeResults(SourceCurrency,DestinationCurrency,Amount);
            
            cout << "\n\nDo You Want To Preform Another Opertion (Y/N) : ";
            cin >> DoAnotherOperation;
            
        }

    }
};

