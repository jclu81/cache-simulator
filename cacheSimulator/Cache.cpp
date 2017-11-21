/*
 * Cache.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: jclu
 */

#include "Cache.h"

Cache::Cache() {
	// TODO Auto-generated constructor stub
	this->cacheSize = 4096 * 1024; //4096KB
	this->blockSize = 16; //16B
	this->associativity = 2; //
	this->indexSize = 17; // log(cacheSize/(blockSize*ass))
	this->offsetSize = 4; // log(blockSize)
	this->tagSize = 11; // 32 - indexSize-offsetSize
	cout << "Cache's construction function: create all blocks" << endl;
	this->block = new Block[pow(2,indexSize) * associativity];
	this->mRU = new char[32];
	this->lRU = new char[32];
//	this->addressSize = 32; //32 bits
}

//Cache::Cache(unsigned int cacheSize, unsigned int blockSize,
//		unsigned short associativity, unsigned short addressSize) {
//	this->cacheSize = cacheSize; //4096KB
//	this->blockSize = blockSize; //16B
//	this->associativity = associativity; //
//
//	this->addressSize = addressSize; //32 bits
//}
int Cache::readCache(bitset<32> addressBit) {

	string adds = addressBit.to_string();
	char *tag = new char[tagSize];
	char *index = new char[indexSize];
	char *offset = new char[offsetSize];

//	cout << adds << endl;
	strcpy(tag, adds.substr(0, 11).c_str());
	strcpy(index, adds.substr(11, 17).c_str());
	strcpy(offset, adds.substr(11 + 17, 4).c_str());

//	cout << tag << endl << index1 << endl << offset1 << endl;

	//find line by index
	bitset<17> indexBit(index);
	int indexInt = (int) indexBit.to_ulong() * 2;
	Block destBlock;
	int hitInt = 0;
	int mruInt = 0;
	int lruInt = 0;

	int assi;
	for (assi = 0; assi < this->associativity; assi++) {
		destBlock = this->block[indexInt + assi];
		//compare valid bit

		//occupied
		if (strcmp(destBlock.getValidBit().to_string().c_str(), "1")) {
			//compare tag
			if (strcmp(destBlock.getTag().to_string().c_str(), tag)) {
				//hit
				hitInt = indexInt + assi;
			}
		}
		// find MRU and LRU
		if (destBlock.getIsLru()) {
			lruInt = indexInt + assi;
		} else {
			mruInt = indexInt + assi;
		}
//		if (destBlock.getIsMru()) {
//			mruInt = indexInt + assi;
//		}
	}

	if (assi < this->associativity) {
		//hit
		//read block set MRU then set MRU to LRU
		if (hitInt != mruInt) {
			destBlock = this->block[hitInt];
			destBlock.setIsLru(false);
			destBlock = this->block[mruInt];
			destBlock.setIsLru(true);
		}
	} else {
		//miss
		//read block from memory and replace the LRU block, move MRU to LRU
		bitset<11> tagBit(tag);
		bitset<1> validBit("1");
		this->block[lruInt].setTag(tagBit);
		this->block[lruInt].setValidBit(validBit);
		//set data
		this->block[lruInt].setIsLru(false);

		destBlock = this->block[mruInt];
		destBlock.setIsLru(true);
	}
	delete[] tag;
	delete[] index;
	delete[] offset;
	return FAIL;
}
int Cache::wirteCache(bitset<32> addressBit) {

	return FAIL;
}
Cache::~Cache() {
	// TODO Auto-generated destructor stub
	delete[] this->mRU;
	delete[] this->lRU;
	delete[] this->block;
}

