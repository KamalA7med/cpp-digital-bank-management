#pragma once
#include <iostream>
#include <vector>
#include"clsDate.h"
using namespace std;
class clsutility
{
public:
	static void Swap(int& X, int& Y)
	{
		int Temp;
		Temp = X;
		X = Y;
		Y = Temp;

	};
	static void Swap(double& X,double& Y)
	{
		double Temp;
		Temp = X;
		X = Y;
		Y = Temp;

	};
	static void Swap(string& X, string& Y)

	{
		string Temp;
		Temp = X;
		X = Y;
		Y = Temp;

	};
	static void SwapDates(clsDate & Date1, clsDate& Date2)
	{
		clsDate Temp;
		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;

	};
	static string Tabs(short NumOfTabs)
	{
		string Tab = "";
		for (short i = 1; i <= NumOfTabs; i++)
		{
			Tab += "\t";
		}
		return Tab;
	}
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static short RandomNumber(short From,short To)
		{
		return rand()% (To - From + 1) + From;
		}
	enum enCharType
	{
		SmallLetter = 1, CapitalLetter = 2, SpecialLetter = 3, MixChars = 5, Digit=4

	};
	static char GetRandomCharcter(enCharType CharType)
	{
		if (CharType == enCharType::MixChars)
		{
			CharType = (enCharType)RandomNumber(1, 3);
		}
		switch (CharType)
		{
		case enCharType::SmallLetter:
		{
			return char(RandomNumber(97, 122));
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
		}
		case enCharType::SpecialLetter:
		{
			return char(RandomNumber(33, 47));
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
		}
		default:
		{
			return char(RandomNumber(97, 122));
		}
		}
	}
	static string  GenerateWord(enCharType CharType, short NumOfChares)
	{
		string Word="";
		for (short i = 1; i <= NumOfChares; i++)
		{
			Word += GetRandomCharcter(CharType);
		}
		return Word;
	}
	static string Generatekey(enCharType CharType)
	{
		string key = "";
		for  (short i = 1;i<=4; i++)
		{
			key += GenerateWord(CharType, 8) + "-";
		}
		return key.substr(0,key.length()-1);
	}
	static void Generatekeys(short NumOfKeys, enCharType CharType)
	{
		for (short i = 1; i <= NumOfKeys; i++)
		{
			cout << "Key [" << i << "] : " << Generatekey(CharType) << endl;	
		}
	}
	static void ShuffleArray(int Arr[], short ArrLength)
	{
		for (short i = 0; i < ArrLength; i++)
		{
			Swap(Arr[RandomNumber(0, ArrLength-1)  ], Arr[RandomNumber(0, ArrLength-1)]);

		}
	}
	static void ShuffleArray(string Arr[], short ArrLength)
	{
		for (short i = 0; i < ArrLength; i++)
		{
			Swap(Arr[RandomNumber(0, ArrLength-1)], Arr[RandomNumber(0, ArrLength-1)]);

		}
	}
	static void FillArrayWithRandomNumbers(int Arr[], short ArrLength, int From, int To)
	{
		for (short i = 0; i < ArrLength; i++)
		{
			Arr[i] = RandomNumber(From, To);

		}

	}
	static void FillArrayWithRandomwords(string Arr[],enCharType CharType, short ArrLength,short NumOfChars)
	{
		for (short i = 0; i < ArrLength; i++)
		{
			Arr[i] = GenerateWord(CharType,NumOfChars);

		}

	}
	static void FillArrayWithRandomKeys(string Arr[], short ArrLength,  enCharType CharType)
	{
		for (short i = 0; i < ArrLength; i++)
		{
			Arr[i] = Generatekey(CharType);

		}

	}
	static string Encrypttext(string Text, short Key=2)
	{
		for  (short i = 0;  i < Text.length(); i++)
		{
			Text[i] = char((short)Text[i] + Key);

		}
		return Text;
	}
	static string Decryptext(string Text, short Key=2)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = char((short)Text[i] - Key);

		}
		return Text;
	}
	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}




};

