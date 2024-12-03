#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include "Transaction.h"
#include "Category.h"  // Assuming Category is a class representing categories of expenses

using namespace std;

class Expense : public Transaction {
private:
    Category* category;  // Category specific to Expense

public:
    // Parameterized constructor for Expense class
    Expense(Account& account, double amount, const Date& date, const string& description, Category* category);

    // Getter for category
    Category* getCategory() const;

    // Setter for category
    void setCategory(Category* cat);
};

#endif // EXPENSE_H
