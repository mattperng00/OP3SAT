#include <atmel_start.h>
#include "send_transmit.h"
#include <stdio.h>

void sender1(void *pvParameters);
void sender2(void *pvParameters);
void receiver(void *pvParameters);
volatile uint8_t help[4] = "help";
volatile uint8_t test[4] = "test";

QueueHandle_t q1;
QueueHandle_t Q2;

int main(void)
{
	NVIC_SetPriority(10,4);
	/* Initializes MCU, drivers and middle ware */
	atmel_start_init();
	
	// init asynchronous driver
	async_setup();
	//Q2 = xQueueCreate((UBaseType_t) 2, (UBaseType_t) sizeof(QueueBuffer));
	Q1 = xQueueCreate((UBaseType_t) 20, (UBaseType_t) sizeof(QueueBuffer));
	
	//xTaskCreate(sender1, "snd1", configMINIMAL_STACK_SIZE, (void *) q1, 1, NULL);
	
	//xTaskCreate(sender2, "snd2", configMINIMAL_STACK_SIZE, (void *) q1, 1, NULL);
	
	xTaskCreate(receiver, "rcv", configMINIMAL_STACK_SIZE, Q1, 2, NULL);

	
	vTaskStartScheduler();
	while(1)
	{
		//io_write(&SERIAL.io, help, 4);
		//serial_rx_cb(&SERIAL.io);
	};
	
}

void sender1(void *pvParameters)
{
	volatile uint8_t sendBuff1[4] = "test";
	int flag = 1;
	
	for (;;)
	{
		//io_write(&SERIAL.io, sendBuff1, 7);
		xQueueSend(Q2, &sendBuff1, portMAX_DELAY);
	}
}

void sender2(void *pvParameters)
{
	volatile uint8_t sendBuff2[7] = "Sender2";
	volatile uint8_t recieve[4] = "";
	int flag = 2;
	
	for (;;)
	{
		xQueueReceive(Q2,&recieve,portMAX_DELAY);
		io_write(&SERIAL.io, recieve, 7);
	}
}

void receiver(void *pvParameters)
{
	//QueueBuffer anything;
	volatile uint8_t recieve[220] = "";
	QueueHandle_t input = (QueueHandle_t)pvParameters;
	BaseType_t n;
	io_write(&SERIAL.io, help, 4);
	for (;;)
	{
		io_write(&SERIAL.io, test, 4);
		if((n = xQueueReceive(Q1, &recieve, 10)) == pdPASS) {
			
			//io_write(&SERIAL.io, anything.buffer, 10);
			io_write(&SERIAL.io,recieve,10);
			
		}
		//gpio_set_pin_level()
		
		if (1) {
			gpio_toggle_pin_level(BLINK);
			delay_ms(100);
			gpio_toggle_pin_level(BLINK);
			delay_ms(100);
			} else {
			gpio_toggle_pin_level(BLINK);
			delay_ms(100);
			gpio_toggle_pin_level(BLINK);
			delay_ms(100);
			gpio_toggle_pin_level(BLINK);
			delay_ms(100);
		}
		
	}
}
