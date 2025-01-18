#include "staff.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

#include "staff.hpp"
#include <iostream>

using namespace std;

int main() {
    // Initialize inventory for testing
    stock = {
        {"Mineral_Water", 20},
        {"Coca_Cola", 15},
        {"Lays", 10},
        {"Kit_Kat", 5}
    };

    prices = {
        {"Mineral_Water", 1.00},
        {"Coca_Cola", 2.00},
        {"Lays", 4.00},
        {"Kit_Kat", 1.50}
    };

    // Test staff menu
    staffMenu();

    return 0;
}

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
    return false; // Login failure as number of attempt has been exhausted.
}

// Displaying the staff menu //
void staffMenu() {
    int choice;
    while (true) {
        cout << "\nStaff Menu:\n";
        cout << "1. Restock Items\n";
        cout << "2. Set Item Prices\n";
        cout << "3. View Stock\n";
        cout << "4. Exit to Main Menu\n";
        cout << "Enter your choice > ";
        cin >> choice;

        switch (choice) {
            case 1:
                restockItems();
                break;
            case 2:
                setItemPrices();
                break;
            case 3:
                displayStock();
                break;
            case 4:
                cout << "Returning to main menu. \n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}


// Restocking an item //
void restockItems() {
    string item;
    int quantity;

    cout << "\nEnter the item name to restock > ";
    cin >> item;
    cout << "Enter the amount of quantity to add > ";
    cin >> quantity;

    if (stock.find(item) != stock.end()) {
        stock[item] += quantity;
        cout << "Successfully restocked " << item << " with " << quantity << " units.\n";
        cout << "New total stock: " << stock[item] << " units.\n";
    } else {
        cout << "Restocking canceled.\n";
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
    
    cout << string(35, '-') << "\n";
    
    for (const auto& [item, quantity] : stock) {
        cout << left 
             << setw(15) << item
             << setw(10) << quantity
             << "RM" << fixed << setprecision(2) << prices[item] << "\n";
    }
}