#ifndef INCOME_H
#define INCOME_H

#include <string>
#include "Transaction.h" 

using namespace std;

class Income : public Transaction {
private:
    string source; 

public:
    // Parameterized constructor for Income class
    Income(double amount, const Date& date, const string& description, const string& source);
    string getSource() const;
    void setSource(const string& src);
    void getTransactionDetails() const override;

};

#endif // INCOME_H
