/*
 * timeofday.c
 *
 * Created: 4/26/2021 7:10:53 PM
 *  Author: anyis
 */ 

#include "timeofday.h"

static uint32_t tai_seconds;
static uint16_t tai_milliseconds;
//static uint32_t internal_clk;


uint32_t get_tai_seconds() {
	return tai_seconds;
}

uint16_t get_tai_milliseconds() {
	return tai_milliseconds;
}

/*uint32_t get_internal_clk() {
	return
}
*/

void set_tai_time(uint32_t seconds, uint16_t milliseconds) {
	
	vTaskSuspendAll();
	
	tai_seconds = seconds;
	tai_milliseconds = milliseconds;
	
	xTaskResumeAll();
}
