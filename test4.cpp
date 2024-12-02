#include "User.h"
#include <iostream>

using namespace std;

int main() {
    User user;

    // Test creating accounts
    cout << "Creating accounts..." << endl;
    User::createAccount("Muhammad Hashim", "hashim@example.com", "12345", Date(15, 12, 2024));
    User::createAccount("Basit Ali", "basit@example.com", "password", Date(1, 3, 2022));
    cout << "Accounts created successfully!" << endl;

    // Test logging in
    string email, password;
    cout << "Enter email to login: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    if (user.login(email, password)) {
        cout << "Logged in successfully!" << endl;

        // Test updating profile
        cout << "=== Update Profile ===" << endl;
        user.updateProfile("hashim@example.com", "12345");

        // Test logging out
        if (user.logout()) {
            cout << "Logged out successfully!" << endl;
        } else {
            cout << "No active session to logout from." << endl;
        }
    } else {
        cout << "Login failed. Please check your credentials." << endl;
    }

    return 0;
}
