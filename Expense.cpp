#include "Expense.h"

// Constructor for Expense class
Expense::Expense(Account& account, double amount, const Date& date, const string& description, Category* category)
    : Transaction(account, amount, date, description), category(category) {
    // The base class Transaction constructor is called here
}

// Getter for category
Category* Expense::getCategory() const {
    return category;
}

// Setter for category
void Expense::setCategory(Category* cat) {
    category = cat;
}
