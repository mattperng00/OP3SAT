
#include <stdio.h>
#include <atmel_start.h>

#include "send_transmit.h"
#include "sppe.h"

int main(void)
{
	NVIC_SetPriority(10,1);
	/* Initializes MCU, drivers and middle ware */
	atmel_start_init();
	
	// init asynchronous driver
	async_setup();

	vTaskStartScheduler();
	
	while(1)
	{
		//io_write(&SERIAL.io, help, 4);
		//serial_rx_cb(&SERIAL.io);
	};
}

void cdhs_init() {
	/* Minimal Queues */
	SPQ = xQueueCreate((UBaseType_t) 20, (UBaseType_t) sizeof(SPPEvent));
	//MRQ = xQueueCreate((UBaseType_t) 20, (UBaseType_t) sizeof(SPPEvent));
	
	/* Tasks */
	xTaskCreate(sppe_task, "sppe", configMINIMAL_STACK_SIZE, SPQ, 1, NULL);
	
	
	/* */
}