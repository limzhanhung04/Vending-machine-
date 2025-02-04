#ifndef STAFF_HPP
#define STAFF_HPP

#include <map>
#include <string>

using namespace std;

// Inventory data structures
extern map<string, int> stock;    // Stores item names and their quantities.
extern map<string, double> prices; // Stores item names and their prices.

// Function declarations
bool staffLogin();        // Authenticate staff before granting access.
void manageItems();      // Restock or remove items in the vending machine.
void setItemPrices();     // Update the prices of items in the vending machine.
void displayStock();      // Display current inventory (stock and prices) of items in the vending machine.
void staffMenu();         // Menu for staff to access these functions.

#endif 