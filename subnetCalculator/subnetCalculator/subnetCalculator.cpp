// Subnet Calculator, by rocco castoro

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <math.h>
using namespace std;



int getOctetsIP(string ip, vector<int> &octetsIP) {		// Define vector<int> octets, using reference from main
	stringstream sip(ip);								// use stringstream named ss and populate with ip
	string temp;
	octetsIP.clear();									// Clears the octetsMask vector, in case main function re-runs this function
	vector<bool> ipInRange;
	while (getline(sip,temp,'.'))						// Every time getline recieves new stream element from ss, save to temp
		octetsIP.push_back(atoi(temp.c_str()));			//... until reaches '.' delimiter, then push_back octet with new element.
	if (octetsIP.size() == 4) {
		for(int i = 0; i < octetsIP.size(); i++){
			if (octetsIP[i] >= 0 && octetsIP[i] <= 255)
				ipInRange.push_back(true);
			else
				ipInRange.push_back(false);
		}
		if (ipInRange[0]==true&&ipInRange[1]==true&&ipInRange[2]==true&&ipInRange[3]==true){
			return 0;
		}else{
			cout << endl << "There are only 255 bits per octet. Please re-enter IP." << endl << endl;
			return 1;
		}
	}else{
		cout << endl << "Please enter four octets in dot notation." << endl << endl;
		return 1;
	}
}




int getOctetsMask(string mask,  vector<int> &octetsMask) {
	stringstream smask(mask);
	string temp;
	octetsMask.clear();		// Clears the octetsMask vector, in case main function re-runs this function
	vector<bool> maskInRange;
	while (getline(smask,temp,'.'))
		octetsMask.push_back(atoi(temp.c_str()));
	if (octetsMask.size() == 4){
		for(int i = 0; i < octetsMask.size(); i++){
			if (octetsMask[i] == 0 || octetsMask[i] == 128 || octetsMask[i] == 192 || octetsMask[i] == 224 || octetsMask[i] == 240 || octetsMask[i] == 248 || octetsMask[i] == 252 || octetsMask[i] == 254 || octetsMask[i] == 255)
				maskInRange.push_back(true);
			else
				maskInRange.push_back(false);
		}
		if(maskInRange[0]==true&&maskInRange[1]==true&&maskInRange[2]==true&&maskInRange[3]==true){
			return 0;
		}else{
			cout << endl << "Subnet masks only use 2^[0-7]. Please re-enter mask." << endl << endl;
			return 1;
		}
	}else{
		cout << endl << "Please enter four octets in dot notation." << endl << endl;
		return 1;
	}
}




int calcClass(vector<int> &octetsIP) {
	if (octetsIP[0] == 10) {
		return 1;	// Class A Private address blocks //
	}else if (octetsIP[0] == 172 && octetsIP[1] >= 16 && octetsIP[1] <= 31) {
		return 2;	// Class B Private address blocks //
	}else if (octetsIP[0] == 192 && octetsIP[1] == 168) {
		return 3;	// Class C Private address blocks //
	}else if (octetsIP[0] == 127) {
		return 4;	// Loopback Address Reserved address blocks //
	}else if (octetsIP[0] >= 0 && octetsIP[0] < 127) {
		return 5;
	}else if (octetsIP[0] > 127 && octetsIP[0] < 192) {
		return 6;
	}else if (octetsIP[0] > 191 && octetsIP[0] < 224) {
		return 7;
	}else if (octetsIP[0] > 223 && octetsIP[0] < 240) {
		return 8;
	}else if (octetsIP[0] > 239 && octetsIP[0] <= 255) {
		return 9;
	}else{
		return 0;	// Out of Range //
	}
}




// Determine Binary /--
int getNHBits(vector<int> &octetsIP, vector<int> &octetsMask, vector<int> &octetsIPBits, vector<int> &octetsMaskBits){

	// Get IP binary rep. // 
cout << "------------------------------------------" << endl;
cout << "///////// Binary Representation //////////" << endl;
cout << "------------------------------------------" << endl;
	for (int j=0; j < octetsIP.size(); j++)
    {
		if (j>0)
			cout << ".";

        int mask = 128;
        while (mask)
        {
            octetsIPBits.push_back((octetsIP[j] & mask) != 0);
			cout << ((octetsIP[j] & mask) != 0);
            mask >>= 1;
        }
    }
	cout << "  : IP Address" << endl;

	// Get SUBNET binary rep. // 
	for (int j=0; j < octetsMask.size(); j++)
    {
		if (j>0)
			cout << ".";
        int mask = 128;
        while (mask)
        {
            octetsMaskBits.push_back((octetsMask[j] & mask) != 0);
			cout << ((octetsMask[j] & mask) != 0);
            mask >>= 1;
        }
    }
	cout << "  : Subnet Mask" << endl;
	cout << "-----------------------------------------" << endl;

return 0;
}



// Perform ANDing of IP and Subnet Mask to generate Network ID range //
vector<int> getNetID(vector<int> &octetsIPBits, vector<int> &octetsMaskBits){
	vector<int> netID;
    for (int j=0; j < octetsIPBits.size(); j++)
    {
        if ((j > 0) && (j%8 == 0))
            cout << ".";

		netID.push_back(octetsIPBits[j] & octetsMaskBits[j]);
    }
return netID;
}


// Turn Binary back to Decimal
string toString(vector<int> octets){
	ostringstream octStrm;

	for(int j = 0; j < octets.size(); j++)
	{
		if (j>0)
			octStrm << '.';

		octStrm << octets[j];
	}
	
	return octStrm.str();
}


// Turn Binary back to Decimal
vector<int> toDecimal(vector<int> octets, vector<int> &decimals){
	stringstream octStrm;
	decimals.clear();
	for(int j = 0; j < octets.size(); j++)
	{
		if (j>0)
			octStrm << '.';

		octStrm << octets[j];
	}

	string temp;
	while (getline(octStrm, temp, '.'))
		decimals.push_back(atoi(temp.c_str()));
	
	return decimals;
}

// Get the network increment //
int getIncrement(vector<int> decimalMask, vector<int> decimalNetID){
	int increment = 0;
	for (int i=0; i<decimalMask.size(); i++){
		if (decimalMask[i] == 255){
			increment = 1;
		}else if(decimalMask[i] == 254){
			increment = 2;
			break;
		}else if(decimalMask[i] == 252){
			increment = 4;
			break;
		}else if(decimalMask[i] == 248){
			increment = 8;
			break;
		}else if(decimalMask[i] == 240){
			increment = 16;
			break;
		}else if(decimalMask[i] == 224){
			increment = 32;
			break;
		}else if(decimalMask[i] == 192){
			increment = 64;
			break;
		}else if(decimalMask[i] == 128){
			increment = 128;
			break;
		}
	}
return increment;
}

// get network id range
vector<int> getNetIDRange(vector<int> &decimalNetID, int &netInc, vector<int> &decimalMask) {
	vector<int> netIDEnd;
	for (int i=0; i<decimalNetID.size(); i++){
		if (decimalMask[i] == 255){
			netIDEnd.push_back(decimalNetID[i]);
		}else if (decimalMask[i] < 255 && decimalMask[i] > 0){
			netIDEnd.push_back( (decimalNetID[i] + netInc) - 1 );
		}else{
			netIDEnd.push_back(255);
		}
	}
	return netIDEnd;
}



// Get subnets
int getSubnets(vector<int> &decimalMask, int &ipClass, vector<int> &subClassMask){
	int netBits = 0;
	subClassMask.clear();
		if (ipClass==1){
			subClassMask.push_back(255);
			subClassMask.push_back(0);
			subClassMask.push_back(0);
			subClassMask.push_back(0);
		}else if(ipClass==2){
			subClassMask.push_back(255);
			subClassMask.push_back(255);
			subClassMask.push_back(0);
			subClassMask.push_back(0);
		}else if(ipClass==3){
			subClassMask.push_back(255);
			subClassMask.push_back(255);
			subClassMask.push_back(255);
			subClassMask.push_back(0);
		}else if(ipClass==4 || ipClass==5){
			subClassMask.push_back(decimalMask[0]);
			subClassMask.push_back(decimalMask[1]);
			subClassMask.push_back(decimalMask[2]);
			subClassMask.push_back(decimalMask[3]);
		}

	for (int i=0; i<decimalMask.size(); i++){
		if (decimalMask[i] != subClassMask[i]){
			if (decimalMask[i] == 255){
				netBits += 8;
				continue;
			}else if (decimalMask[i] == 254){
				netBits += 7;
				continue;
			}else if (decimalMask[i] == 252){
				netBits += 6;
				continue;
			}else if (decimalMask[i] == 248){
				netBits += 5;
				continue;
			}else if (decimalMask[i] == 240){
				netBits += 4;
				continue;
			}else if (decimalMask[i] == 224){
				netBits += 3;
				continue;
			}else if (decimalMask[i] == 192){
				netBits += 2;
				continue;
			}else if (decimalMask[i] == 128){
				netBits += 1;
				continue;
			}else if (decimalMask[i] == 0){
				netBits += 0;
				continue;
			}else{
				netBits += 0;
			}
		}
	}
	int subnets = pow(2.0,netBits);
	return subnets;
}



// Get hosts per subnet
int getHostsPerSubnet(vector<int> &decimalMask){
	int hostBits = 0;
	for (int i=0; i<decimalMask.size(); i++){
		if (decimalMask[i] == 255){
			hostBits += 0;
			continue;
		}else if (decimalMask[i] == 254){
			hostBits += 1;
			continue;
		}else if (decimalMask[i] == 252){
			hostBits += 2;
			continue;
		}else if (decimalMask[i] == 248){
			hostBits += 3;
			continue;
		}else if (decimalMask[i] == 240){
			hostBits += 4;
			continue;
		}else if (decimalMask[i] == 224){
			hostBits += 5;
			continue;
		}else if (decimalMask[i] == 192){
			hostBits += 6;
			continue;
		}else if (decimalMask[i] == 128){
			hostBits += 7;
			continue;
		}else if (decimalMask[i] == 0){
			hostBits += 8;
			continue;
		}else{
			hostBits = 0;
			break;
		}
	}
	int hostsPerSubnet = pow(2.0,hostBits)-2;
	return hostsPerSubnet;
}


int main() {

// Give details, given an IP and Subnet Mask //
char resp = 'y';
while (resp == 'y') {
	cout << " //// -- IPv4 Subnetting Calculator -- \\\\\\\\" << endl;
	cout << "||||  ----- dev. by Rocco Castoro ----- ||||" << endl;
	cout << " \\\\\\\\ ----- rockycast@hotmail.com ---- ////" << endl;
	cout << endl << endl;

		// Get IP address octets //
		string ip;
		vector<int> octetsIP;
		while (getOctetsIP(ip, octetsIP) == 1) {
		cout << "Enter IPv4 Address -> ";
		(getline(cin, ip));		// Accept user input for IP Address //
		}

		// Get subnet mask octets //
		string mask;
		vector<int> octetsMask;
		while (getOctetsMask(mask, octetsMask) == 1) {
		cout << endl << "Enter subnet mask for " << ip << " -> ";
		(getline(cin, mask));	// Accept user input for subnet mask //
		}
		cout << endl << endl << endl << endl << endl;

		// Print Initial User IP and Subnet Mask //
		vector<int> decimals;
		cout << "//////////////////////////////////////////" << endl;
		cout << "/// IP Address: " << toString(octetsIP) << endl;
		vector<int> decimalMask = toDecimal(octetsMask, decimals);
		cout << "/// Subnet Mask: " << toString(octetsMask) << endl;
		cout << "//////////////////////////////////////////" << endl << endl;

		// Print Binary Representation //
		vector<int> octetsIPBits;
		vector<int> octetsMaskBits;
		getNHBits(octetsIP, octetsMask, octetsIPBits, octetsMaskBits);
		vector<int> netID = getNetID(octetsIP, octetsMask);
		vector<int> decimalNetID = toDecimal(netID, decimals);
		int netInc = getIncrement(decimalMask, decimalNetID);
		cout << endl;

		// Print IP Class
			// Run function to determine and print IP class
			cout << "------------------------------------------" << endl;
			cout << "//////////// Class Information ///////////" << endl;
			cout << "------------------------------------------" << endl;
			int classResult = calcClass(octetsIP);
			int ipClass = 0;
			switch (classResult){
				case 1:
					cout << "IP Class: Private block, Class 'A' " << endl;
					ipClass = 1;
					break;
				case 2:
					cout << "IP Class: Private block, Class 'B'" << endl;
					ipClass = 2;
					break;
				case 3:
					cout << "IP Class: Private block, Class 'C'" << endl;
					ipClass = 3;
					break;
				case 4:
					cout << "IP Class: Reserved block, System Loopback Address" << endl;
					ipClass = 1;
					break;
				case 5: 
					cout << "IP Class: A" << endl;
					ipClass = 1;
					break;
				case 6:
					cout << "IP Class: B" << endl;
					ipClass = 2;
					break;
				case 7:
					cout << "IP Class: C" << endl;
					ipClass = 3;
					break;
				case 8:
					cout << "IP Class: D" << endl;
					ipClass = 4;
					cout << "!! This is a reserved Class D Multicast IP Address Block" << endl;
					break;
				case 9:
					cout << "IP Class: E" << endl;
					ipClass = 5;
					cout << "!! This is a reserved Class E Multicast IP Address Block" << endl;
					break;
				default :
					cout << "Not in Range" << endl;
					break;
			}
		vector<int> subClassMask;
		getSubnets(decimalMask, ipClass, subClassMask);
		cout << "Default Class Subnet Mask: " << toString(subClassMask) << endl;
		cout << "-----------------------------------------" << endl << endl;

		// Print Subnetting Details //
		cout << "------------------------------------------" << endl;
		cout << "///////////// Subnet Details /////////////" << endl;
		cout << "------------------------------------------" << endl;
		vector<int> netIDRange = getNetIDRange(decimalNetID, netInc, decimalMask);
		cout << "Network ID:            -           Broadcast ID: " << endl;
			cout << "-------------------------------------------------" << endl;
			cout << toString(netID) << " - [ usable hosts ] - ";
		cout << toString(netIDRange) << endl << endl;
		cout << "Network Increment: " << getIncrement(decimalMask, decimalNetID) << endl;
		cout << "Number of Subnets: " << getSubnets(decimalMask, ipClass, subClassMask) << endl;
		cout << "Usable hosts per subnet: " << getHostsPerSubnet(decimalMask) << endl;
		cout << "-----------------------------------------" << endl << endl;

		cout << "Would you like to enter another IP Address to subnet? (y or n): ";
		cin >> resp;
		cout << endl << endl << endl << endl;
}
	return 0;
}