#include "Income.h"

// Constructor for Income class
Income::Income(Account& account, double amount, const Date& date, const string& description, const string& source)
    : Transaction(account, amount, date, description), source(source) {
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
