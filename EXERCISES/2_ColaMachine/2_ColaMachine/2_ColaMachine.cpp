// 2_ColaMachine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int menu() {
	bool flag = true;
	char input = ' ';
	cout << "--------------------" << endl << "Select a soft drink" << endl << "====================" << endl << "--------------------" << endl;
	cout << "A.) Coca Cola" << endl;
	cout << "B.) Pepsi Cola" << endl;
	cout << "C.) Dr. Pepper" << endl;
	cout << "D.) Fanta" << endl;
	cout << "E.) RedBull (it gives you wings)" << endl;
	cout << "----------------" << endl << "Select an option" << endl << "----------------" << endl << "################" << endl << "################" << endl << "  A  B  C  D  E  " << endl << "################" << endl << "################" << endl << "---------------" << endl;
	
	while (flag = true) {
		cout << "Enter Choice: ";
		cin >> input;

		// Determine selection to return
		cout << endl << endl << endl << endl << endl << endl;
		cout << endl << endl << "!&#@ BING @#*!" << endl << endl;
		cout << endl << endl << "$##! BANG *&$#" << endl << endl;
		cout << endl << endl << "$$#@ CLINK $#@@" << endl << endl;
		cout << endl << endl << endl << endl << endl << endl;
		switch (input) {
		case 'A':
		case 'a':
			cout << "Here is your Coca Cola. Enjoy." << endl;
			return 1;
			break;
		case 'B':
		case 'b':
			cout << "Here is your Pepsi Cola. Enjoy." << endl;
			return 2;
			break;
		case 'C':
		case 'c':
			cout << "Here is your Dr. Pepper. Enjoy." << endl;
			return 3;
			break;
		case 'D':
		case 'd':
			cout << "Here is your Fanta. Enjoy." << endl;
			return 4;
			break;
		case 'E':
		case 'e':
			cout << "Here is your Redbull. Enjoy your wings." << endl;
			return 5;
			break;
		default:
			cout << "Whoops, we vended you a drink that we do not serve." << endl << "Good thing this is virtual or time and matter would collapse." << endl << endl;
			flag = true;
		}
	}
}

int main()
{
	string pay;
	char flag = 'y';
	cout << "Virtual Vending Machine" << endl << "-------------------------" << endl;
	cout << "Defying rules of relativity for trillions of years." << endl;
	cout << "----------------------------------------------------";
	while (flag == 'y') {
		flag = 'n';
		cout << endl << endl << "Insert 25 cents? (y or n): ";
		cin >> flag;
		if (flag == 'y'){
			menu();
		}
	}
}
