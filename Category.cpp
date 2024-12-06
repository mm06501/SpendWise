#include "Category.h"

// Constructor to initialize a Category with a name and budget
Category::Category(int id, const string& categoryName, double categoryBudget)
    : categoryID(id), name(categoryName), budget(categoryBudget), totalSpending(0.0) {}

// Getter for category name
string Category::getName() const {
    return name;
}

void Category::setBudget(double amount){
    budget = amount;
}

double Category::getBudget() const {
    return budget;
}

// Getter for category spending
double Category::getSpending() const {
    return totalSpending;
}

int Category::getCategoryID() const {
    return categoryID;
}


void Category::setTotalSpending(double amount) {
    totalSpending = amount;
}
