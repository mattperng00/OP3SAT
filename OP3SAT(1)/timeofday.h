/*
 * timeofday.h
 *
 * Created: 4/26/2021 7:01:13 PM
 *  Author: anyis
 */ 


#ifndef TIMEOFDAY_H_
#define TIMEOFDAY_H_

#include <stdint.h>

uint32_t get_tai_seconds();

uint16_t get_tai_milliseconds();

uint32_t get_internal_clk();

void set_tai_time(uint32_t seconds, uint16_t milliseconds);

//void set_internal_clk();

#endif /* TIMEOFDAY_H_ */