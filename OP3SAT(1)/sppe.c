/*
 * sppe.c
 *
 * Created: 3/25/2021 5:26:23 PM
 *  Author: John
 */ 
#include "sppe.h"
void SPPE_Task(void *pvParameters){	SPPEvent receivedEvent;	for (;;)	{		/* Wait until there is something to do. */		xQueueReceive(SPQ, &receivedEvent, portMAX_DELAY);		/* Perform a different action for each event type. */		switch (receivedEvent.eventType)		{			case eUSARTRxEvent:			prvProcessSPPPacket(receivedEvent.pvData);			//or prvProcessUSARTFrame(xReceivedEvent.pvData);			break;			case eUSARTTxEvent:			//prvProcessUSARTTransmit(xReceivedEvent.pvData);			break;			case eSPPTxEvent:			prvProcessGeneratedPacket(receivedEvent.pvData);			break;			default:			/* Should not get here. TODO: Possible error handling */		}	}		vTaskDelete(NULL);}void prvProcessSPPPacket() {		// Check CRC, if good, pass on to MRQ, else delete it (TODO: Error
}
void prvProcessGeneratedPacket(){
	
}