// 5_BracketingSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>	  /* time */
using namespace std;

int genGuess(int highorlow)
{
static unsigned guess = 0;
static unsigned guessHigh = 100;
static unsigned guessLow = 1;
	if (highorlow == 0) {
		srand(unsigned(time(NULL)));
		guess = guessLow + ((guessHigh - guessLow) /2);
		cout << guess;
	} else if (highorlow == 1) {
		guessHigh = guess;
		guess = guessLow + ((guessHigh - guessLow) /2);
	} else if (highorlow == 2) {
		guessLow = guess;
		guess = guessLow + ((guessHigh - guessLow) /2);
	}
return guess;
}

bool hotorcold(int num, int guess, int& highorlow)
{
	int userResp = 0;
	if (num != guess) {
		cout << "\n\nThe computer guessed: " << guess << ".\n";
		cout << "Remember, your secret number was: " << num << ".\n\n";
		cout << "Was this too high or too low?\n";
		cout << "1.) Too High\n";
		cout << "2.) Too Low\n";
		cin >> userResp;
		highorlow = userResp;
		return false;
	}
	return true;
}

int main()
{
	int secret = 0;
	int compResp = 0;
	bool position = false;
	int highorlow = 0;
	cout << "Bracketing Search\n";
	cout << "Pick a number between 1 and 100 for the computer to guess \n\n";
	cout << "Input secret number: ";
	cin >> secret;
	while (position == false){
		compResp = genGuess(highorlow);
		position = hotorcold(secret, compResp, highorlow);
	}
	cout << "The computer has guessed your number!" << endl;
}