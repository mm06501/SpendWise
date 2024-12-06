#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include "Expense.h"
#include "Income.h"
#include "Transaction.h"
#include "Budget.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


class Account{
	private:
		int accountNumber;
		double balance;
		Budget* budget;
		Income* income;
		Expense* expense;
		static int generateUniqueAccountNumber();
		static bool accountExists(int accountNumber);
	public:
		Account();
		Account(int userID, int accNum, double startingBalance, Budget* budget);
		Account(int userID, double startingBalance, Budget* budget);
		void addTransaction(Expense* expense);
		void writeAccountToFile(int userID);
		void addTransaction(Income* income);
		void withdraw(Expense* expense);
		void deposit(Income* income);
		//void viewStatement() const;
		double getBalance() const;
		void updateBalance(double newBalance);
		int getAccountNumber() const;
		};

#endif 
