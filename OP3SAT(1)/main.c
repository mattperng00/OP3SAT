#include <atmel_start.h>
#include "send_transmit.h"
#include "sppe.h"
#include <stdio.h>
void sender1(void *pvParameters);
void sender2(void *pvParameters);
void receiver(void *pvParameters);
volatile uint8_t help[4] = "help";
volatile uint8_t test[4] = "test";


int main(void)
{
	NVIC_SetPriority(10,1);
	/* Initializes MCU, drivers and middle ware */
	atmel_start_init();
	
	// init asynchronous driver
	async_setup();
	
	SPQ = xQueueCreate((UBaseType_t) 20, (UBaseType_t) sizeof(SPPEvent));
	//MRQ = xQueueCreate((UBaseType_t) 20, (UBaseType_t) sizeof(SPPEvent));
		
	xTaskCreate(sppe_task, "sppe", configMINIMAL_STACK_SIZE, SPQ, 1, NULL);

	vTaskStartScheduler();
	while(1)
	{
		//io_write(&SERIAL.io, help, 4);
		//serial_rx_cb(&SERIAL.io);
	};
}
