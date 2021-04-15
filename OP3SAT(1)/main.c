
#include <stdio.h>
#include <atmel_start.h>

#include "buffer_pool.h"
#include "send_transmit.h"
#include "sppe.h"
#include "buffer_pool.h"

int main(void)
{
	NVIC_SetPriority(10,1);
	/* Initializes MCU, drivers and middle ware */
	atmel_start_init();
	
	// init asynchronous driver
	async_setup();
	
	cdhs_init();

	vTaskStartScheduler();
	
	while(1)
	{
		//io_write(&SERIAL.io, help, 4);
		//serial_rx_cb(&SERIAL.io);
	};
}

void cdhs_init() {
	
	/* Minimal Queues */
	SPQ = xQueueCreate(20, (UBaseType_t) sizeof(SPPEvent));
	//MRQ = xQueueCreate((UBaseType_t) 20, (UBaseType_t) sizeof(SPPEvent));
	//FBQ = xQueueCreate(20, (UBaseType_t) sizeof(void*));
	
	/* Tasks */
	xTaskCreate(sppe_task, "sppe", configMINIMAL_STACK_SIZE, SPQ, 1, NULL);
	
	
	/* */
	crc_table_init();
	//free_buffer_init(20, 128);
}