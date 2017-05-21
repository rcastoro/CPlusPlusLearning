// 9_StringsAreFriends.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	char repeat = 'y';
	while (repeat == 'y'){
		system("cls");
	string fname;
	string lname;
	string name;
	string vowelArr[6] = { "a", "e", "i", "o", "u", "y" };
	string vowel;
	unsigned found;
	cout << "Enter your first name: ";
	cin >> fname;
	cout << "Enter you last name: ";
	cin >> lname;
	name = fname + " " + lname;
	cout << "Name combined: " << name << "\n";
	cout << "Name reversed: ";
	for(string::reverse_iterator rit = name.rbegin(); rit != name.rend(); ++rit){
		cout << *rit;
	}
	cout << "\nName without vowels: ";
	
	for (int i=0; i < name.length(); i++)
	{
		for (int x=0; x < 6; x++) {
			vowel = vowelArr[x];
			found = name.find(vowel);
		if (found!=string::npos)
			name.replace(found, 1, "z");
		}
	}
	cout << name << endl;
	cout << "Go again? y or n? : ";
		cin >> repeat;
	}
}