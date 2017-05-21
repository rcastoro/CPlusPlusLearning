#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void getArray(string arg[], int length);

int main()
{
char repeat = 'y';

int i = 0;
int n = 0;
cout << "How many elements would you like to create: ";
cin >> n;
string* arrString;
arrString= new (nothrow) string[n];

for (int i=0;i<n;i++){
		cout << "Enter a string for array " << i << ": ";
		cin >> arrString[i];
	}
	getArray(arrString, n);
}

void getArray(string arg[], int length)
{
	for(int i=0; i<length; i++)
	cout << arg[i] << endl;
}
