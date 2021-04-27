/*
 * msg_router.c
 *
 * Created: 4/1/2021 7:00:34 PM
 *  Author: mattp
 */ 

#include "msg_router.h"
#include "buffer_pool.h"

void msg_router_init();
void route_command(void *data);


void msg_router_init() {
	
}

void msg_router_task(void *pvParameters) {		SPPEvent received_event;	void *msg = NULL;		for (;;) {		xQueueReceive(MRQ, &received_event, portMAX_DELAY);		
		if (spp_packet_type((uint8_t*)received_event.pvData)) {
			//route_command(received_event.pvData);
		}
		else {
			//xQueueSend(TDQ, receivedEvent.pvData, portMAX_DELAY);
		}
			}		vTaskDelete(NULL);}void route_command(void *data) {		// Check APID		// Check CMD type		// route}