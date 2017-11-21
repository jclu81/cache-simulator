/*
 * Block.h
 *
 *  Created on: Nov 20, 2017
 *      Author: jclu
 */

#ifndef BLOCK_H_
#define BLOCK_H_
#include<bitset>
#define sizeOfTag 11
class Block {
private:
	unsigned short blockSize; // 块大小 16b
	bitset<1> validBit; //valid bit
	char* data;
	bitset<sizeOfTag> tag;
	bool isLru;
//	bool isMru;
public:
	Block() {
		this->blockSize = 16;
		this->validBit.reset();
		data = (char*) malloc(sizeof(char) * this->blockSize);
		tag.reset();
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
	void setTag(bitset<sizeOfTag> tag) {
		for (int tagi = 0; tagi < sizeOfTag; tagi++) {
			this->tag[tagi] = tag[tagi];
		}
	}
	void setValidBit(bitset<1> validBit) {
		this->validBit[0] = validBit[0];
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
	bitset<11> getTag() {
		return this->tag;
	}
	unsigned short getBlockSize() {
		return this->blockSize;
	}
	bitset<1> getValidBit() {
		return this->validBit;
	}

	virtual ~Block() {
		if (data != NULL) {
			free(data);
		}
	}
};

#endif /* BLOCK_H_ */
