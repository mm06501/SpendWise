#include "Budget.h"

// Constructor initializes startDate, endDate, and totalBudget
Budget::Budget(Date start, Date end, double initialBudget)
    : startDate(start), endDate(end), totalBudget(initialBudget), totalSpending(0.0) {}

// Getter for total budget
double Budget::getTotalBudget() const {
    return totalBudget;
}

// Setter for total budget
void Budget::setTotalBudget(double budget) {
    totalBudget = budget;
}

// Getter for total spending
double Budget::getTotalSpending() const {
    return totalSpending;
}

Category* Budget::getCategoryById(int categoryId) {
    for (auto& categoryPair : categories) {
        if (categoryPair.first->getCategoryID() == categoryId) {
            return categoryPair.first;  // Return the pointer to the matching Category
        }
    }
    return nullptr;  // Return nullptr if the category was not found
}


// Add a category and its budget to the list
void Budget::addCategory(Category* category, double budget) {
    categories.push_back(make_pair(category, budget));
    updateTotalBudget(); 
}

// Remove a category and its budget
void Budget::removeCategory(Category* category) {
    for (auto it = categories.begin(); it != categories.end(); ++it) {
        if (it->first == category) {
            categories.erase(it);
            updateTotalBudget();  // Recalculate total budget after removal
            break;
        }
    }
}

// Recalculate the total budget based on the sum of all category budgets
void Budget::updateTotalBudget() {
    double newTotal = 0.0;
    for (const auto& pair : categories) {
        newTotal += pair.second;  // Add the budget for each category
    }
    totalBudget = newTotal;
}

// Reset the budget (clear categories, reset total spending, etc.)
void Budget::reset() {
    categories.clear();
    totalSpending = 0.0;
    totalBudget = 0.0;
}

// void Budget::reset() {
//     // Clear all categories
//     categories.clear();
    
//     // Reset total spending and budget
//     totalSpending = 0.0;
//     totalBudget = 0.0;

//     startDate = Date();  
//     endDate = Date();    
// }
void Budget::setTotalSpending(double amount){
    totalSpending = amount;
}

