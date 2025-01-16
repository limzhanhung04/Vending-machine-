#ifndef payment _hpp
#define payment _hpp

#include "inventory.hpp"
#include <iostream>

using namespace std;

void total_price (Product product, int quantity);   
void calc_change (double price, double money);
bool process_payment (Product product, int quantity, double money);

#endif