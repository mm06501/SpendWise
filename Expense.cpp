#include "Expense.h"

// Constructor for Expense class
Expense::Expense(double amount, const Date& date, const string& description, Category* category)
    : Transaction(amount, date, description), category(category) {
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

#include "Expense.h"
#include <sstream>

// Parameterized constructor for Expense class
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

// Overriding getTransactionDetails from the base class (Transaction)
void Expense::getTransactionDetails() const {
    cout<< "Expense Transaction ID: " << transactionID << "\n";
       cout<< "Amount: " << amount << "\n";
       cout<< "Date: " << date.getDate() << "\n";
       cout<< "Description: " << description << "\n";
       cout<< "Category: " << (category ? category->getName() : "Unknown")<<endl;}

