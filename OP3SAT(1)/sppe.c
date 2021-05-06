/*
 * sppe.c
 *
 * Created: 3/25/2021 5:26:23 PM
 *  Author: John
 */ 

#include "sppe.h"

void sppe_task_init();
void sppe_task(void *pvParameters);

void recieve_packet(void *data);
void send_packet(void *data);

uint8_t ack_pkt[];

char fail[] = "sppe fail";
char suc[] = "sppe success";

void sppe_task_init() {
	
}

void sppe_task(void *pvParameters){	SPPEvent received_event;		for (;;) {		/* Wait until there is something to do. */		xQueueReceive(SPQ, &received_event, portMAX_DELAY);				//io_write(&SERIAL.io, receivedEvent.pvData, 30);				switch (received_event.eventType) {			case eUSARTRxEvent:				recieve_packet(received_event.pvData);				break;			/*case eUSARTTxEvent:				processUSARTTransmit(receivedEvent.pvData);				break;			case eSPPTxEvent:				send_packet(receivedEvent.pvData);				break;*/			default:			/* Should not get here. TODO: Possible error handling */				break;		}	}		vTaskDelete(NULL);}void recieve_packet(void *data) {		// Check CRC, if good, pass on to MRQ, else delete it (TODO: Error)
	
	io_write(&SERIAL.io, suc, 4);
	
	//uint8_t* msg = find_message((uint8_t*)data, 20); // TODO: What is the length we should search for?
	
	uint16_t crc_len = spp_packet_crc_check_range((uint8_t*)data);
	uint8_t* crc_start = spp_packet_crc_start((uint8_t*)data);
	
	if (!compute_crc(crc_start, crc_len)) {
		
		io_write(&SERIAL.io, fail, 6);
		
		// TODO: report error
		
		// release buffer
		return_buffer(data);
		
		return;
	}
	
	xQueueSend(MRQ, data, portMAX_DELAY);
}

void send_packet(void* data) {
	
	uint16_t pkt_len = spp_packet_length(data);
	
	//io_write(&SERIAL.io, data, pkt_len);
	
	// Free buffer
	return_buffer(data);
}