#include "User.h"
#include "Main.h"
#include <iostream>

using namespace std;

int main() {
    
	
    Main::createUser(10001, "Muhammad Hashim", "hashim@example.com", "12345", Date(15, 12, 2024));
    Main::createUser(10003, "Wasif Ali", "wasif@example.com", "password1", Date(1, 3, 2022));
    Main::createUser(10004, "Faaiz Ali", "faaiz@example.com", "password2", Date(1, 3, 2022));
    Main::createUser(10005, "Shan Ali", "shan@example.com", "password3", Date(1, 3, 2022));


    cout << "User account creation done!" << endl;

    Main::deleteUser(10001, "hashim@example.com", "12345");

    cout << "Account deleted successfully!" << endl;

    return 0;
}
