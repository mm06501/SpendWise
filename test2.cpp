#include "User.h"
#include <iostream>
using namespace std;

int main() {
    User user;

    string email, password;

    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;


    if (user.login(email, password)) {
        cout << "Login successful! Welcome to the system." << endl;
    } else {
        cout << "Login failed. Please check your credentials." << endl;
    }

    return 0;
}
