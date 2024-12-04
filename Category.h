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
    vector<Transaction*> transactions;  // Using a vector to store transactions

public:
    // Constructor to initialize category with ID, name, and budget
    Category(int id, const string& categoryName, double categoryBudget);

    // Getter for category name
    string getName() const;

    // Getter for category budget
    double getBudget() const;

    // Getter for category spending
    double getSpending() const;

    // Getter for category ID
    int getCategoryID() const;

    // Method to add a transaction to the category
    void addTransaction(Transaction* transaction);

    // Method to delete a transaction from the category
    void deleteTransaction(Transaction* transaction);

    // Update the spending based on transactions
    void updateBudget();

    // Method to update spending (can be called after adding/removing transactions)
    void updateSpending();
	string getName();
	
};

#endif  // CATEGORY_H
