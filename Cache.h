/*
 * Cache.h
 *
 *  Created on: Nov 19, 2017
 *      Author: jclu
 */

#ifndef CACHE_H_
#define CACHE_H_
#include<math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define FAIL -1
#define SUCCESS 0

#include "Block.h"

class Cache {
private:
	unsigned int cacheSize;
	unsigned int blockSize;
	unsigned short associativity;
	unsigned short indexSize;
	unsigned short offsetSize;
	unsigned short tagSize;

	//MRU and LRU
	char * mRU;
	char * lRU;
	Block * block;

//	unsigned short addressSize;

public:
	Cache();
//	Cache(unsigned int cacheSize, unsigned int blockSize,
//			unsigned short associativity);
	int readCache(char* addressChar);
	int wirteCache(char* addressChar);
	virtual ~Cache();
};

#endif /* CACHE_H_ */
