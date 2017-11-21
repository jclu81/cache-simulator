/*
 * Address.h
 *
 *  Created on: Nov 19, 2017
 *      Author: jclu
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <bitset>
using std::bitset;

#define addressSize 32
#define offset 4
#define index 17

class Address {
private:
	bitset<addressSize - offset - index> tagBit;
	bitset<index> indexBit;
	bitset<offset> offsetBit;

public:
	Address();
	virtual ~Address();
};

#endif /* ADDRESS_H_ */

