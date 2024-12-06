#include "Report.h"

using namespace std;


void Report::generateReport(Account* account){
    cout << "Account Number: " << account->getAccountNumber() << endl;
    cout << "Balance: " << account->getBalance() << endl;
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
                if (accountNum == to_string(account->getAccountNumber())) {
                    cout << "Transaction: " << transaction << endl;
                    accountFound = true;
                }
            }
        }
    }
    if (!accountFound) {
        cout << "No transactions found for this account number." << endl;
    }
    file.close(); }