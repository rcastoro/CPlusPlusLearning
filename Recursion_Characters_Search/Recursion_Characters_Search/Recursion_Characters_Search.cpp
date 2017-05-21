// Template

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void findX (string s, vector<unsigned>& found, unsigned& idx, unsigned& pos, char& findChar)
{
	if (idx != 0){
		pos = found[idx-1] + 1;
	}

	found.push_back (s.find(findChar, pos+1));

	
	if (found[idx]!=string::npos){		// if more matches, then...
			cout << findChar << " is " << found[idx] << " places into the string." << endl;
		idx++;
		findX(s, found, idx, pos, findChar);		// Recursion
	}
}

int main()
{
	char findChar = ' ';
	unsigned idx = 0;
	string str = " ";
	unsigned pos = 0;
	vector<unsigned> found;

	cout << "Please input a string of text: \n";
	getline(cin, str);
	cout << "Please enter a character to find in this string: ";
	cin >> findChar;
	findX(str, found, idx, pos, findChar);		// Call recusrive function
}