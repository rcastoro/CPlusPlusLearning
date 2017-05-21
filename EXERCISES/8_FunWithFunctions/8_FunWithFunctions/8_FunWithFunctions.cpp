// 8_FunWithFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int half(int num)
{
	cout << num << endl;
	int dividend = num / 2;

	if (dividend > 0){
		half(dividend);
	}else{
		return 0;
	}
}

void getProduct(int int1, int int2)
{
	int product = int1 * int2;
	cout << product << endl;
}

void sayHello(int times)
{
 for (int i=0; i< times; i++)
	cout << "Hello\n";
}

int main()
{
	sayHello(10);
	getProduct(4, 5);
	half(100);
}