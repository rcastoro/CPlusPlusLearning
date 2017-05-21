#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class NameDataSet
{
public:
	string sName;
	// Link to next entry in the list
	NameDataSet* pNext;
};

// The pointer to the first entry in the list
NameDataSet* pHead = 0;


// Add a new member to the linked list
void add (NameDataSet* pNDS)
{
	// Point the current entry to the beginning of the list
	pNDS->pNext = pHead;

	// point the head pointer to the current entry
	pHead = pNDS;
}

NameDataSet* getData()
{
	// read first name
	string name;
	cout << "\nEnter name::";
	cin >> name;

	// if the name entered is 'exit'....
	if (name == "exit")
	{
		//return null to terminate input
		return 0;
	}

	// get a new entry and fill in values
	NameDataSet* pNDS = new NameDataSet;
	pNDS->sName = name;
	pNDS->pNext = 0; // zero link

	// return the address of the object created
	return pNDS;
}

int main(int nNumberofArgs, char* pszArgs[])
{
	cout << "Read names of students\n"
		<< "Enter 'exit' for first name to exit"
		<< endl;

	// create another NameDataSet object
	NameDataSet* pNDS;

	while (pNDS = getData())
	{
		// Add it to the list of NameDataSet Objects
		add(pNDS);
	}

	// display the objects
	for (NameDataSet *pIter = pHead; pIter;  pIter = pIter->pNext)
	{
		cout << pIter->sName << endl;
	}

}