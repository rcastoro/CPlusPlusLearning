// SumOfCubes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int singleDigit(int num, int digit)	// Function to seperate each of three digits from userNum
{
    for(int i = 0; i < digit; ++i)
        num /= 10;             // DESTROY PREVIOUS DIGITS
    return num % 10;     // remainder of number div 10
}

int calcMagic(int x, int y, int z) {
	int xT = x * x * x;		// variable cubed calculation
	int yT = y * y * y;
	int zT = z * z * z;		//	//
	int sum = xT + yT + zT;	//	Cube sums
	return sum;
}

int main () {
	int userNum;
	cout << "Determine Sum of Cubes is magic number" << endl;

	while (1) {		// repeat program until ctrl+c
	cout << endl;
	// Input Single Number to test for narsisistic number
	cout<<"Input the three digit number: ";
	cin>>userNum;
	int x = singleDigit(userNum, 2);	// x is return of digit extraction function in 3rd decimal place
	int y = singleDigit(userNum, 1);	// y is return of digit extraction function in 2nd decimal place
	int z = singleDigit(userNum, 0);	// z is return of digit extraction function in 1st decimal place
	int sum = calcMagic(x,y,z);

	if (sum == userNum)
		cout << "You have magic number!" << endl;
	else
		cout << "This is NOT a magic number!" << endl;
	}
	return 0;
}