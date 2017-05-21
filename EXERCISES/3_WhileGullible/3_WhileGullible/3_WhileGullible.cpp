// 3_WhileGullible.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


bool gullibleLoop()
{
	int input;
	int count = 0;
	for(int i=0; i<10;i++) {
		cout << "Please enter any number, except for " << i << ": ";
		cin >> input;
		if (input == i){
			cout << "Hey! you weren't supposed to enter " << i << "!" << endl;
			Sleep(500);
			return true;
		}
	}
	cout << "You're more patient than I am! You Win!" << endl;
	return true;
}

int main ()
{
	bool exit;
	cout << "Gullability Tester" << endl << "------------------" << endl << endl;
	exit = gullibleLoop();
}
