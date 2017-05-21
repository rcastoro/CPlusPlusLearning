#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Machine {
public:
	Machine(string manufac, string mdl, double p, int q)
	{
		manufacturer = manufac;
		model = mdl;
		price = p;
		quantity = q;
	}
	void setManufacturer(string manufac)
	{
		manufacturer = manufac;
	}
	void setModel(string mdl)
	{
		model = mdl;
	}
	void setPrice(double p)
	{
		price = p;
	}
	void setQuantity(int q)
	{
		quantity = q;
	}

	string getManufacturer(void)
	{
		return manufacturer;
	}
	string getModel(void)
	{
		return model;
	}
	double getPrice(void)
	{
		return price;
	}
	double getPrice(int q)
	{
		return price * q;
	}
	int getQuantity(void)
	{
		return quantity;
	}
private:
	string manufacturer;
	string model;
	double price;
	int quantity;
};
void addInventory(vector<Machine>& m)
{
	int mIndex = 0;
	char resp = 'Y';
	string manufac;
	string mdl;
	double p;
	int q;
	while (resp == 'Y' || resp == 'y') {
		cout << "Add Inventory\n--------------\n\n";
		cout << "Please enter item's manufacturer: ";
		getline(cin, manufac);
		cout << "Please enter item's model name: ";
		getline(cin, mdl);
		cout << "Please enter item's price: ";
		cin >> p;
		cout << "Please enter quantity available of this item: ";
		cin >> q;
		cin.ignore();
		Machine mTemp(manufac, mdl, p, q);
		m.push_back(mTemp);
		cout << "\n\nWould you like to add another item? (Y or N): ";
		mIndex++;
		cin >> resp;
		cin.ignore();
	}
}

void viewInventory(vector<Machine>& m)
{
	cout << "View Machine Inventory\n------------------------\n\n";
	for (unsigned int i=0; i<m.size(); i++)
	{
		cout << "Machine Item # " << i << "\n---------------------\n";
		cout << "Manufacturer: " << m[i].getManufacturer() << endl;
		cout << "Model: " << m[i].getModel() << endl;
		cout << "Price: " << m[i].getPrice() << endl;
		cout << "Quantity: " << m[i].getQuantity() << endl;
	}
}

int main()
{
	int exit = 0;
	vector<Machine> m;
	while (true) {
		int menuUserInput;
		cout << "Rocco Construction Inventory\n\n";
		cout << "Select an option\n-------------------\n";
		cout << "1.) Add item to inventory\n";
		cout << "2.) Search item in inventory\n";
		cout << "3.) View all items in inventory\n";
		cout << "4.) Exit\n\n";
		cin >> menuUserInput;
		cin.ignore();
		switch (menuUserInput) {
			case 1:
				addInventory(m);
				break;
			/* case 2:
				searchInventory(m);
				break; */
			case 3:
				viewInventory(m);
				break;
			case 4:
				exit = 1;
				break;
			default:
				cout << "You didn't enter a valid option. Please try again.\n\n";
				break;
		}
		if (exit == 1) {
			break;
		}
	}
}