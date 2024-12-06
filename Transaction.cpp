#include "Transaction.h"

// Static member initialization
int Transaction::count = 0;


Transaction::Transaction(){}

Transaction::Transaction(double amount, const Date& date, const string& description)
    : amount(amount), date(date), description(description), transactionID(count++) {
}


int Transaction::getTransactionID() const {
    return transactionID;
}

void Transaction::setTransactionID(int id) {
    transactionID = id;
}

double Transaction::getAmount() const {
    return amount;
}

void Transaction::setAmount(double amount) {
    this->amount = amount;
}


Date Transaction::getDate() const {
    return date;
}

void Transaction::setDate(const Date& date) {
    this->date = date;
}

void Transaction::setDescription(const std::string& description) {
    this->description = description;
}

string Transaction::getDescription(){
    return description;
}




//bring write transaction into account