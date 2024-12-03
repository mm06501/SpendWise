#include "Account.h"
using namespace std;


        Account::Account() : balance(0.0), budget(new Budget(0.0)) {
        accountNumber = generateUniqueAccountNumber();
        writeAccountToFile();
    }

    Account::Account(double initialBudget, double balance): balance(0.0), budget(new Budget(initialBudget)) {
        accountNumber = generateUniqueAccountNumber();
        accountNumber = accountNumber;
        writeAccountToFile();
    }

    int Account::generateUniqueAccountNumber() {
        int accountNumber;
        bool unique = false;

        srand(time(nullptr));

        while (!unique) {
            accountNumber = rand() % 900000 + 100000;  // between 100000 and 999999
            unique = !accountExists(accountNumber);
        }

        return accountNumber;
    }

    bool Account::accountExists(int accountNumber) {
        ifstream file("accounts.csv");
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(",");
            if (pos != string::npos) {
                int existingAccountNumber = stoi(line.substr(0, pos));  // Get the account number part
                if (existingAccountNumber == accountNumber) {
                    return true;  // Account exists
                }
            }
        }
        return false; }
    
    // void Account::addTransaction(double amount, string description, Date date, string transactionType,
    //     Category& category) {
    //     Expense transaction(double amount, string description,
    //      Date date, string transactionType, Category& category);
    // }
    // void Account::addTransaction(double amount, string description, Date date, string transactionType,
    //     string source) {
    //     Income transaction(string source, double amount, string description,
    //      Date date, string transactionType);
    // }


    void Account::deposit(double amount, string description, Date date, string transactionType, string source) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " | New balance: " << balance << endl;
            Income income(double amount, string description, Date date, string transactionType,
        string source);
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void Account::withdraw(double amount, string description, Date date, string transactionType, Category& category) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New balance: " << balance << endl;
            Expense expense(double amount, string description,
         Date date, string transactionType, Category& category);
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    void Account::viewStatement() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
    cout << "Transactions: " << endl;
    ifstream file("transactions.csv");
    if (!file.is_open()) {
        cerr << "Error opening the file!" << endl;
        return;
    }
    string line;
    bool accountFound = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string accountNum, transaction;
        bool firstField = true;

        while (getline(ss, transaction, ',')) {
            if (firstField) {
                accountNum = transaction;
                firstField = false;
            } else {
                if (accountNum == to_string(accountNumber)) {
                    cout << "Transaction: " << transaction << endl;
                    accountFound = true;
                }
            }
        }
    }
    if (!accountFound) {
        cout << "No transactions found for this account number." << endl;
    }
    file.close();}

    void Account::writeAccountToFile() {
        ofstream file("accounts.csv", ios::app);
        if (file.is_open()) {
            file << accountNumber << "," << balance << "," << budget->getTotalBudget() << endl;
            file.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }

    int Account::getAccountNumber() const {
        return accountNumber;
    }
    double Account::getBalance() const {
        return balance;
    }
