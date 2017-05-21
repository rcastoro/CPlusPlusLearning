#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int main() 
{
	vector<int> randNum;
	char hit = 'y';
	int n = 0;

	srand((unsigned)time(0));
	
	while (hit =='Y' || hit == 'y')
	{
		randNum.push_back(1 + rand() % 100);
		if (randNum.size() > 1){
			for (int i=0; i < randNum.size(); i++){
					while (randNum[n] == randNum[n-1]) {
						cout << "New number generated because original matched previous number: " << randNum[n] << endl;
					randNum.pop_back();
					randNum.push_back(1 + rand() % 100);
					
					}
			}
		}
		cout << n << ".) Generated number is: " << randNum[n] << endl;
		cout << "Would you like to generate another number? (y or n): ";
		cin >> hit;
		n++;
	} //end of loop

	cout << endl << endl << "Numbers" << endl << "----------------" << endl;
	for (int j=0; j<n; j++){
		cout << randNum[j] << endl;
	}
}