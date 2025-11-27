#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsPerson.h"
#include"clsString.h"
#include"clsDate.h"
#include"Global.h"
using namespace std;


class clsBankClient:public clsPerson
{
private:
	enum enMode
	{
		EmptyMode=0,UpdateMode=1,AddNewMode=2

	};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete=false;
	static clsBankClient _ConvertLineToObject(string Line)
	{
		vector<string> vClient = clsString::Split(Line,"#//#");
		return clsBankClient(enMode::UpdateMode,vClient[0],vClient[1],vClient[2],vClient[3],vClient[4],vClient[5],stoi(vClient[6]));
	}
	struct stTranferRecord;
	static stTranferRecord _ConvertLineToTransferRecord( string Line,string Sep ="#//#")
	{
		vector<string>vTransferLine = clsString::Split(Line,Sep);
		stTranferRecord TransferRecord;
		TransferRecord.Date = vTransferLine[0];
		TransferRecord.SourceClient = vTransferLine[1];
		TransferRecord.DestinationClient = vTransferLine[2];
		TransferRecord.Amount = stof(vTransferLine[3]);
		TransferRecord.SourceClientBalance = stof(vTransferLine[4]);
		TransferRecord.DestinationClientBalance = stof(vTransferLine[5]);
		TransferRecord.UserName = vTransferLine[6];
		return TransferRecord;
	}
	 static clsBankClient GetEmptyObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	 string _prepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string Sep="#//#")
	 {
		 string Line = "";
		 Line += clsDate::GetSystemDataTimeString() + Sep;
		 Line += AccountNumber + Sep;
		 Line += DestinationClient.AccountNumber + Sep;
		 Line += to_string(Amount) + Sep;
		 Line += to_string(AccountBalance) + Sep;
		 Line += to_string(DestinationClient.AccountBalance) + Sep;
		 Line += CurrentUser.UserName;

			 return Line;
	 }
	 void _SaveTransferToFile(float Amount,clsBankClient DestinationClient)
	 {
		 string DataLine = _prepareTransferLogRecord(Amount,DestinationClient);
		 fstream Myfile;
		 Myfile.open("TransferHistory.txt", ios::out|ios::app);
		 if (Myfile.is_open())
		 {
			 
			 Myfile << DataLine << endl;
			 Myfile.close();
		 }

	 }
	static vector<clsBankClient> _LoadDataFromFile()
	 {
		 vector<clsBankClient> vClients;
		 fstream Myfile;
		 Myfile.open("Clients.txt", ios::in);
		 if (Myfile.is_open())
		 {
			 string Line;
			 while (getline(Myfile, Line))
			 {
				 clsBankClient Client = _ConvertLineToObject(Line);
				 vClients.push_back(Client);
			 }
			 Myfile.close();
		 }

		 return vClients;
	 }
	static string _CovertObjectToLine(clsBankClient Client,string Sep="#//#")
	{
		string Line = "";
		Line += Client.FirstName + Sep;
		Line += Client.LastName + Sep;
		Line += Client.Email + Sep;
		Line += Client.Phone+Sep;
		Line += Client.AccountNumber + Sep;
		Line += Client.PinCode + Sep;
		Line += to_string(Client.AccountBalance);
		return Line;
	}
	
	
	void _SaveClientsDataToFile(vector<clsBankClient>&vClients)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::out);
		string DataLine;
		if (Myfile.is_open())
		{
			
			for (clsBankClient& Client : vClients)
			{
				if (Client.MarkedForDelete() == false)
				{
					DataLine = _CovertObjectToLine(Client);

					Myfile << DataLine << endl;

				}
				
				
			}

			Myfile.close();
		}


	}
	 void _Update()
	 {
		 vector<clsBankClient> vClients = _LoadDataFromFile();
		 for (clsBankClient& Client : vClients)
		 {
			 if (Client.AccountNumber == this->AccountNumber)
			 {
				 Client = *this;
				 break;
			 }

		 }
		 _SaveClientsDataToFile(vClients);
	 }
	 void  _AddNewLine(string Line)
	 {
		 fstream MyFile;

		 MyFile.open("Clients.txt", ios::out | ios::app);
		 if (MyFile.is_open())
		 {
			 MyFile << Line << endl;
			 MyFile.close();
			}

	 }
	void _AddNew()
	 {
		_AddNewLine(  _CovertObjectToLine(*this));

	 }

public:
	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		:
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
		_PinCode = PinCode;


	}
	struct stTranferRecord
	{
		string Date;
		string SourceClient;
		string DestinationClient;
		float Amount;
		float SourceClientBalance;
		float DestinationClientBalance;
		string UserName;
	};
	bool IsEmpty()
	{
		return (enMode::EmptyMode==_Mode);
	}
static	vector<stTranferRecord>GetTranserHistory()
	{
		vector<stTranferRecord> vTransferHistory;
		fstream  Myfile;
		Myfile.open("TransferHistory.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			stTranferRecord Record;
			while (getline(Myfile, Line))
			{
				Record = _ConvertLineToTransferRecord(Line);
				vTransferHistory.push_back(Record);
			}


			Myfile.close();
		}
		return vTransferHistory;
	}
	
	

	
	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber)) string AccountNumber;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;

	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
	bool MarkedForDelete()
	{
		return _MarkForDelete;
	}
	
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;

	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	



	static clsBankClient Find(string AccountNumber)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			
			while (getline(Myfile, Line))
			{
				clsBankClient Client = _ConvertLineToObject(Line);
				if (Client.AccountNumber == AccountNumber)
				{
					Myfile.close();
					return Client;


				}

			}
			Myfile.close();
		}
		return GetEmptyObject();
	}

	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;

			while (getline(Myfile, Line))
			{
				clsBankClient Client = _ConvertLineToObject(Line);
				if (Client.AccountNumber == AccountNumber
					&&
					Client.PinCode==PinCode)
				{
					Myfile.close();
					return Client;

				}

			}
			Myfile.close();
		}
		return GetEmptyObject();
	}

	static  bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}
	enum enSaveResult {SaveFailed=0,SaveSuccessed=1 ,SaveFailedAccountNumberExists=3};
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResult::SaveFailed;
		}
		case enMode::UpdateMode:
		{
			
			_Update();
			return enSaveResult::SaveSuccessed;
			
		}
		case enMode::AddNewMode:
		{
			if (IsClientExist(this->AccountNumber))
			{
				return enSaveResult::SaveFailedAccountNumberExists;
				
			}
			else
			{
				_AddNew();
				return enSaveResult::SaveSuccessed;

			}

			
		}


		}
	}
	 static clsBankClient AddNewClient(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	 }
	 bool Delete()
	 {
		 vector<clsBankClient> vClients = _LoadDataFromFile();
		 for (clsBankClient& client : vClients)
		 {
			 if (client.AccountNumber == AccountNumber)
			 {
				 client._MarkForDelete = true;
				 break;
			 }
			 
		 }
		 _SaveClientsDataToFile(vClients);
		 *this = GetEmptyObject();
		 return true;
	 }
	 static  vector<clsBankClient> GetClientsList()
	 {
		 return _LoadDataFromFile();
	 }
	 static double GetTotalBalance()
	 {
		 vector<clsBankClient> vClients = _LoadDataFromFile();
		 double TotalBalance = 0;
		 for  (clsBankClient & Client : vClients)
		 {
			 TotalBalance += Client.AccountBalance;
		 }
		 return TotalBalance;
	 }
	  void Deposite(double Amount)
	 {
		this->AccountBalance += Amount;
		Save();

	 }
	  void Withdraw(double Amount)
	  {
		  this->AccountBalance -= Amount;
		  Save();

	  }
	  bool Transfer(float Amount, clsBankClient & DestinationClient )
	  {
		  if (Amount > this->AccountBalance)
		  {
			  return false;
		  }
		  DestinationClient.Deposite(Amount);
		  this->Withdraw(Amount);
		  _SaveTransferToFile(Amount, DestinationClient);
		  return true;
	  }


};

