#include "Expense.h"

Expense::Expense(double amount, const Date& date, const string& description, Category* category)
    : Transaction(amount, date, description), category(category) {}

// Getter for category
Category* Expense::getCategory() const {
    return category;
}

// Setter for category
void Expense::setCategory(Category* cat) {
    category = cat;
}


void Expense::getTransactionDetails() const {
    cout<< "Expense Transaction ID: " << transactionID << "\n";
       cout<< "Amount: " << amount << "\n";
       cout<< "Date: " << date.getDate() << "\n";
       cout<< "Description: " << description << "\n";
       cout<< "Category: " << category->getName()<<endl;}

