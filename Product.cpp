#include "product.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

        string name;
        double price; 
        int quantity;   

        //Getter function for name, price, and quantity
        string getName(){
            return name;
        }
        double getPrice(){
            return price;
        }
        int getQuantity() {
            return quantity;
        }  

        //Setter function for name, price, and quantity
        void setName(const std::string& productName) {
            name = productName;
        }  
        void setPrice(double productPrice) {
            price = productPrice;
        }
        void setQuantity(int productQuantity) {
            quantity = productQuantity;
        }

        //Save and load product information to and from a file
        void saveToFile(std::ofstream& outFile) {
            outFile << name << " " << price << " " << quantity << endl;
        }
        void loadFromFile(std::ifstream& inFile) {
            inFile >> name >> price >> quantity;
        }

        //Display product information
        void displayProduct() {
            cout << "Product Name: " << name << endl;
            cout << "Product Price: " << price << endl;
            cout << "Product Quantity: " << quantity << endl;
        }  