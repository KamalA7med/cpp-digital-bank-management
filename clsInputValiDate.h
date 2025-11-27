#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;
class clsInputValidate
{
private:
static	bool IsTheInput_A_Number( double num)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return false;
		}
		return true;
	}
public:
	static bool IsNumberBetween(int Num, int From, int To)
	{
		return (!(Num<From || Num>To));
	}
	static bool IsNumberBetween(double Num, double From, double To)
	{
		return (!(Num<From || Num>To));
	}
	
	static int ReadIntNumber(string Message)
	{
		int Num;
		cin >> Num;
		
		while (!IsTheInput_A_Number(Num))
		{
			cout << Message;
			cin >> Num;
		}
		return Num;
	}
	static int ReadIntNumberBetween(int From, int To, string Message)
	{
		
		int Num=ReadDoubleNumber(Message);
		
		while (!IsNumberBetween(Num, From, To))
		{
			cout << Message;
			cin >> Num;
		}
		return Num;
	}
	static double ReadDoubleNumber(string Message)
	{
		double Num;

		cin >> Num;
		while (!IsTheInput_A_Number(Num))
		{
			cout << Message;
			cin >> Num;
		}
		return Num;
	}
	static double ReadDoubleNumberBetween(double From, double To, string Message)
	{

		double Num=ReadDoubleNumber( Message);
		
		while (!IsNumberBetween(Num, From, To))
		{
			cout << Message;
			cin >> Num;
		}
		return Num;
	}
	static bool IsValideDate(clsDate Date)
	{
		return (clsDate::IsValidDate(Date));
		
	}
	static bool IsDateBetween(clsDate Date
		, clsDate From, clsDate To)
	{
		if (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)
			&&
			clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
		{
			return true;
		}
		if (clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)
			&&
			clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
		{
			return true;
		}
		return false;

	}

	static string ReadString()
	{
		string Text;
		getline(cin >> ws,Text );
		return Text;
	}
	static float ReadFloatNumber()
	{
		float Num;
		cin >> Num;
		while (!IsTheInput_A_Number(Num))
		{
			cout << "\nThe Input Is Not Valid , Please Try Again :";

			cin >> Num;

		}
		return Num;
	}

};

