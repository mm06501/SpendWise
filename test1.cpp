#include <iostream>
#include "Main.h"
#include "User.h" 
#include "Account.h"

int main() {

    Main mainApp;
    
    bool isAuthenticated = false;

    std::cout << "Testing: Create User" << std::endl;
    Date dateJoined = Date(04, 12, 2024);
    Date startDate = Date(04, 12, 2024);
    Date endDate = Date(04, 12, 2025);
    User* newUser = mainApp.createUser(10001, "JohnDoe", "johndoe@example.com", "password123", dateJoined, 500.0, 200.0, startDate, endDate);
    
    std::cout << std::endl;

    // Test: User login
    std::cout << "Testing: Login" << std::endl;
    bool loginResult = mainApp.login("johndoe@example.com", "password123", isAuthenticated);
    std::cout << "Login result: " << (loginResult ? "Success" : "Failure") << std::endl;
    std::cout << std::endl;

    std::cout << "Testing: Update Profile" << std::endl;
    mainApp.updateProfile("johndoe@example.com", "password123");
    std::cout << std::endl;

    std::cout << "Testing: Logout" << std::endl;
    bool logoutResult = mainApp.logout(isAuthenticated);
    std::cout << "Logout result: " << (logoutResult ? "Success" : "Failure") << std::endl;
    std::cout << std::endl;

    // Test: Delete user
    std::cout << "Testing: Delete User" << std::endl;
    mainApp.deleteUser(newUser->getAccountNumber(), 10001, "johndoe@example.com", "password123", isAuthenticated);
    
    std::cout << std::endl;

    // Additional test to verify user deletion
    std::cout << "Testing: Login after Deletion" << std::endl;
    bool loginAfterDeletion = mainApp.login("johndoe@example.com", "password123", isAuthenticated);
    std::cout << "Login result after deletion: " << (loginAfterDeletion ? "Success" : "Failure") << std::endl;
    
    return 0;
}
