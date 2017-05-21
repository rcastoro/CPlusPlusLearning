#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

char readData(int A[], int B[], int& sumA, int& sumB) {
	cout << endl << endl << "Array A: " << endl << "-------------" << endl;
	for (int i=0; i<10; i++){
		cout << "Enter number " << i << " for array A: ";
		cin >> A[i];
		sumA += A[i];
	}
	cout << endl << endl << "Array B: " << endl << "-------------" << endl;
	for (int i=0; i<10; i++){
		cout << "Enter number " << i << " for array B: ";
		cin >> B[i];
		sumB += B[i];
	}
	if (sumA > sumB)
		return 'a';
	else
		return 'b';
}

void printLarger(char &arrayLarger, int A[], int B[]) {

	if (arrayLarger == 'a'){
	cout << "Array A is larger" << endl << "-----------------" << endl << "It Contained:" << endl << "-----------------" << endl;
		for (int i=0; i<10; i++) {
			cout << A[i] << endl;
		}
	}else{
	cout << "Array B is larger" << endl << "-----------------" << endl << "It Contained:" << endl << "-----------------" << endl;
		for (int i=0; i<10; i++) {
			cout << B[i] << endl;
		}
	}		
}

int main()
{
	int arrayA[10];
	int arrayB[10];
	char arrayLarger;
	int sumA;
	int sumB;
	arrayLarger = readData(arrayA, arrayB, sumA, sumB);
	printLarger(arrayLarger, arrayA, arrayB);
}