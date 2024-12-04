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
	public:
		Transaction();
		Transaction(double amount, const Date& date, const string& description);
		virtual void getTransactionDetails() const = 0;
    	int getTransactionID() const;
    	void setTransactionID(int id);
    	double getAmount() const;
    	void setAmount(double amount);
    	Date getDate() const;
    	void setDate(const Date& date);
		void setDescription(const std::string& description);
		string getDescription();
};

#endif
