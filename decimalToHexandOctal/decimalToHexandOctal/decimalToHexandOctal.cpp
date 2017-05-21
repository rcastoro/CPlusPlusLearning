// Decimal to Hexadecimal and Octal converter //

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Converter {
protected:
	int num;
	int quotient;				// Declare quotient as pointer, for dynamic array initalization
	int remain;					// Declare remainder
	string result;

public:
	void userInput(int);
};

class Hexadecimal: public Converter {
public:

	string convert(int num) {
		  string hexArray[16];
		  hexArray[0] = "0";
		  hexArray[1] = "1";
		  hexArray[2] = "2";
		  hexArray[3] = "3";
		  hexArray[4] = "4";
		  hexArray[5] = "5";
		  hexArray[6] = "6";
		  hexArray[7] = "7";
		  hexArray[8] = "8";
		  hexArray[9] = "9";
		  hexArray[10] = "a";
		  hexArray[11] = "b";
		  hexArray[12] = "c";
		  hexArray[13] = "d";
		  hexArray[14] = "e";
		  hexArray[15] = "f";

		quotient = (int)num/16; // 8
		remain = num%16; // 4
		result = hexArray[remain]; // 4

		while (quotient != 0)
		{
			remain = quotient%16; // 7
			quotient = (int)quotient/16; // 1 
			result = hexArray[remain]+result; // 11
		}
		return result;
	}
};

class Octal: public Converter {
public:

	string convert(int num) {
		string octalArray[8];
		octalArray[0] = '0';
		octalArray[1] = '1';
		octalArray[2] = '2';
		octalArray[3] = '3';
		octalArray[4] = '4';
		octalArray[5] = '5';
		octalArray[6] = '6';
		octalArray[7] = '7';

		// decimal = 23
		quotient = num/8; // 2
		remain = num%8; // 7
		result = octalArray[remain]; // 7

		while (quotient != 0)
		{
			remain = quotient%8; // 2
			quotient = (int)quotient/8; // 0
			result = octalArray[remain]+result; // ((string)2)  +  7 = 27 (octal number for 23)
		}
		return result;
	}
};

void Converter::userInput (int decimal) {
	num = decimal;
}


int main()
{
	char repeat = 'y';
	char resp = 'c';
	int decimal(0);		// Declare decimal
	Hexadecimal hex;
	Octal oct;

	cout << "Decimal to Hexadecimal and Octal converter" << endl << endl;

	while (repeat == 'y') {
		cout << "Please enter a decimal number: "; cin >> decimal;
		cout << endl;
		cout << "Would you like to convert " << decimal << " to hexadecimal or octal?" << endl;
		cout << "a.) hexadecimal" << endl;
		cout << "b.) octal" << endl;
		cout << "Reponse: "; cin >> resp;

		// Handle menu
		if (resp == 'a')
			cout << endl << endl <<  "Hexadecimal: 0x" << hex.convert(decimal);
		else if (resp == 'b')
			cout << endl << endl <<  "Octal: " << oct.convert(decimal);
		else
			cout << endl << "Please enter a or b" << endl;
		
		cout << "\n\n\n\aWould you like to convert another decimal (y or n): ";
		cin >> repeat;
		cout << endl;
	}
return 0;
}