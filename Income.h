#ifndef INCOME_H
#define INCOME_H
#include <string>
#include "Transaction.h" // Assuming Income inherits or uses Transaction properties

using namespace std;

class Income: public Transaction {
private:
    string source;
    bool isRecurring;
    string transactionType;

public:
    void updateIncome();
    void deleteIncome();
};

#endif 