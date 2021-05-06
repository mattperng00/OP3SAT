/*
 * tod_processor.c
 *
 * Created: 4/26/2021 6:51:01 PM
 *  Author: anyis
 */ 


#include "tod_processor.h"

void tod_processor_init();

void tod_processor_init() {
	
}

void tod_processor_task(void *pvParameters) {
	
	SPPEvent recieved_event;
	uint8_t* data;
	uint32_t seconds;
	uint16_t m_seconds;
	
	//tod_processor_init();
	
	for (;;) {
		xQueueReceive(MRQ, &recieved_event, portMAX_DELAY);
		
		data = (uint8_t*)recieved_event.pvData;
		seconds = tai_seconds(data);
		m_seconds = tai_milliseconds(data);
		
		// update
		set_tai_time(seconds, m_seconds);
		
		// Free pvData
	}
}
