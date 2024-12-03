#ifndef USER_H
#define USER_H

#include <string>
#include "Date.h"   // Include Date header
#include "Account.h"  

using namespace std;

class User {
private:
    int userID;  // User ID
    string userName;  // Username
    string email;  // Email address
    string password;  // Password
    Date dateJoined;  // Date of joining (Date object)
    Account* account;
public:
    // Constructors
    User();  // Default constructor
    User(int userID, const string& userName, const string& email, const string& password,
     const Date& dateJoined, double initialBudget, double startingBalance);

    // Getters for User properties
    const Date& getDateJoined() const;
    int getUserId() const;
    string getUserName() const;
    string getEmail() const;
    string getPassword() const;
    int getAccountNumber();
};

#endif
