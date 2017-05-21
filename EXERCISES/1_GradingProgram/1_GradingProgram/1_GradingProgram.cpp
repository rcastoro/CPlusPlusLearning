// 1_GradingProgram.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
using namespace std;

float getUserScore(float score){
	bool flag = true;
	while (flag == true) {
		cout << "Please enter a score between 0 and 100: ";
		cin >> score;
		if (score >= 0 && score <= 100) {
			return score;
			flag = false;
			break;
		}else{
			score = 0;
			flag = true;
			continue;
		}
	}
}

char getUserGrade(int score){
	char grade = ' ';
	if (score >= 90)
		grade = 'A';
	else if (score <= 89 && score >= 80)
		grade = 'B';
	else if (score <= 79 && score >= 70)
		grade = 'C';
	else if (score <= 69 && score >= 60)
		grade = 'D';
	else
		grade = 'F';

	return grade;
}

int main()
{
	float score = 0;
	char grade = ' ';
	score = getUserScore(score);
	grade = getUserGrade(score);
	cout << "Your score of " << score << " earns you a " << grade << " for the assignment." << endl;
}