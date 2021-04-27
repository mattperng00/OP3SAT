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
	
	for (;;) {
		xQueueReceive(MRQ, &recieved_event, portMAX_DELAY);
		
		
	}
}
