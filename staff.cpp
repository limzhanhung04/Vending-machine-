#include "staff.hpp"    // Header file
#include <iostream>     //
#include <iomanip>      // Generalise precise and correct decimal places and stock display.
#include <string>
#include <map>
#include <limits>       // 

using namespace std;

// Definitions for inventory data //
map<string, int> stock;
map<string, double> prices;

// Login credentials //
const string STAFF_USERNAME = "Admin";
const string STAFF_PASSWORD = "69420";

bool staffLogin() {
    string username, password;
    int attempts = 3; // Allow up to 3 attempts before redirecting to main menu to prevent endless loops.

    while (attempts > 0) {
        cout << "\nStaff Login\n";

        // Input username from staff //
        cout << "Please enter your Username > ";
        getline(cin, username); 
        if (username.empty()) { // Check for empty input.
            cout << "Username cannot be empty. Please try again.\n";
            continue;
        }

        // Input password from staff //
        cout << "Please enter your Password > ";
        getline(cin, password); 
        if (password.empty()) { 
            cout << "Password cannot be empty. Please try again.\n";
            continue;
        }

        // Check credentials validity //
        if (username == STAFF_USERNAME && password == STAFF_PASSWORD) {
            cout << "Login successful! Welcome, Admin.\n";
            return true; // Successfully logged in as the input for username and password is correct.
        } else {
            attempts--;
            cout << "Invalid password or username. You have " << attempts << " attempt(s) remaining.\n"; // Wrong username or password.
        }
    }

    cout << "Too many failed attempts. Redirecting to main menu.\n";
    return false; // Failure to log in after exhausting attempts.
}

// Menu for staff to choose his/her actions //
void staffMenu() {
    int choice;
    while (true) {
        cout << "\nStaff Menu:\n";
        cout << "1. Restock or Remove Items\n";
        cout << "2. Set Item Prices\n";
        cout << "3. View Stock\n";
        cout << "4. Exit to Main Menu\n";

        // Use safeInput to validate only numeric input by staff //
        safeInput(choice, "Enter your choice (1 - 4) > ");

        switch (choice) {
            case 1:
                manageItems();
                break;
            case 2:
                setItemPrices();
                break;
            case 3:
                displayStock();
                break;
            case 4:
                cout << "Returning to main menu.\n";
                return;
            default:
                cout << "Invalid choice. Please try again by entering input within the given range.\n";
        }
    }
}

// Restocking or removing an item //
void manageItems() {
    string item;
    int quantity;
    char choice;

    cout << "\nInventory Management";
    cout << "\n1. Restock items";
    cout << "\n2. Remove expired items";
    cout << "\nEnter your choice (1-2) > ";
    cin >> choice;

    cout << "\nEnter the item name > ";
    cin >> item;

    if (stock.find(item) == stock.end()) {
        cout << "Item not found in inventory.\n";
        return;
    }

    switch (choice) {
        case '1': {
            safeInput(quantity, "Enter the amount of quantity to add (minimum requirement = 1) > ");
            
            stock[item] += quantity;
            cout << "Successfully restocked " << item << " with " << quantity << " units.\n";
            cout << "New total stock: " << stock[item] << " units.\n";
            break;
        }
        
        case '2': {
            safeInput(quantity, "Enter the amount of quantity to remove (minimum requirement = 1) > ");
            
            if (quantity > stock[item]) {
                cout << "Error: Cannot remove more than current available stock (" 
                     << stock[item] << " units).\n";
            } else {
                stock[item] -= quantity;
                cout << "Successfully removed " << quantity << " units of " << item << ".\n";
                cout << "Remaining stock: " << stock[item] << " units.\n";
            }
            break;
        }
        
        default:
            cout << "Invalid choice. Operation canceled.\n";
    }
}

// Set or readjust the price of an item //
void setItemPrices() {
    string item;
    double price;

    cout << "\nEnter the item name to update price > ";
    cin >> item;

    if (prices.find(item) != prices.end()) {
        cout << "Enter the new price for " << item << "> ";
        cin >> price;
        prices[item] = price;
        cout << "Updated price of " << item << " to RM " << fixed << setprecision(2) << price << ".\n";
    } else {
        cout << "Item not found in inventory.\n";
    }
}

// Display the current stock and prices //
void displayStock() {
    if (stock.empty()) {
        cout << "\nInventory is empty.\n";
        return; // To prevent displaying void in the case where there's literally no stocks left.
    }

    cout << "\nCurrent Inventory:\n";
    cout << left 
         << setw(20) << "Item"
         << setw(10) << "Quantity"
         << setw(10) << "Price" << "\n";
    cout << string(40, '-') << "\n";

    for (const auto& [item, quantity] : stock) {
        cout << left 
             << setw(20) << item
             << setw(10) << quantity
             << "RM" << fixed << setprecision(2) << prices[item] << "\n";
    }
}


// To prevent processing failure of the program if the inputs are alphabets while integers are expected. 
void safeInput(int& value, const string& prompt) {
    while (true) {
        cout << prompt;
        if (cin >> value) { // Valid numeric input
            break; 

        } else { // Invalid input (i.e., alphabets or symbols)
            cin.clear(); // Clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // To discard invalid input
            cout << "Invalid input. Please enter a number in the range provided.\n";
        }
    }
}

