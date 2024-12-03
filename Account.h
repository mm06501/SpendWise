#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include "User.h"
#include "Expense.h"
#include "Income.h"
#include "Category.h"
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
		User& user;
		double balance;
		Budget* budget;
		Transaction* transactions;
		static int generateUniqueAccountNumber();
		static bool accountExists(int accountNumber);
		void writeAccountToFile();
	public:
		Account();
		Account(int accountNumber, double initialBudget, double startingBalance);
		Account(double initialBudget, double startingBalance);
		void deposit(double amount, string description, Date date, string transactionType, string source);
		void withdraw(double amount, string description, Date date, string transactionType, Category& category);
		void viewStatement() const;
		double getBalance() const;
		int getAccountNumber() const;
		};

#endif 
