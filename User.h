#ifndef USER_H
#define USER_H

#include <string>
#include "Date.h"   // Include Date header

// Forward declaration of Account class, if needed later
// #include "Account.h"  

using namespace std;

class User {
private:
    int userID;  // User ID
    string userName;  // Username
    string email;  // Email address
    string password;  // Password
    Date dateJoined;  // Date of joining (Date object)

public:
    // Constructors
    User();  // Default constructor
    User(int userIDCount);  // Constructor that asks for user input
    User(int userID, const string& userName, const string& email, const string& password, const Date& dateJoined);

    // Getters for User properties
    const Date& getDateJoined() const;
    int getUserId() const;
    string getUserName() const;
    string getEmail() const;
    string getPassword() const;
};

#endif
