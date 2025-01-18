#include <iostream>
#include <cmath>
#include <iomanip>
#include "staff.cpp"

int main() {

char user;
  
cout << " WELCOME TO VELOR VENDING MACHINE ";
do {
cout << "/n/nEnter ('c') for customer and ('s') for staff: ";
cin >> user ;
if ( user == 's'|| user =='S')
{
  bool staff_login = staffLogin();
  if (staff_login==true)
    staffMenu();
  else
    continue;
    
}
else if ( user == 'c' || user == 'C')
{
  
}
else
{
  cout << "ERROR INVALID CODE. Re-enter your code.";
}
}while(user != 's' || user != 'S' || user != 'c' || user != 'C')
  }
  return 0;  
}
