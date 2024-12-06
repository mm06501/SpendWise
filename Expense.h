#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include "Transaction.h"
#include "Category.h" 

using namespace std;

class Expense : public Transaction {
private:
    Category* category;

public:
    // Parameterized constructor for Expense class
    Expense(double amount, const Date& date, const string& description, Category* category);

    // Getter for category
    Category* getCategory() const;

    // Setter for category
    void setCategory(Category* cat);
    void getTransactionDetails() const override;
};

#endif // EXPENSE_H
