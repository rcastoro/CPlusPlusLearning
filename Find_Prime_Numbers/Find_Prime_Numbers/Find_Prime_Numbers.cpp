#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;


int main()
{
	bool set = false;
	cout << 2 << " ";
	for (int x=3; x <= 1000; x++) {
		set = false;
		for (int i=1; i < x; i++) {
			if ( i != 1 ) {
				if ( x % i != 0 ){
					set = true;
				}else{
					set = false;
					break;
				}
			}
		}
		if (set == true) {
			cout << x << " ";
		}
	}
}

