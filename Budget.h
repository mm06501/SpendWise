#ifndef BUDGET_H
#define BUDGET_H

#include <vector>
#include "Category.h" 
//#include "Date.h" 

using namespace std;

class Budget {
private:
    Category* categories;
    Date startDate;
    Date endDate;
    double totalBudget;
    double totalSpending;

public:
    double getTotalBudget();
    void setTotalBudget();
    void getTotalSpending();
    void addCategory(Category* category, double budget);
    void removeCategory(Category* category);
    void updateTotalBudget();
    void reset();
};

#endif 
