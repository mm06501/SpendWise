#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include "Transaction.h"
#include "Category.h"
using namespace std;


class Expense:public Transaction {
    string transactionType;
    Category* category;
    bool isRecurring;

public:
    void updateExpense();
    void deleteExpense();
};

#endif
