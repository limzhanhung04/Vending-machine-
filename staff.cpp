#include "staff.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

// Definitions for inventory data //
map<string, int> stock;
map<string, double> prices;

// Login credentials //
const string STAFF_USERNAME = "Admin";
const string STAFF_PASSWORD = "69420";

// Staff login function //
bool staffLogin() {
    string username, password;
    int attempts = 3; // Allow up to 3 attempts before redirecting to prevent endless loop. 

    // Input from staff //
    while (attempts > 0) {
        cout << "\nStaff Login\n";
        cout << "Please enter your Username > ";
        cin >> username;
        cout << "Please enter your Password > ";
        cin >> password;

        if (username == STAFF_USERNAME && password == STAFF_PASSWORD) {
            cout << "Login successful! Welcome, Admin.\n";
            return true; // Correct password and username. 
        } else {
            attempts--;
            cout << "Invalid password or username. You have " << attempts << " attempt(s) remaining.\n"; // Incorrect password or username.
        }
    }

    cout << "Too many failed attempts. Redirecting to main menu.\n";
    return false; // Login failure as number of attempt has been used up.
}

// Displaying the staff menu //
void staffMenu() {
    int choice;
    while (true) {
        cout << "\nStaff Menu:\n";
        cout << "1. Restock or Remove Items\n";
        cout << "2. Set Item Prices\n";
        cout << "3. View Stock\n";
        cout << "4. Exit to Main Menu\n";
        cout << "Enter your choice (1 - 4) > ";
        cin >> choice;

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
                cout << "Invalid choice. Please try again.\n";
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
            cout << "Enter the amount of quantity to add > ";
            cin >> quantity;
            
            stock[item] += quantity;
            cout << "Successfully restocked " << item << " with " << quantity << " units.\n";
            cout << "New total stock: " << stock[item] << " units.\n";
            break;
        }
        
        case '2': {
            cout << "Enter the amount of quantity to remove > ";
            cin >> quantity;
            
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