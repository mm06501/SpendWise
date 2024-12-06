# SPENDWISE : Personal Budget Tracker Application.

## Overview

This project is a simple financial management system implemented in C++. It allows users to manage accounts, transactions, income, expenses, budgets, and categories.

## Files

The project consists of the following files:

- **Main.cpp**: Entry point for the program, which drives the logic.
- **User.cpp**: Contains the user class and related functionality.
- **Account.cpp**: Contains the account class and functions for managing accounts.
- **Transaction.cpp**: Contains the transaction class and logic for handling transactions.
- **Income.cpp**: Handles income-related functionality.
- **Expense.cpp**: Handles expense-related functionality.
- **Budget.cpp**: Contains budget management functionality.
- **Date.cpp**: Contains date handling functionality.
- **Category.cpp**: Manages different categories of income/expenses.
- **testprogram.cpp**: The main file used to test the program's functionality.

## Compilation

To compile and create the executable file `demo.exe`, run the following command in the terminal:

```bash
g++ Main.cpp User.cpp Account.cpp Transaction.cpp Income.cpp Expense.cpp Budget.cpp Date.cpp Category.cpp testprogram.cpp -o demo.exe
