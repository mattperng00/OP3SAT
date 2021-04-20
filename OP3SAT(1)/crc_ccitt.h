/*
 * crc_ccitt.h
 *
 * Created: 4/4/2021 1:46:31 PM
 *  Author: anyis
 */ 


#ifndef CRC_CCITT_H_
#define CRC_CCITT_H_

#include <stdint.h>

extern uint16_t compute_crc(uint8_t*, int);

extern void crc_table_init();

#endif /* CRC_CCITT_H_ */