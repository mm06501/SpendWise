#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include "Transaction.h" 
#include "Budget.h"

using namespace std;

class Account{
	private:
		int accountNumber;
		string accountType;
		double balance;
		string password;
		Budget* budget;
		vector<Transaction*> transactions;

	public:
		void addTransaction(Transaction* transaction);
		void deleteTransaction(Transaction* transaction);
		double getBalance();
		void deposit(double amount);
		void withdraw(double amount);
		void viewStatement();};

#endif 
