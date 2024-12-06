#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include "Main.h"
#include "Date.h"  
#include "User.h"  
#include "Budget.h"
#include "Account.h"
#include "Category.h"
#include "Income.h"
#include "Expense.h"
#include "Transaction.h"
#include <limits>
#include "Report.h"

using namespace std;

int main() {
    Main app;
    app.isAuthenticated = false;
    string userName, email, password;
    Date dateJoined;
    
    char ch;

    cout << "Enter password: ";

cout<<"Welcome to SpendWise"<<endl;
cout<<"Sign Up:"<<endl;
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter password: ";
        while ((ch = _getch()) != 13) {  // 13 is the Enter key
        if (ch == 8) {  // Backspace
            if (password.length() > 0) {
                password.pop_back();
                cout << "\b \b";  // Move cursor back, erase character
            }
        } else {
            password.push_back(ch);
            cout << '*';  // Print asterisk for each entered character
        }
    }
    cout<<endl;
 cout << "Enter joining date (DD MM YYYY): ";
    cin >> dateJoined.day >> dateJoined.month >> dateJoined.year;
cout<<"Enter budget details:"<<endl;
    double initialBudget;
    cout<<"Enter initial budget: ";
    cin>>initialBudget;
    double startingBalance;
    cout<<"Enter starting balance: ";
    cin>>startingBalance;
    Date start, end;
    cout << "Enter budget start date (DD MM YYYY): ";
    cin >> start.day >> start.month >> start.year;
    cout << "Enter budget date (DD MM YYYY): ";
    cin >> end.day >> end.month >> end.year;
    User* myUser = app.createUser(app.userIdCount, userName, email, password, dateJoined, initialBudget, startingBalance,start, end);

    cout<< "Sign Up Complete."<<endl;
    int accNum = myUser->getAccountNumber();

string loginEmail, loginPassword;


    // Taking email input
    cout << "Enter email: ";
    getline(cin, loginEmail);  // Read the email input

    // Clear any leftover newline characters in the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Taking password input (hide the input with asterisks)
    char ch2;
    cout << "Enter password: ";
    while ((ch2 = _getch()) != 13) {  // 13 is the Enter key
        if (ch2 == 8) {  // Backspace
            if (loginPassword.length() > 0) {
                loginPassword.pop_back();
                cout << "\b \b";  // Move cursor back, erase character
            }
        } else {
            loginPassword.push_back(ch2);
            cout << '*';  // Print asterisk for each entered character
        }
    }
    cout << endl;
bool isAuthenticated = false;
    // Call login function
    if (app.login(email, password, isAuthenticated)) {
        cout << "Login successful." << endl;
    } else {
        cout << "Login failed." << endl;
    }

    isAuthenticated = true;
    app.updateProfile(loginEmail, loginPassword);

    isAuthenticated = true;
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
    app.deleteUser(accNum, deleteUserId, deleteEmail, deletePassword, app.isAuthenticated);

    // Create a sample Budget (e.g., start and end date with initial budget)
    Budget* budget = myUser->getBudget();

    // Create an Account (with account number, starting balance, and budget)
    Account* account =  myUser->getAccount();

    // Display initial account details
    cout << "Initial Account Details: " << endl;
    cout << "Account Number: " << account->getAccountNumber() << endl;
    cout << "Balance: " << account->getBalance() << endl;

    Category* rent = new Category(1, "Rent", 50000);
    budget-> addCategory(rent, 50000);

    Income* income = new Income(1000.0,Date(15, 02, 2024), "Monthly Salary", "Habib University");
    Expense* expense = new Expense(200.0, Date(16, 2, 2024), "Grocery shopping", rent);


    cout << "\nDepositing Income..." << endl;
    account->deposit(income);

    cout << "\nWithdrawing Expense..." << endl;
    account->withdraw(expense);

    cout << "\nAccount Report " << endl;
    Report report;
    report.generateReport(account);

    account->updateBalance(1000.0); // Setting balance to 1000.0
    cout << "\nUpdated Account Balance: " << account->getBalance() << endl;


    delete income;
    delete expense;
    delete budget;

    return 0;
}



