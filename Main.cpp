#include "Main.h"
using namespace std;




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

User* Main::createUser(const int userIDCount ,const std::string& userName, const std::string& email,
                      const std::string& password, const Date& dateJoined,
                       double initialBudget, double startingBalance) {

    User* myUser = new User(userIdCount, userName, email, password, dateJoined, initialBudget, startingBalance);

    ofstream file("users.csv",ios::app);

    if (file.is_open()) {
        
       string formattedDate = myUser->getDateJoined().getDate();

        // Write the user details to the CSV file
        file << myUser->getAccountNumber() <<myUser->getUserId() << "," << myUser->getUserName() << "," << myUser->getEmail() << "," << myUser->getPassword() 
        << "," << formattedDate << initialBudget<< startingBalance<<endl;

        // Close the file after writing
        file.close();

        std::cout << "User created successfully!" << std::endl;

        userIdCount++;
    }
        return myUser;}

// Function to delete a user based on userId, email, and password
void Main::deleteUser(int accountNumber, int userId, const std::string& email, const std::string& password, bool isAuthenticated) {
    if(isAuthenticated){
    ifstream file("users.csv");  
    stringstream buffer;         
    string line;
    bool userFound = false;

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the file for reading." << std::endl;
        return;
    }
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

        buffer<<accountNumber << userID << "," << userName << "," << userEmail << "," << userPassword << "," << userDate << std::endl;
    }

    file.close();

    if (!userFound) {
        std::cout << "User not found. Deletion unsuccessful!" << std::endl;
        return;
    }

    // Now that we've processed all users, open the file in write mode and overwrite it
    ofstream outputFile("users.csv");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open the file for writing." << std::endl;
        return;
    }

    // Write the buffer content (without the deleted user) to the file
    outputFile << buffer.str();
    outputFile.close();
}
else
cout<<"Please log in first";}

bool Main::login(const string& email, const string& password,  bool &isAuthenticated) {
        std::ifstream inFile("users.csv");
        std::string line;

        // Check if the file opened successfully
        if (!inFile.is_open()) {
            std::cerr << "Error opening file." << std::endl;
            return false;
        }

        // Read each line from the CSV file
        while (getline(inFile, line)) {
            std::stringstream ss(line);  // Use stringstream to split the line
            std::string accountNumber, userID, userName, currentEmail, currentPassword;
            // Extract the data using getline to split by comma
            getline(ss, accountNumber, ',');
            getline(ss, userID, ',');
            getline(ss, userName, ',');
            getline(ss, currentEmail, ',');
            getline(ss, currentPassword, ',');

            if (currentEmail == email && currentPassword == password) {
                isAuthenticated = true;
                cout << "Login successful." <<endl;
                inFile.close(); 
                return true;
            }
        }

        inFile.close();
        std::cout << "Login failed: Incorrect email or password." << std::endl;
        return false;
    }

bool Main::logout(bool &isAuthenticated) {
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
