#include "inventory.hpp"
#include "payment.hpp"
#include <iostream>

using namespace std;

void total_price (Product product, int quantity){
    double total = product.price * quantity;
    cout << "Total price: RM" << total << endl;
}

void calc_change (double price, double money){
    double change = money - price;
    cout << "Change: RM" << change << endl;
}

bool process_payment (Product product, int quantity, double money){
    double total = product.price * quantity;
    if(money >= total){
        cout << "Payment successful!" << endl;
        calc_change(total, money);
        return true;
    }
    else{
        cout << "Insufficient payment!" << endl;
        return false;
    }
}