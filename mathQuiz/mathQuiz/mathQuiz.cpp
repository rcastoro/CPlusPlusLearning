// mathQuiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

string name;
int randNum1;
int randNum2;
int tempNum;
int signRoll;
int answer;
int userAnswer;
string addition = "+";
string subtract = "-";
string sign;
string divider = "--------";
string answerQuestion= "What is your answer?";
string good =" Nice Job";
string bad = "I'm sorry, that is not correct";
string response = "y";
int main()

{
cout <<"Welcome, Please enter your Name:";
cin>> name;
cout <<"Thanks!,"<< name;

while(response == "y" || response == "y") {

	srand((unsigned)time(0));
	randNum1 = 1 + rand() % 20;
	randNum2 = 1 + rand() % 20;
	signRoll= 1 + rand() % 3;

	// Decide to use addition or subtraction
	if(signRoll == 1){
		sign = addition;
		answer = randNum1 + randNum2 ;
	}else{
		sign = subtract;
		if (randNum1 < randNum2){
			randNum1=tempNum;
			randNum1=randNum2;
			randNum2=tempNum;
		}
		answer = randNum1 - randNum2 ;
	}

	cout<< fixed << showpoint<< setprecision(1);
	cout<<left<<setw(4)<<right<<setw(5)<< randNum1 <<endl;
	cout<<left<< setw(2)<<sign <<right<<setw(3)<< randNum2 <<endl;
	cout << divider << endl;
	cout <<""<< endl;
	cout<< answerQuestion << endl;
	cin >> userAnswer;

	if(answer == userAnswer)
	{
		cout <<good;
	}else{
		cout << bad << endl;
		cout <<"The Correct answer is: "<< answer << endl;
		cout << endl;
	}
	cout << " Do you want another problem? (Y/N)";
	cin >> response;
}
return 0;
}