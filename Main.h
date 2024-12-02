#ifndef MAIN_H
#define MAIN_H
#include <string>
#include "Date.h"
#include "User.h"

class Main {
private:
    static int userIdCount;
    User* user;
    bool isAuthenticated;

public:
    static void createUser();
    static void createUser(const int userIDCount, const string& userName, const string& email,
                              const string& password, const Date& dateJoined);
    static void deleteUser(int userId, const string& email, const string& password);
    void updateProfile(const string& authEmail, const string& authPassword);
    bool login(const string& email, const string& password);
    bool logout();
};

#endif
