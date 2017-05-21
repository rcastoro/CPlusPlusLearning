// Structure used, with vectors (arrays)
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct songs {
string artist;
string track;
};

int main()
{
	char repeat = 'y';
	int count = 0;
	vector<songs> mySongList;

	cout << "Song Tracker" << endl << endl;
	while (repeat == 'y')
	{
		mySongList.push_back( songs() );
		cout << "What is your favorite song" << endl;
		cout << "-----------------------------" << endl;
		cout << "Enter the artist name: ";
		getline(cin, mySongList[count].artist);
		cout << endl << "Enter your favorite track from " << mySongList[count].artist << ": ";
		getline(cin, mySongList[count].track);
		cout << endl << endl << "Would you like to enter some more songs? (y or n): ";
		cin >> repeat;
		count++;
		cin.ignore();
	}

	for (int i=0; i<count; i++){
		cout << "Favorite artist #" << i << " is: " << mySongList[i].artist << endl;
		cout << "Favorite track from " << mySongList[i].artist << " is: " << mySongList[i].track << endl;
	}


return 0;
}