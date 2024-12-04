#ifndef BUDGET_H
#define BUDGET_H

#include <vector>
#include "Category.h"
#include "Date.h"

using namespace std;

class Budget {
private:
    vector<pair<Category*, double>> categories;  // Stores categories and their assigned budget
    Date startDate;
    Date endDate;
    double totalBudget;
    double totalSpending;

public:
    // Constructor
    Budget(Date start, Date end, double initialBudget);

    // Getter for total budget
    double getTotalBudget() const;

    // Setter for total budget
    void setTotalBudget(double budget);

    // Getter for total spending
    double getTotalSpending() const;

    // Add a category and its budget
    void addCategory(Category* category, double budget);

    // Remove a category
    void removeCategory(Category* category);

    // Update the total budget by recalculating from categories
    void updateTotalBudget();

    // Reset all data for a new period
    void reset();
};

#endif  // BUDGET_H
