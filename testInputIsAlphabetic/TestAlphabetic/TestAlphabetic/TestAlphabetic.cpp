#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool IsCharAlpha(char cAnswer);

int main()
{
    char cInput, cAnswer;

    cout << "Please enter a character: " << endl;
    cin >> cInput;
    cAnswer = cInput;
    bool result = IsCharAlpha(cAnswer);

    if (result == 1)
    {
        cout << "Your character is an alphabetic character!" << endl;
    }

    else if (result == 0)
    {
        cout << "That is not a valid character." << endl;
    }
}

bool IsCharAlpha(char cAnswer)
{
    if (isalpha(cAnswer))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}