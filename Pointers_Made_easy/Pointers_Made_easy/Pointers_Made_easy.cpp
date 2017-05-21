// Pointers are declared with int* ptr, which states ptr is a pointer variable of size int
// and you can only assign a memory cell addresses (byte each) to it. To assign a
// memory cell address to a pointer, assign the variable whos address you would like
// stored in the ptr using the address of operator (&);

////////////////////////////
// i.e....
// int* ptr, regVal = 5;	---// ptr is a pointer variable of size int \\---
// ptr = &regVal;			---// Assign ptr to the memory address of regVal using & \\---
// *ptr = 3;					---// So now, regVal = 3!  \\---
// cout << *ptr;				---// Prints 3 \\---
// cout << ptr;				---// Prints address of regVal \\---
////////////////////////////

// You can manipulate pointers with math equations. The pointer can be incremented
// by 1 or more to get the address of the next memory cell, and decremented by 1 
// or more to get the address of the previous memory cell, which can then be used and
// manipulated.

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a[30];
	int* p;
	
	for (int i=0; i<30; i++) {
		a[i] = i;
		p = &a[i];
		*p = i+1;
		cout << *p;
		if (i == 29) {
			for (int x=0; x<29; x++) {
				p--;
				cout << *p;
			}
		}
	}
}