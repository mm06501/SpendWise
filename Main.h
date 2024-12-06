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
    User* user;

public:
    static User* createUser(const int userIDCount ,const std::string& userName, const std::string& email,
                      const std::string& password, const Date& dateJoined,
                       double initialBudget, double startingBalance, Date start, Date end);
    static void deleteUser(int accountNumber, int userId, const std::string& email, const std::string& password, bool isAuthenticated);
    void updateProfile(const string& authEmail, const string& authPassword);
    bool login(const string& email, const string& password,  bool &isAuthenticated);
    bool logout(bool &isAuthenticated);
    static int userIdCount;
    bool isAuthenticated;
};

#endif
