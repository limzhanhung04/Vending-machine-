#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <fstream>
#include <string>

using namespace std;

class Product{
    private:
        string name;
        double price;
        int quantity;

    public:
        Product::Product(string name, double price, int quantity);

        // Getter function for name, price, and quantity
        string getName() const;
        double getPrice() const;
        int getQuantity() const;

        // Setter function for name, price, and quantity
        void setName(const std::string& productName);
        void setPrice(double productPrice);
        void setQuantity(int productQuantity);

        // Function to save and load product information to and from a file
        void saveToFile(std::ofstream& outFile) const;
        void loadFromFile(std::ifstream& inFile);

        // Function to display product information
        void displayProduct() const;
};

#endif


