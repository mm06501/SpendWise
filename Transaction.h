#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"  // Ensure Date.h is correctly included
#include "Category.h"  // Ensure Category.h is correctly included


class Transaction {
protected:
    static int count;
    int transactionID;
    double amount;
    Date date;
    std::string description;

public:
    Transaction();
    Transaction(double amount, const Date& date, const std::string& description);
    virtual void getTransactionDetails() const = 0;  // Pure virtual function to be overridden by derived classes
    
    int getTransactionID() const;
    void setTransactionID(int id);
    double getAmount() const;
    void setAmount(double amount);
    Date getDate() const;
    void setDate(const Date& date);
    void setDescription(const std::string& description);
    std::string getDescription();
};

#endif
