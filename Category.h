#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>
#include "Transaction.h" 
using namespace std;

class Category {

private:
		int categoryID;
		string name;
		double budget;
		double spending;
		Transaction* transactions;
	public:
		void addTransaction(Transaction* transaction);
		void deleteTransaction(Transaction* transaction);
		void updateBudget();};

#endif 
