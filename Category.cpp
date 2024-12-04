#include "Category.h"

// Constructor to initialize a Category with a name and budget
Category::Category(int id, const string& categoryName, double categoryBudget)
    : categoryID(id), name(categoryName), budget(categoryBudget), spending(0.0) {}

// Getter for category name
string Category::getName() const {
    return name;
}

// Getter for category budget
double Category::getBudget() const {
    return budget;
}

// Getter for category spending
double Category::getSpending() const {
    return spending;
}

// Getter for category ID
int Category::getCategoryID() const {
    return categoryID;
}

// Add a transaction to the category
void Category::addTransaction(Transaction* transaction) {
    transactions.push_back(transaction);
    updateSpending();  // Recalculate the spending after adding a transaction
}

// Delete a transaction from the category
void Category::deleteTransaction(Transaction* transaction) {
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if (*it == transaction) {
            transactions.erase(it);
            updateSpending();  // Recalculate the spending after deleting a transaction
            break;
        }
    }
}

// Update the spending after adding/removing transactions
void Category::updateSpending() {
    spending = 0.0;  // Reset spending
    for (auto& transaction : transactions) {
        spending += transaction->getAmount();  // Add the transaction amount to the spending
    }
}
string Category::getName(){
    return name;
}

// Update spending based on transactions (can be called explicitly if needed)
void Category::updateBudget() {
    // You can implement this to adjust the category's budget based on spending or other logic
    // For now, we can just update spending here, if needed.
    updateSpending();
}
