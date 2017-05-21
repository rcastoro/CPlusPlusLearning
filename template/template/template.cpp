#include "stdafx.h"
#include <iostream>
using namespace std;

int additionFunc();
int subtractFunc();
int multiplyFunc();
int divideFunc();

void calcMenu()
{
   int getOption = 0;
   cout << "Select a option" << endl << endl;
   cout << "1.) Add 2.) Subtract 3.) Multiply 4.) Divide";
   cin >> getOption;
   switch (getOption)
      {
      case 1:
         additionFunc();
         break;
      case 2:
         subtractFunc();
         break;
      case 3:
         multiplyFunc();
         break;
      case 4:
         divideFunc();
         break;
      default:
         cout << "You selected a wrong option, try again" << endl;
         break;
      }

}

int main ()
{
   cout << "Welcome to calculator" << endl;
   calcMenu();
}