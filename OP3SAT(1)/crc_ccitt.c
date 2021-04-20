/*
 * crc_ccitt.c
 *
 * Created: 4/4/2021 1:45:37 PM
 *  Author: anyis
 */ 
#include "crc_ccitt.h"

#define POLY_CCITT 0x1021
#define INIT_CCITT 0xFFFF

// Algorithm used: CRC-16/CCITT-FALSE

uint16_t crc_table[256];

uint16_t _compute_crc(uint16_t, uint8_t*, int);


uint16_t compute_crc(uint8_t* buffer, int len) {	
	return _compute_crc(INIT_CCITT, buffer, len);
}

uint16_t _compute_crc(uint16_t crc, uint8_t* buffer, int len) {

	while (len--) {
		crc = (crc << 8) ^ crc_table[(crc >> 8) ^ *buffer++];
	}
	return crc;
}

void crc_table_init() {
	uint16_t crc, c;

	for (uint16_t i = 0; i < 256; i++) {
		crc = 0;
		c = i << 8;

		for (int j = 0; j < 8; j++) {
			
			if ((crc ^ c) & 0x8000)
				crc = (crc << 1) ^ POLY_CCITT;
			else
				crc = crc << 1;
			c = c << 1;
		}
		crc_table[i] = crc;
	}
}
