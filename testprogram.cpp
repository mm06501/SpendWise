#include <iostream>
#include <fstream>
#include <string>
#include "Main.h"
#include "Date.h"  // Assuming you have a Date class
#include "User.h"  // Assuming you have a User class
#include "Budget.h"
#include "Account.h"
#include "Category.h"
#include "Income.h"
#include "Expense.h"
#include "Transaction.h"

using namespace std;

int main() {
    Main app;
    int userIdCount = 10001;
    string userName, email, password;
    Date dateJoined;  // Assuming you have a Date object or can instantiate one

    double initialBudget;
    cout<<"Enter initial budget: ";
    cin>>initialBudget;
    cout<<"Enter starting Balance: ";
    double startingBalance;

    // Test: Create User
    cout << "Creating a new user..." << endl;
    cout << "Enter username: ";
    getline(cin, userName);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter password: ";
    getline(cin, password);
    cout << "Enter joining date day DD): ";
    cin >> dateJoined.day;
    cout << "Enter joining date Month MM): ";
    cin>>dateJoined.month;
    cout << "Enter joining date Year YYYY): ";
    cin>>dateJoined.year;

    User* myUser = app.createUser(userIdCount, userName, email, password, dateJoined, initialBudget, startingBalance);
    int accNum = myUser->getAccountNumber();
    // Test: Login
    bool isAuthenticated = false;
    string loginEmail, loginPassword;
    cout << "\nLogging in..." << endl;
    cout << "Enter email: ";
    getline(cin, loginEmail);
    cout << "Enter password: ";
    getline(cin, loginPassword);

    if (app.login(loginEmail, loginPassword, isAuthenticated)) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Login failed!" << endl;
    }

    // Test: Update Profile
    if (isAuthenticated) {
        cout << "\nUpdating Profile..." << endl;

        app.updateProfile(loginEmail, loginPassword);
    }

    // Test: Logout
    if (app.logout(isAuthenticated)) {
        cout << "Logged out successfully." << endl;
    } else {
        cout << "Logout failed." << endl;
    }

    int deleteUserId;
    cout << "\nEnter user ID to delete: ";
    cin >> deleteUserId;
    cin.ignore();  // Ignore the newline character from previous input
    string deleteEmail, deletePassword;
    cout << "Enter email for deletion: ";
    getline(cin, deleteEmail);
    cout << "Enter password for deletion: ";
    getline(cin, deletePassword);
    app.deleteUser(accNum, deleteUserId, deleteEmail, deletePassword, isAuthenticated);

