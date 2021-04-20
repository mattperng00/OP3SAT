/*
 * sppe.c
 *
 * Created: 3/25/2021 5:26:23 PM
 *  Author: John
 */ 

#include "sppe.h"

void sppe_task_init();
void sppe_task(void *pvParameters);

void recieveSPPPacket(void *data);
void sendSPPPacket(void *data);


void sppe_task_init() {
	
}

void sppe_task(void *pvParameters){	SPPEvent receivedEvent;		for (;;) {		/* Wait until there is something to do. */		xQueueReceive(SPQ, &receivedEvent, portMAX_DELAY);				//io_write(&SERIAL.io, receivedEvent.pvData, 30);				switch (receivedEvent.eventType) {			case eUSARTRxEvent:				recieveSPPPacket(receivedEvent.pvData);				break;			/*case eUSARTTxEvent:				processUSARTTransmit(receivedEvent.pvData);				break;			case eSPPTxEvent:				sendSPPPacket(receivedEvent.pvData);				break;*/			default:			/* Should not get here. TODO: Possible error handling */				break;		}	}		vTaskDelete(NULL);}void recieveSPPPacket(void *data) {		uint8_t suc[9] = "success!";		// Check CRC, if good, pass on to MRQ, else delete it (TODO: Error)
	
	io_write(&SERIAL.io, suc, 9);
	/*uint8_t* msg = find_message((uint8_t*) data, 20); // What is the length???
	
	uint16_t crc_len = spp_packet_crc_check_range(msg);
	uint8_t* crc_start = spp_packet_crc_start(msg);
	
	if (!compute_crc(crc_start, crc_len)) {
		// Error, free buffer and return
		io_write(&SERIAL.io, fail, 6);
		return;
	}*/
	
	//io_write(&SERIAL.io, suc, 8);
}

void sendSPPPacket(void* data) {
	
	uint16_t pkt_len = spp_packet_length(data);
	
	//io_write(&SERIAL.io, data, pkt_len);
	
	// Free buffer
}