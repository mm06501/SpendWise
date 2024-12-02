#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include "Transaction.h"
#include "Budget.h"

using namespace std;

class Account {
private:
    int accountNumber;
    string accountType;
    double balance;
    string password;
    Budget* budget;  // Pointer to Budget object
    vector<Transaction*> transactions;  // Vector of Transaction pointers

public:
    // Default constructor
    Account() : accountNumber(0), accountType("Standard"), balance(0.0), password(""), budget(nullptr) {
        // Optional: Initialize the transactions vector if needed (it's already default-initialized to empty)
    }

    // Parameterized constructor
    Account(int accountNumber, const string& accountType, double balance, const string& password, Budget* budget = nullptr)
        : accountNumber(accountNumber), accountType(accountType), balance(balance), password(password), budget(budget) {
        // Initialize the transactions vector (it's already default-initialized)
    }

    // Destructor
    ~Account() {
        // Delete the dynamically allocated Budget object if it exists
        if (budget) {
            delete budget;
        }

        // Optionally delete each Transaction object if they were dynamically allocated
        for (Transaction* transaction : transactions) {
            delete transaction;  // Make sure each transaction object is deleted
        }
        // Clear the transactions vector
        transactions.clear();
    }

    // Add a new transaction to the account
    void addTransaction(Transaction* transaction) {
        transactions.push_back(transaction);  // Adds transaction to the vector
    }

    // Delete a transaction from the account
    void deleteTransaction(Transaction* transaction) {
        }

    // Get the current balance of the account
    double getBalance() const {
        return balance;
    }

    // Deposit a specified amount to the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " | New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw a specified amount from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    // View the account statement (basic example, could be extended)
    void viewStatement() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transactions: " << endl;

        for (const auto& transaction : transactions) {
            // Assuming Transaction has a method to print details
            transaction->displayTransactionDetails();  // Replace with actual method in Transaction class
        }
    }

    // Getters and Setters for the Account properties (optional)
    int getAccountNumber() const {
        return accountNumber;
    }

    string getAccountType() const {
        return accountType;
    }

    string getPassword() const {
        return password;
    }

    Budget* getBudget() const {
        return budget;
    }

    void setPassword(const string& newPassword) {
        password = newPassword;
    }

    void setAccountType(const string& newAccountType) {
        accountType = newAccountType;
    }

    void setBalance(double newBalance) {
        balance = newBalance;
    }

    void setBudget(Budget* newBudget) {
        if (budget) {
            delete budget;  // Delete the old budget if it was dynamically allocated
        }
        budget = newBudget;
    }
};

#endif
