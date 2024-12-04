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
		User* user;
		double balance;
		Budget* budget;
		Income* income;
		Expense* expense;
		static int generateUniqueAccountNumber();
		static bool accountExists(int accountNumber);
		void writeAccountToFile();
	public:
		Account();
		Account(int accNum, double startingBalance, Budget* budget);
		Account(double startingBalance, Budget* budget);
		void addTransaction(Expense* expense);
		void addTransaction(Income* income);
		void withdraw(Expense* expense);
		void deposit(Income* income);
		void viewStatement() const;
		double getBalance() const;
		void updateBalance(double newBalance);
		int getAccountNumber() const;
		};

#endif 
