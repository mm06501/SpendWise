#include "Main.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

#include <iomanip>  // For formatting strings
#include "User.h"
#include "Date.h"   // Assuming you have the Date class header
int Main::userIdCount = 10000;


// void Main::createUser() {

//     User newUser(userIdCount);

//     ofstream file("users.csv", std::ios::app);

//     if (file.is_open()) {
        
//         string formattedDate = newUser.getDateJoined().getDate();

//         // Write the user details to the CSV file
//         file << newUser.getUserId() << "," << newUser.getUserName() << "," << newUser.getEmail() << "," << newUser.getPassword() << "," << formattedDate << std::endl;

//         // Close the file after writing
//         file.close();

//         cout << "User created successfully!" << endl;

//         userIdCount++;
//     }
// }

void Main::createUser(const int userIDCount ,const std::string& userName, const std::string& email,
                      const std::string& password, const Date& dateJoined,
                       double initialBudget, double startingBalance) {

    User myUser(userIdCount, userName, email, password, dateJoined, initialBudget, startingBalance);

    std::ofstream file("users.csv", std::ios::app);

    if (file.is_open()) {
        
       string formattedDate = myUser.getDateJoined().getDate();

        // Write the user details to the CSV file
        file << myUser.getAccountNumber() <<myUser.getUserId() << "," << myUser.getUserName() << "," << myUser.getEmail() << "," << myUser.getPassword() << "," << formattedDate << std::endl;

        // Close the file after writing
        file.close();

        std::cout << "User created successfully!" << std::endl;

        userIdCount++;
    }
}


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "User.h"
#include "Date.h"

// Function to delete a user based on userId, email, and password
void Main::deleteUser(int accountNumber, int userId, const std::string& email, const std::string& password) {
    std::ifstream file("users.csv");  // Open the file to read
    std::stringstream buffer;         // A buffer to store the new file content
    std::string line;
    bool userFound = false;

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the file for reading." << std::endl;
        return;
    }

    // Read through the entire file and load it into the buffer, excluding the user to delete
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string accountNumber, userID, userName, userEmail, userPassword, userDate;
        
        std::getline(ss, accountNumber, ',');
        std::getline(ss, userID, ',');
        std::getline(ss, userName, ',');
        std::getline(ss, userEmail, ',');
        std::getline(ss, userPassword, ',');
        std::getline(ss, userDate);

        // Check if the current line matches the deletion criteria
        if (std::stoi(userID) == userId && userEmail == email && userPassword == password) {
            userFound = true;
            std::cout << "User with ID: " << userId << " has been deleted successfully!" << std::endl;
            continue;  // Skip this user, don't write to the buffer
        }

        // Write the non-matching users to the buffer (this excludes the deleted user)
        buffer<<accountNumber << userID << "," << userName << "," << userEmail << "," << userPassword << "," << userDate << std::endl;
    }

    file.close();

    if (!userFound) {
        std::cout << "User not found. Deletion unsuccessful!" << std::endl;
        return;
    }

    // Now that we've processed all users, open the file in write mode and overwrite it
    std::ofstream outputFile("users.csv");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open the file for writing." << std::endl;
        return;
    }

    // Write the buffer content (without the deleted user) to the file
    outputFile << buffer.str();
    outputFile.close();
}

bool Main::login(const string& email, const string& password) {
    ifstream inFile("users.csv");
    string line;


    while (getline(inFile, line)) {
        size_t firstComma = line.find(',');
        size_t secondComma = line.find(',', firstComma + 1);
        size_t thirdComma = line.find(',', secondComma + 1);

        if (firstComma != string::npos && secondComma != string::npos && thirdComma != string::npos) {
            string currentEmail = line.substr(secondComma + 1, thirdComma - secondComma - 1);
            string currentPassword = line.substr(thirdComma + 1, line.find(',', thirdComma + 1) - thirdComma - 1);

            if (currentEmail == email && currentPassword == password) {
                isAuthenticated = true; 
                inFile.close();
                cout << "Login successful." << endl;
                return true;}}}

    inFile.close();
    cout << "Login failed: Incorrect email or password." << endl;
    return false;}

bool Main::logout() {
    if (isAuthenticated) {
        isAuthenticated = false;
        cout << "Logout successful!" << endl;
        return true;}
		else {
        cout << "No active session to logout from." << endl;
        return false;}
    return false;}

    void Main::updateProfile(const string& authEmail, const string& authPassword) {
    if (!isAuthenticated) {
        cout << "You must be logged in to update your profile." << endl;
        return;
    }

    ifstream inFile("users.csv");
    if (!inFile) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    vector<string> lines;
    string line;
    bool updated = false;

    cout << "Updating profile. Leave fields blank to retain current values." << endl;
    // Prompt user for new values
    string newUserName, newEmail, newPassword;
    cout << "Enter new username (leave blank to keep current): ";
    getline(cin, newUserName);
    cout << "Enter new email (leave blank to keep current): ";
    getline(cin, newEmail);
    cout << "Enter new password (leave blank to keep current): ";
    getline(cin, newPassword);

    // Process each line in the file
    while (getline(inFile, line)) {
        stringstream ss(line);
        string currentUserId, currentUserName, currentEmail, currentPassword, dateJoined;
        getline(ss, currentUserId, ',');
        getline(ss, currentUserName, ',');
        getline(ss, currentEmail, ',');
        getline(ss, currentPassword, ',');
        getline(ss, dateJoined);

        // If the authenticated user's email and password match
        if (currentEmail == authEmail && currentPassword == authPassword) {
            updated = true;
            // Update fields only if new values are provided
            if (!newUserName.empty()) currentUserName = newUserName;
            if (!newEmail.empty()) currentEmail = newEmail;
            if (!newPassword.empty()) currentPassword = newPassword;

            line = currentUserId + "," + currentUserName + "," + currentEmail + "," + currentPassword + "," + dateJoined;
        }
        lines.push_back(line);  // Add the (possibly updated) line to the list    
    }
    inFile.close();

    if (!updated) {
        cout << "Profile update failed: No matching user found." << endl;
        return;
    }

    ofstream outFile("users.csv", ios::trunc);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (const auto& outLine : lines) {
        outFile << outLine << endl;
    }
    outFile.close();
    cout << "Profile updated successfully!" << endl;
}