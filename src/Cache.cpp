/*
 * Cache.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: jclu
 */
#include "Cache.h"
#include "string.h"
using std::bitset;
Cache::Cache() {
	// TODO Auto-generated constructor stub
	this->cacheSize = 4096 * 1024; //4096KB
	this->blockSize = 16; //16B
	this->associativity = 2; //
	this->indexSize = 17; // log(cacheSize/(blockSize*ass))
	this->offsetSize = 4; // log(blockSize)
	this->tagSize = 11; // 32 - indexSize-offsetSize
	cout << "Cache's construction function: create all blocks" << endl;
	this->block = new Block[int(pow(2, indexSize) * associativity)];
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
int Cache::readCache(char* addressChar) {
	string addressString(addressChar);
	bitset<32> addressBit(addressString);

	bitset<32> add;

	string adds = addressBit.to_string('0', '1');
	char *tag = new char[tagSize];
	char *index = new char[indexSize];
	char *offset = new char[offsetSize];

//	cout << adds << endl;
	strcpy(tag, adds.substr(0, 11).c_str());
	strcpy(index, adds.substr(11, 17).c_str());
	strcpy(offset, adds.substr(11 + 17, 4).c_str());

//	cout << tag << endl << index1 << endl << offset1 << endl;

	//find line by index
	string indexString(index);
	bitset<17> indexBit(indexString);
	int indexInt = (int) indexBit.to_ulong() * 2;
	Block *destBlock;
	int hitInt = 0;
	int mruInt = indexInt;
	int lruInt = 0;

	int assi;
	bool isHit = false;
	for (assi = 0; assi < this->associativity; assi++) {
		destBlock = &this->block[indexInt + assi];
		//compare valid bit

		//occupied
		if (destBlock->getValidBit()) {
			//compare tag
			if (!strcmp(destBlock->getTag(), tag)) {
				isHit = true;
				hitInt = indexInt + assi;
			}
		}
		// find MRU and LRU
		if (destBlock->getIsLru()) {
			lruInt = indexInt + assi;
		} else {
			mruInt = indexInt + assi;
		}
//		if (destBlock.getIsMru()) {
//			mruInt = indexInt + assi;
//		}
	}

	if (isHit) {
		//hit
		//read block set MRU then set MRU to LRU
		if (hitInt != mruInt) {
			destBlock = &this->block[hitInt];
			destBlock->setIsLru(false);
			destBlock = &this->block[mruInt];
			destBlock->setIsLru(true);
		}
	} else {
		//miss
		//read block from memory and replace the LRU block, move MRU to LRU

		this->block[lruInt].setTag(tag);
		this->block[lruInt].setValidBit(true);
		//set data
		this->block[lruInt].setIsLru(false);

		destBlock = &this->block[mruInt];
		destBlock->setIsLru(true);
	}
	delete[] tag;
	delete[] index;
	delete[] offset;
	return isHit ? SUCCESS : FAIL;
}

int Cache::wirteCache(char* addressChar) {
	string addressString(addressChar);
	bitset<32> addressBit(addressString);
	string adds = addressBit.to_string('0', '1');

	//find line by index
	bitset<11> tagBit(adds, 0, 11);
	bitset<17> indexBit(adds, 11, 17);
	bitset<4> offsetBit(adds, 28, 4);
	char *tag = new char[11];
	strcpy(tag, tagBit.to_string().c_str());
	int indexInt = (int) indexBit.to_ulong() * 2;
	Block *destBlock;
	int hitInt = 0;
	int mruInt = indexInt;
	int lruInt = 0;

	int assi;
	bool isHit = false;
	for (assi = 0; assi < this->associativity; assi++) {
		destBlock = &this->block[indexInt + assi];
		//compare valid bit

		//occupied
		if (destBlock->getValidBit()) {
			//compare tag
			if (!strcmp(destBlock->getTag(), tag)) {
				isHit = true;
				hitInt = indexInt + assi;
			}
		}
		// find MRU and LRU
		if (destBlock->getIsLru()) {
			lruInt = indexInt + assi;
		} else {
			mruInt = indexInt + assi;
		}
	}

	if (isHit) {
		//hit
		//write block set MRU then set MRU to LRU
		if (hitInt != mruInt) {
			destBlock = &this->block[hitInt];
			destBlock->setIsLru(false);
			destBlock = &this->block[mruInt];
			destBlock->setIsLru(true);
		}
		//write cache and memary
	} else {
		//miss
		//write memary then take block from memory and replace the LRU block, move MRU to LRU

		this->block[lruInt].setTag(tag);
		this->block[lruInt].setValidBit(true);
		//set data
		this->block[lruInt].setIsLru(false);

		destBlock = &this->block[mruInt];
		destBlock->setIsLru(true);
	}
	delete[] tag;
	return isHit ? SUCCESS : FAIL;
}
Cache::~Cache() {
	// TODO Auto-generated destructor stub
	delete[] this->mRU;
	delete[] this->lRU;
	delete[] this->block;
}

