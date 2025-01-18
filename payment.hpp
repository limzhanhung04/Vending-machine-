#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include "inventory.hpp"
#include <iostream>

using namespace std;

void total_price (Product product, int quantity);   
void calc_change (double price, double money);
bool process_payment (Product product, int quantity, double money);

#endif