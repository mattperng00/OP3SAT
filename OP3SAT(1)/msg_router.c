/*
 * msg_router.c
 *
 * Created: 4/1/2021 7:00:34 PM
 *  Author: mattp
 */ 

#include "msg_router.h"

void msg_router_init() {
	
}

void msg_router_task(void *pvParameters) {	// declare struct	SPPEvent receivedEvent;	for (;;)	{		xQueueReceive(SPQ,&receivedEvent,portMAX_DELAY);		if(receivedEvent.pvData == 16)
		{
			//time of day process
		}
		else
		{
			//parse command
		}
				}		vTaskDelete(NULL);}