// 4_PancakeGlutton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define PEOPLE 10

struct person {
	unsigned id;
	unsigned pancakes;
}p[PEOPLE];

void doEating(person p[]) {
	for (int i=0; i<10; i++){
		p[i].id = i+1;
		cout << "Enter the amount of pancake's ate by person " << i+1 << ": ";
		cin >> p[i].pancakes;
	}
}

void bubbleSort(person p[]) {
      bool swapped = true;
      int j = 0;
      while (swapped) {
            swapped = false;
            for (int i = 0; i < PEOPLE - j; i++) {
				if (p[i].pancakes > p[i + 1].pancakes) {
						swap(p[i], p[i+1]) ;
						swapped = true ;
				}
			}
	  }
}

void printList(person p[]) {
	for (int i=0; i<PEOPLE;i++){
		cout << "Pancakes eaten by person " << p[i].id << ": " << p[i].pancakes << endl;
	}
}


int main() {
	cout << "Pancake Glutton" << endl << endl;
	doEating(p);
	bubbleSort(p);
	printList(p);
}