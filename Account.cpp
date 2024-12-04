#include "Account.h"
using namespace std;


        Account::Account() {} //: balance(0.0), budget(new Budget(Date(1,2,2024 ),Date(1,2,2024 ), 0.0)) {
       // accountNumber = generateUniqueAccountNumber();
       // writeAccountToFile();
   // }

    Account::Account(int accNum, double startingBalance, Budget* budget): accountNumber(accNum), balance(startingBalance),
     budget(budget) {
        writeAccountToFile();
    }

    Account::Account(double startingBalance, Budget* budget): balance(startingBalance), budget(budget) {
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


    void Account::deposit(Income* income) {
        if (income->getAmount() > 0) {
            balance += income->getAmount();
            cout << "Deposited: " << income->getAmount() << " | New balance: " << balance << endl;
            addTransaction(income);
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void Account::withdraw(Expense* expense) {
        if (expense->getAmount() > 0 && expense->getAmount() <= balance) {
            balance -= expense->getAmount();
            cout << "Withdrawn: " << expense->getAmount() << " | New balance: " << balance << endl;
            addTransaction(expense);
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
            file << user->getUserId() << "," <<accountNumber << "," << balance << "," << budget->getTotalBudget() << endl;
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

    void Account::updateBalance(double newAmount){
        balance = newAmount;
    }

    void Account::addTransaction(Expense* expense) {
    std::ofstream file("transactions.csv", std::ios::app);  // Open file in append mode
    if (file.is_open()) {
        file << accountNumber << "," 
             << expense->getTransactionID() << ","
             << expense->getAmount() << ","
             << std::setw(2) << std::setfill('0') << expense->getDate().day << "/"
             << std::setw(2) << std::setfill('0') << expense->getDate().month << "/"
             << expense->getDate().year << ","
             << expense->getDescription() << "\n";
        file.close();
    } else {
        std::cerr << "Error opening transactions file!" << std::endl;
    }
}

void Account::addTransaction(Income* income) {
    std::ofstream file("transactions.csv", std::ios::app);  // Open file in append mode
    if (file.is_open()) {
        file << accountNumber << "," 
             << income->getTransactionID() << ","
             << income->getAmount() << ","
             << std::setw(2) << std::setfill('0') << income->getDate().day << "/"
             << std::setw(2) << std::setfill('0') << income->getDate().month << "/"
             << income->getDate().year << ","
             << income->getDescription() << "\n";
        file.close();
    } else {
        std::cerr << "Error opening transactions file!" << std::endl;
    }
}
