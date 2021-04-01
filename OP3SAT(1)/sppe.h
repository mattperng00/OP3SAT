/*
 * sppe.h
 *
 * Created: 3/25/2021 5:26:36 PM
 *  Author: John
 */ 



#ifndef SPPE_H_
#define SPPE_H_
/* To header */#include "rtos_start.h"

typedef enum{	eUSARTRxEvent, /* Indicates that this data came from a USART Rx interrupt */	eUSARTTxEvent, /* Indicates that a USART Tx was successful/failed */	eSPPTxEvent		/* Indicates that this data is a packet that should be transmitted */}enumSPPEvent;typedef struct SPP_TASK_COMMANDS{	enumSPPEvent eventType; /* Tells the receiving task what the event is. */	void *pvData;			/* Holds or points to any data associated with the event. */} SPPEvent;void sppe_task(void *pvParameters);//QueueHandle_t SPQ;	
#endif /* SPPE_H_ */