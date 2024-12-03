#ifndef INCOME_H
#define INCOME_H

#include <string>
#include "Transaction.h" // Include the base class Transaction header

using namespace std;

class Income : public Transaction {
private:
    string source;  // Source specific to Income

public:
    // Parameterized constructor for Income class
    Income(Account& account, double amount, const Date& date, const string& description, const string& source);

    // Getter for source
    string getSource() const;

    // Setter for source
    void setSource(const string& src);
};

#endif // INCOME_H
