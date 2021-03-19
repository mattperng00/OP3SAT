#include <atmel_start.h>
#include "send_transmit.h"
#include <stdio.h>

void sender1(void *pvParameters);
void sender2(void *pvParameters);
void receiver(void *pvParameters);

QueueHandle_t q1;

int main(void)
{
	
	/* Initializes MCU, drivers and middle ware */
	atmel_start_init();
	
	// init asynchronous driver
	async_setup();
	
	Q1 = xQueueCreate((UBaseType_t) 2, (UBaseType_t) sizeof(QueueBuffer));
	
	//xTaskCreate(sender1, "snd1", configMINIMAL_STACK_SIZE, (void *) q1, 1, NULL);
	
	//xTaskCreate(sender2, "snd2", configMINIMAL_STACK_SIZE, (void *) q1, 1, NULL);
	
	xTaskCreate(receiver, "rcv", configMINIMAL_STACK_SIZE, (void *) Q1, 2, NULL);

	
	vTaskStartScheduler();
	
	
}

void sender1(void *pvParameters)
{
	volatile uint8_t sendBuff1[7] = "Sender1";
	int flag = 1;
	QueueHandle_t output = (QueueHandle_t)pvParameters;
	
	for (;;)
	{
		io_write(&SERIAL.io, sendBuff1, 7);
		xQueueSend(output, &flag, portMAX_DELAY);
	}
}

void sender2(void *pvParameters)
{
	volatile uint8_t sendBuff2[7] = "Sender2";
	int flag = 2;
	QueueHandle_t output = (QueueHandle_t)pvParameters;
	
	for (;;)
	{
		io_write(&SERIAL.io, sendBuff2, 7);
		xQueueSend(output, &flag, portMAX_DELAY);
	}
}

void receiver(void *pvParameters)
{
	volatile uint8_t help[4] = "help";
	QueueBuffer anything;
	QueueHandle_t input = (QueueHandle_t)pvParameters;
	BaseType_t n;
	io_write(&SERIAL.io, help, 4);
	for (;;)
	{
		
		if((n = xQueueReceive(input, &anything, 10)) == pdPASS) {
			io_write(&SERIAL.io, help, 4);
			//io_write(&SERIAL.io, anything.buffer, 4);

		}
		//gpio_set_pin_level()
		
		if (1) {
			gpio_toggle_pin_level(BLINK);
			delay_ms(750);
			gpio_toggle_pin_level(BLINK);
			delay_ms(750);
			} else {
			gpio_toggle_pin_level(BLINK);
			delay_ms(250);
			gpio_toggle_pin_level(BLINK);
			delay_ms(250);
			gpio_toggle_pin_level(BLINK);
			delay_ms(750);
		}
		
	}
}
