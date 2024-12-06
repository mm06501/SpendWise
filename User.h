#ifndef USER_H
#define USER_H

#include <string>
#include "Date.h"   // Include Date header
#include "Account.h" 
#include "Budget.h"


using namespace std;

class User {
private:
    int userID;  // User ID
    string userName;  // Username
    string email;  // Email address
    string password;  // Password
    Date dateJoined;  // Date of joining (Date object)
    Account account;
    Budget* budget;
    string getEmail() const;
    string getPassword() const;
public:
    // Constructors
    User();  // Default constructor
    User(int userID);
    User(int userID, const string& userName, const string& email, const string& password, const Date& dateJoined,
    Date start, Date end,double initialBudget, double startingBalance);

    // Getters for User properties
    const Date& getDateJoined() const;
    int getUserId() const;
    string getUserName() const;
    int getAccountNumber();
    Account* getAccount();
    Budget* getBudget();
};

#endif
