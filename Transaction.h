#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Date.h" 
#include "Category.h" 
using namespace std;

class Transaction {
	
	protected:
		static int count;
		int transactionID;
		double amount;
		Date date;
		string description;
		Category category;
	public:
		Transaction();
		Transaction(double amount, const Date& date, const string& description, Category& category);
		string getTransactionDetails();
		void displayTransactionDetails(); };

#endif 
