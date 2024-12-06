#include "Income.h"

// Constructor for Income class
Income::Income(double amount, const Date& date, const string& description, const string& source)
    : Transaction(amount, date, description), source(source) {
    // The base class Transaction constructor is called here
}

// Getter for source
string Income::getSource() const {
    return source;
}

// Setter for source
void Income::setSource(const string& src) {
    source = src;
}

void Income::getTransactionDetails() const {
    cout<< "Expense Transaction ID: " << transactionID << "\n";
       cout<< "Amount: " << amount << "\n";
       cout<< "Date: " << date.getDate() << "\n";
       cout<< "Description: " << description << "\n";
       cout<< "Source: " << source<<endl;}
