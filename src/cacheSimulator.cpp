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

#include "Tools.h"
#include "Cache.h"
typedef unsigned char BYTE;
using namespace std;

char* filePath = "/Users/jclu/eclipse-workspace/cacheSimulator/src/test1.txt";

int main(int argc, char* argv[]) {
	if(argc > 2){
		cout<<"Args wrong!"<<endl;
		return 0;
	}
	if(argc==2){
		filePath = argv[1];
	}
	cout << "Begins..." <<argc<< endl; // begins

	// main function start
    int totalTraces = 0;
    int numberOfRead =0;
    int numberOfWrite =0;
    int numberOfhit =0;
    int numberOfMiss =0;
	// create a cache
	Cache *cache = new Cache();
	//read from txt line by line eg:1f16 ff60 W
	ifstream iFile;

	iFile.open(filePath, ios::in);
//	iFile.open("", ios::in);
	if (!iFile.is_open()) {
		cout << "open fail!";
	} else {
        string line;
		char *buffer = new char[8];
		char *buffer32 = new char[32];
		char model;
		Tools tools;
//        int j = 10;
		while (getline(iFile, line)) {
            if(line.empty()){
                continue;
            }
            int result=1;
            totalTraces++;

            strcpy(buffer, line.substr(0,8).c_str());
            model = line.substr(9,1).c_str()[0];
			tools.hex2bin(buffer, buffer32, 8);
//			bitset<32> addressBit(buffer32);
			// call cache's function depends on the input
			// for W operation
			if (model == 'W') {
                numberOfWrite++;
//                cout << "W" << endl << buffer << endl;
				result = cache->wirteCache(buffer32);
                
			}
			// for R operation
			else if (model == 'R') {
                numberOfRead++;
//                cout << "R" << endl << buffer << endl;
                result = cache->readCache(buffer32);
			} else {
				cout << "wrong!" << endl;
			}
            result==SUCCESS?numberOfhit++:numberOfMiss++;
//            j--;
//            string a=result==SUCCESS?"hit":"miss";
//            cout<<a<<endl;
		}
		delete[] buffer32;
		delete[] buffer;

		// delete cache
		iFile.close();
	}

	delete cache;
    cout<<"Total traces:"<<totalTraces<<endl;
    cout<<"Reads:"<<numberOfRead<<endl;
    cout<<"Writes:"<<numberOfWrite<<endl;
    cout<<"Cache hits:"<<numberOfhit<<endl;
    cout<<"Cache misses:"<<numberOfMiss<<endl;
    
	return 0;
}

