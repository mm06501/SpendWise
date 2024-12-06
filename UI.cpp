#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>

class SFMLDemoApp {
public:
    SFMLDemoApp() : window(sf::VideoMode(800, 600), "Budget Tracker Demo") {
        if (!font.loadFromFile("C:/Users/HP/OneDrive/Desktop/new/arial.ttf")) {
            std::cerr << "Error loading font" << std::endl;
        }
    }

    void run() {
        bool running = true;
        while (window.isOpen() && running) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            renderScreens();
            window.display();
        }
    }

private:
    sf::RenderWindow window;
    sf::Font font;
    bool isAuthenticated = false;
    bool isInSignUp = false;
    std::string email = "test@example.com";
    std::string password = "password";
    double balance = 1000.00;
    double income = 1500.00;
    double expense = 500.00;

    void renderScreens() {
        if (isInSignUp) {
            renderSignUpScreen();
        } else if (!isAuthenticated) {
            renderLoginScreen();
        } else {
            renderDashboard();
        }
    }

    void renderLoginScreen() {
        sf::Text title("Login Screen", font, 30);
        title.setPosition(300, 50);
        window.draw(title);

        // Simulate user input
        sf::Text emailText("Email: " + email, font, 20);
        emailText.setPosition(200, 150);
        window.draw(emailText);

        sf::Text passwordText("Password: " + password, font, 20);
        passwordText.setPosition(200, 200);
        window.draw(passwordText);

        // Simulate login button
        sf::Text loginButton("Press Enter to Login", font, 20);
        loginButton.setPosition(200, 250);
        window.draw(loginButton);

        // Simulate Sign Up button
        sf::Text signUpButton("Press S for Sign Up", font, 20);
        signUpButton.setPosition(200, 300);
        window.draw(signUpButton);

        // Simulate login process
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    isAuthenticated = true;
                    std::cout << "Logged in successfully!" << std::endl;
                }
                if (event.key.code == sf::Keyboard::S) {
                    isInSignUp = true;
                    std::cout << "Switching to Sign Up screen..." << std::endl;
                }
            }
        }
    }

    void renderSignUpScreen() {
        sf::Text title("Sign Up Screen", font, 30);
        title.setPosition(300, 50);
        window.draw(title);

        // Simulate user input for email
        sf::Text signUpEmailText("Enter Email: " + email, font, 20);
        signUpEmailText.setPosition(200, 150);
        window.draw(signUpEmailText);

        // Simulate user input for password
        sf::Text signUpPasswordText("Enter Password: " + password, font, 20);
        signUpPasswordText.setPosition(200, 200);
        window.draw(signUpPasswordText);

        // Simulate the sign-up button
        sf::Text signUpCompleteButton("Press Enter to Complete Sign Up", font, 20);
        signUpCompleteButton.setPosition(200, 250);
        window.draw(signUpCompleteButton);

        // Simulate the back button
        sf::Text backButton("Press B to Back to Login", font, 20);
        backButton.setPosition(200, 300);
        window.draw(backButton);

        // Handle user interaction on Sign Up screen
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    isAuthenticated = true;
                    isInSignUp = false;
                    std::cout << "Sign Up Complete! Logged in as: " << email << std::endl;
                }
                if (event.key.code == sf::Keyboard::B) {
                    isInSignUp = false;
                    std::cout << "Back to Login screen." << std::endl;
                }
            }
        }
    }

    void renderDashboard() {
        sf::Text title("Dashboard", font, 30);
        title.setPosition(300, 50);
        window.draw(title);

        sf::Text balanceText("Current Balance: $" + std::to_string(balance), font, 20);
        balanceText.setPosition(200, 150);
        window.draw(balanceText);

        sf::Text incomeText("Total Income: $" + std::to_string(income), font, 20);
        incomeText.setPosition(200, 200);
        window.draw(incomeText);

        sf::Text expenseText("Total Expense: $" + std::to_string(expense), font, 20);
        expenseText.setPosition(200, 250);
        window.draw(expenseText);

        sf::Text remainingBalanceText("Remaining Balance: $" + std::to_string(balance + income - expense), font, 20);
        remainingBalanceText.setPosition(200, 300);
        window.draw(remainingBalanceText);

        // Simulate logout button
        sf::Text logoutButton("Press Enter to Logout", font, 20);
        logoutButton.setPosition(200, 350);
        window.draw(logoutButton);

        // Handle logout
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                isAuthenticated = false;
                std::cout << "Logged out successfully!" << std::endl;
            }
        }
    }
};

int main() {
    SFMLDemoApp app;
    app.run();
    return 0;
}
