#include "User.h"
#include <iostream>

using namespace std;

int main() {
    User user;

    if (user.login("hashim@example.com", "12345")) {
        cout << "User logged in successfully!" << endl;}


    if (user.logout()) {
        cout << "User logged out successfully!" << endl;}


    if (!user.logout()) {
        cout << "Cannot logout because no session is active." << endl;    }
    return 0;
}
