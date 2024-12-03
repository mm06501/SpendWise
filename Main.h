#ifndef MAIN_H
#define MAIN_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>  
#include "User.h"
#include "Date.h" 
#include "Account.h"

class Main {
private:
    static int userIdCount;
    User* user;
    bool isAuthenticated = false;

public:
    static void createUser(const int userIDCount, const string& userName, const string& email,
                              const string& password, const Date& dateJoined, double initialBudget, double startingBalance);
    static void deleteUser(int accountNumber, int userId, const std::string& email, const std::string& password);
    void updateProfile(const string& authEmail, const string& authPassword);
    bool login(const string& email, const string& password);
    bool logout();
};

#endif
