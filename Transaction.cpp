#include <iostream>
#include <string>
#include "Transaction.h"

int Transaction::count = 1;

Transaction::Transaction(){}
Transaction::Transaction(double amount, const Date& date, const string& description, Category& category)
        : amount(amount),  date(date), description(description){
            transactionID = count;
            count++;
        }

    string Transaction::getTransactionDetails() {

    }
    void Transaction::displayTransactionDetails(){}
