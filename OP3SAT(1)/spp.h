/*
 * spp.h
 *
 * Created: 4/13/2021 6:02:19 PM
 *  Author: anyis
 */ 


#ifndef SPP_H_
#define SPP_H_

#include <stdint.h>
#include <atmel_start.h>


uint32_t spp_packet_sync_pattern(uint8_t* ptr);

uint16_t spp_packet_data_length(uint8_t* ptr);

uint16_t spp_packet_length(uint8_t* ptr);

uint8_t spp_packet_type(uint8_t* ptr);

uint8_t* spp_packet_crc_start(uint8_t* ptr);

uint16_t spp_packet_crc_check_range(uint8_t* ptr);

uint16_t spp_packet_crc_compute_range(uint8_t* ptr);

uint8_t* find_message(uint8_t* ptr, int len);

uint16_t generate_ack(uint8_t* ptr);


#endif /* SPP_H_ */