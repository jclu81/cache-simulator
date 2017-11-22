/*
 * Tools.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: jclu
 */

#include "Tools.h"

Tools::Tools() {
	// TODO Auto-generated constructor stub

}

Tools::~Tools() {
	// TODO Auto-generated destructor stub
}

int inline Tools::hex_to_bin(char hex, char * buf, int bit) {
	if (!buf || ((0 > bit) && (3 < bit))) {
		return -1;
	}

	if (hex & (0x1 << bit)) {
		buf[3 - bit] = '1';
	}
	else{
		buf[3 - bit]='0';
	}

	return 0;
}


int Tools::hex_2_bin(char hex, char * buf) {
	char c = 0;
	int i = 0;

	if (!buf) {
		return -1;
	}

	if (('0' <= hex) && ('9' >= hex)) {
		c = hex - 0x30;
	} else if ((('A' <= hex) && ('F' >= hex))
			|| (('a' <= hex) && ('f' >= hex))) {
		c = hex - 0x37;
	} else {
		return -1;
	}

	for (i = 0; i < 4; i++) {
		if (-1 == hex_to_bin(c, buf, i)) {
			return -1;
		}
	}

	return 0;
}

int Tools::hex2bin(char *hex, char * buf, int len) {
	int i = 0;
	/* hex to bin */
	for (i = 0; i < len; i++) {
		if (-1 == hex_2_bin(hex[i], &buf[i * 4])) {
			return -1;
		}
	}
	return 0;
}

int inline Tools::bin_to_hex(const char * hex, char * buf, int bit) {
	if (!hex || !buf || ((0 > bit) || (3 < bit))) {
		return -1;
	}

	if ('1' == hex[3 - bit]) {
		buf[0] |= (0x1 << bit);
	}

	return 0;
}

int Tools::bin2hex(const char * hex, char * buf) {
	int i = 0;

	if (!hex || !buf) {
		return -1;
	}

	for (i = 0; i < 4; i++) {
		if (-1 == bin_to_hex(hex, buf, i)) {
			return -1;
		}
	}
	if ((0 <= buf[0]) && (9 >= buf[0])) {
		buf[0] += 0x30;
	} else if ((0xA <= buf[0]) && (0xF >= buf[0])) {
		buf[0] += 0x37;
	} else {
		return -1;
	}

	return 0;
}
