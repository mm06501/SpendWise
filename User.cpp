#include "User.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
User::User() {
    // You may initialize other members here if needed
}

// // Constructor that asks for user input
User::User(int userID) {
    cout << "Enter username: ";
    getline(cin, userName);

    cout << "Enter email: ";
    getline(cin, email);

    cout << "Enter password: ";
    getline(cin, password);

    // Prompt user for the join date
    Date date;
    cout << "Enter the date joined (format: DD): ";
    cin >> date.day;
    cout << "Enter the Month (format: MM): ";
    cin >> date.month;
    cout << "Enter the Year (format: YYYY): ";
    cin >> date.year;

    // Initialize dateJoined with user input
    dateJoined = date;
    
    // Optionally, initialize account if needed
     account = new Account();

    cout << "User account created!" << endl;
}

// Account(User& user, double startingBalance, Budget* budget);

// Parameterized constructor
User::User(int userID, const string& userName, const string& email, const string& password, const Date& dateJoined,
 Date start, Date end, double initialBudget, double startingBalance)
    : userID(userID), userName(userName), email(email), password(password), dateJoined(dateJoined) {
    budget = new Budget(start, end, initialBudget);
    account = new Account(startingBalance, budget);
}
int User::getAccountNumber(){
   int accNum = account->getAccountNumber();
   return accNum;
}
// Getter for dateJoined
const Date& User::getDateJoined() const { 
    return dateJoined; 
}

// Getter for userID
int User::getUserId() const { 
    return userID;  // Fixed the member name to match the class definition
}

// Getter for userName
string User::getUserName() const { 
    return userName; 
}

// Getter for email
string User::getEmail() const { 
    return email; 
}

// Getter for password
string User::getPassword() const { 
    return password; 
}
