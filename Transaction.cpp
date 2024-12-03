#include "Transaction.h"
#include <sstream>

// Static member initialization
int Transaction::count = 0;

Transaction::Transaction() : amount(0.0), transactionID(count), description("") {
writeTransactionToFile();
}

Transaction::Transaction(double amount, const Date& date, const std::string& description)
    : amount(amount), date(date), description(description) {
    transactionID = count++;
    writeTransactionToFile();
}

int Transaction::getTransactionID() const {
    return transactionID;
}

void Transaction::setTransactionID(int id) {
    transactionID = id;
}

double Transaction::getAmount() const {
    return amount;
}

void Transaction::setAmount(double amount) {
    this->amount = amount;
}


Date Transaction::getDate() const {
    return date;
}

void Transaction::setDate(const Date& date) {
    this->date = date;
}

void Transaction::setDescription(const std::string& description) {
    this->description = description;
}

std::string Transaction::getTransactionDetails() const {
    std::stringstream ss;
    ss << "Transaction ID: " << transactionID << "\n"
       << "Amount: " << amount << "\n"
       << "Date: " << date.getDate()<< "\n"
       << "Description: " << description;
    return ss.str();
}

// Method to write the transaction details to a file
void Transaction::writeTransactionToFile() {
    std::ofstream file("transactions.csv", std::ios::app);  // Open file in append mode
    if (file.is_open()) {
        file << transactionID << ","
             << amount << ","
             << std::setw(2) << std::setfill('0') << date.day << "/"
             << std::setw(2) << std::setfill('0') << date.month << "/"
             << date.year) << ","
             << description << "\n";
        file.close();
    } else {
        std::cerr << "Error opening transactions file!" << std::endl;
    }
}
