/*
 * Block.h
 *
 *  Created on: Nov 20, 2017
 *      Author: jclu
 */

#ifndef BLOCK_H_
#define BLOCK_H_
#include<bitset>
#include<stdio.h>
#include<malloc.h>
#define sizeOfTag 11
class Block {
private:
	unsigned short blockSize; // 块大小 16b
	bool validBit; //valid bit
	char* data;
	char* tag;
	bool isLru;
//	bool isMru;
public:
	Block() {
		this->blockSize = 16;
		this->validBit = false;
		data = (char*)malloc(sizeof(char));

		tag=(char*) malloc(sizeof(char) * 11);
		isLru = true;
//		isMru = true;
	}

//	Block(unsigned short blockSize, unsigned short tagSize) {
//		this->blockSize = blockSize;
//		this->validBit = '0';
//		data = (char*) malloc(sizeof(char) * blockSize);
//		tag = new char[tagSize];
//	}

//	void setIsMru(bool isLru) {
//		this->isLru = isLru;
//	}
	void setIsLru(bool isLru) {
		this->isLru = isLru;
	}
	void setTag(char* tag) {
		for (int tagi = 0; tagi < sizeOfTag; tagi++) {
			this->tag[tagi] = tag[tagi];
		}
	}
	void setValidBit(bool validBit) {
		this->validBit = validBit;
	}
	void setBlockSize(unsigned short blockSize) {
		this->blockSize = blockSize;
	}
//	bool getIsMru() {
////		return this->isLru;
////	}
	bool getIsLru() {
		return this->isLru;
	}
	char* getTag() {
		return this->tag;
	}
	unsigned short getBlockSize() {
		return this->blockSize;
	}
	bool getValidBit() {
		return this->validBit;
	}

	virtual ~Block() {
//        if (data != NULL) {
			free(data);
//        }
	}
};

#endif /* BLOCK_H_ */
