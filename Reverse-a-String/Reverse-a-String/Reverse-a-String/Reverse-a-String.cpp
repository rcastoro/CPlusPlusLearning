// REVERSE A STRING //

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{

string str("RedruM RedruM");

for (string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit)
cout << *rit;

return 0;
} 