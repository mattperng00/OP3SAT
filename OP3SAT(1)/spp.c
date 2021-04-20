/*
 * spp.c
 *
 * Created: 4/13/2021 6:00:31 PM
 *  Author: anyis
 */ 

#include "spp.h"

#define CMD_SYNC_PATTERN 0x40286BFE
#define TOD_SYNC_PATTERN CMD_SYNC_PATTERN
#define TEL_SYNC_PATTERN 0x53F82E35

#define HEADER_LEN 10
#define SYNC_LEN 4
#define CRC_LEN 2

/* Field extract */
inline uint32_t spp_packet_sync_pattern(uint8_t* ptr) {
	return *(uint32_t*)ptr;
}

inline uint16_t spp_packet_data_length(uint8_t* ptr) {
	return *(uint16_t*)(ptr + HEADER_LEN - 2);
}

inline uint16_t spp_packet_length(uint8_t* ptr) {
	return spp_packet_data_length(ptr) + HEADER_LEN + CRC_LEN; // Include header and CRC bytes
}

inline uint8_t spp_packet_type(uint8_t* ptr)
{
	return *(ptr+4) & 0b00010000; 
}

inline uint8_t* spp_packet_crc_start(uint8_t* ptr) {
	return ptr + SYNC_LEN; // Start at byte past sync frame
}

inline uint16_t spp_packet_crc_check_range(uint8_t* ptr) {
	return spp_packet_length(ptr) - SYNC_LEN; // Exclude sync bytes
}

inline uint16_t spp_packet_crc_compute_range(uint8_t* ptr) {
	return spp_packet_length(ptr) - SYNC_LEN - CRC_LEN; // Exclude sync and (currently empty) crc bytes
}

uint8_t* find_message(uint8_t* ptr, int len) {

	while (len--) {
		if (*(uint32_t*)ptr == CMD_SYNC_PATTERN)
		return ptr;
		ptr++;
	}

	return NULL;
}

/* ACK */
inline uint16_t generate_ack(uint8_t* ptr) {
	
}