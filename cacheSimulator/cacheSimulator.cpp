//============================================================================
// Name        : cacheSimulator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "Address.h"
#include "Tools.h"
#include "Cache.h"
typedef unsigned char BYTE;
using namespace std;

string filePath = "/Users/jclu/eclipse-workspace/cacheSimulator/src/1.txt";

int main() {
	cout << "Begins..." << endl; // begins

	// main function start

	// create a cache
	Cache *cache = new Cache();
	//read from txt line by line eg:1f16 ff60 W
	ifstream iFile;

	iFile.open(filePath, ios::in);
	if (!iFile.is_open()) {
		cout << "open fail!";
	} else {

		char *buffer = new char[8];
		char *buffer32 = new char[32];
		char model;
		Tools tools;
		int j = 10;
		while (j > 0 && !iFile.eof()) {
			iFile >> buffer;
			iFile >> model;
			tools.hex2bin(buffer, buffer32, 8);
			bitset<32> addressBit(buffer32);
			// call cache's function depends on the input
			// for W operation
			if (model == 'W') {
				cout << "W" << endl << buffer << endl;
//				cache->wirteCache(addressBit);

			}
			// for R operation
			else if (model == 'R') {
				cout << "R" << endl << buffer << endl;
				cache->readCache(addressBit);
			} else {
				cout << "wrong!" << endl;
			}

			j--;
		}
		delete[] buffer32;
		delete[] buffer;

		// delete cache
		iFile.close();
	}

	delete cache;
	return 0;
}

