#ifndef inventory _hpp
#define inventory _hpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product{
    public:
        string name;
        double price;
        int quantity;
        Product(std::string name, double price, int quantity);
};

class vendingMachine{
    private:
        vector<Product> products;
    public:
        void addProduct(string name, double price, int quantity);
        void updateStock(Product, int quantity);
        bool checkStock(Product, int quantity);
        void restockProduct(Product, int quantity);
};

#endif 