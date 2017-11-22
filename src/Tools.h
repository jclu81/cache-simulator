/*
 * Tools.h
 *
 *  Created on: Nov 19, 2017
 *      Author: jclu
 */

#ifndef TOOLS_H_
#define TOOLS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
class Tools {
public:
	Tools();
	virtual ~Tools();
	int inline hex_to_bin(char hex, char * buf, int bit);
	int hex2bin(char *hex, char * buf, int len);
	int inline  bin_to_hex(const char * hex, char * buf, int bit);
	int bin2hex(const char * hex, char * buf);
	int hex_2_bin(char hex, char * buf);
};

#endif /* TOOLS_H_ */
