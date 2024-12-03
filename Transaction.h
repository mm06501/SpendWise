#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <fstream>
#include <iostream>
#include <iomanip> 
#include <string>
#include "Date.h" 
#include "Category.h"
#include "Account.h"

class Transaction {
	protected:
		static int count;
		int transactionID;
		double amount;
		Date date;
		string description;
		Account& account;
		void writeTransactionToFile();
	public:
		Transaction();
		Transaction(Account& account, double amount, const Date& date, const std::string& description);
		string getTransactionDetails() const;
    	int getTransactionID() const;
    	void setTransactionID(int id);
    	double getAmount() const;
    	void setAmount(double amount);
    	Date getDate() const;
    	void setDate(const Date& date);
		void setDescription(const std::string& description);
};

#endif
