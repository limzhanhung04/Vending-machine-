#include "inventory.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Product::Product(string name, double price, int quantity){
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

void vendingMachine::addProduct(string name, double price, int quantity){
    Product(name, price, quantity);
    products.push_back(Product("Mineral Water", 1.00, 20));
    products.push_back(Product("100 Plus", 2.00, 20));
    products.push_back(Product("Coca Cola", 2.00, 20));
    products.push_back(Product("Nescafe Coffee", 3.00, 20));
    products.push_back(Product("Milo", 2.50, 20));
    products.push_back(Product("Lays", 4.00, 20));
    products.push_back(Product("Kit Kat", 1.50, 20));
    products.push_back(Product("Oreo", 2.00, 20));
    products.push_back(Product("M&M", 2.00, 20));
    products.push_back(Product("Maggi Hot Cup", 3.00, 20));
}

void vendingMachine::updateStock(Product product, int quantity){
    for(int i = 0; i < products.size(); i++){
        if(products[i].name == product.name){
            products[i].quantity -= quantity;
        }
    }
}   

bool vendingMachine::checkStock(Product product, int quantity){
    for(int i = 0; i < products.size(); i++){
        if(products[i].name == product.name){
            if(products[i].quantity >= quantity){
                return true;
            }
        }
    }
    return false;
}

void vendingMachine::restockProduct(Product product, int quantity){
    for(int i = 0; i < products.size(); i++){
        if(products[i].name == product.name){
            products[i].quantity += quantity;
        }
    }
}