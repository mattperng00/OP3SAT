/*
 * sppe.c
 *
 * Created: 3/25/2021 5:26:23 PM
 *  Author: John
 */ 

#include <stdio.h>
#include <atmel_start.h>

#include "sppe.h"
#include "send_transmit.h"


void sppe_task(void *pvParameters){	//volatile uint8_t received[220] = {0x00};	SPPEvent receivedEvent;	for (;;)	{		/* Wait until there is something to do. */		xQueueReceive(SPQ, &receivedEvent, portMAX_DELAY);		io_write(&SERIAL.io, receivedEvent.pvData, 30);		/* Perform a different action for each event type. */		switch (receivedEvent.eventType)		{			case eUSARTRxEvent:				recieveSPPPacket(receivedEvent.pvData);				break;			//case eUSARTTxEvent:				//processUSARTTransmit(receivedEvent.pvData);				//break;			//case eSPPTxEvent:				//sendSPPPacket(receivedEvent.pvData);				//break;			//default:			/* Should not get here. TODO: Possible error handling */		}	}		vTaskDelete(NULL);}void recieveSPPPacket() {		// Check CRC, if good, pass on to MRQ, else delete it (TODO: Error
	//io_write(&SERIAL.io, help, 5);
}
void processGeneratedPacket(){
		//io_write(&SERIAL.io, help, 6);
}