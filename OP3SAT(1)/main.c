
#include <stdio.h>
#include <atmel_start.h>

#include "send_transmit.h"
#include "sppe.h"
#include "free_buffers.h"

void cdhs_init();


int main(void)
{
	NVIC_SetPriority(10, 1);
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
	}
}

void cdhs_init() {
	
	/* Queues */
	SPQ = xQueueCreate(20, (UBaseType_t) sizeof(SPPEvent));
	//MRQ = xQueueCreate(20, (UBaseType_t) sizeof(SPPEvent));
	//FBQ = xQueueCreate(20, (UBaseType_t) sizeof(void*));
	//TDQ = xQueueCreate(2, (UBaseType_t) sizeof(void*));
	
	/* Tasks */
	xTaskCreate(sppe_task, "sppe", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	//xTaskCreate(msg_router_task, "msgr", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	//xTaskCreate(tod_processor_task, "todp", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	//xTaskCreate(, "cmdu", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	//xTaskCreate(, "cmd1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	
	/* Other */
	crc_table_init();
	
	//free_buffer_init(20, 64);
}