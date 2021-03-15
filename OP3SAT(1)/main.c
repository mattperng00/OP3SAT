#include <atmel_start.h>
#include "send_transmit.h"
#include <stdio.h>

void sender1(void *pvParameters);
void sender2(void *pvParameters);
void receiver(void *pvParameters);

QueueHandle_t q1;

int main(void)
{
	
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	// init async driver
	async_setup();
	
    q1 = xQueueCreate((UBaseType_t) 2, (UBaseType_t) sizeof(uint32_t));
	
	BaseType_t rc;
	rc = xTaskCreate(sender1, "snd1", configMINIMAL_STACK_SIZE, (void *) q1, 1, NULL);
	ASSERT(rc != pdFALSE);
	rc = xTaskCreate(sender2, "snd2", configMINIMAL_STACK_SIZE, (void *) q1, 1, NULL);
	ASSERT(rc != pdFALSE);
	rc = xTaskCreate(receiver, "rcv", configMINIMAL_STACK_SIZE, (void *) q1, 2, NULL);
	ASSERT(rc != pdFALSE);
	
	vTaskStartScheduler(); 
	
	while (1) {
		gpio_toggle_pin_level(BLINK);
		//delay_ms(1000);
		//transmit();
		//receive_callback();
	}
}

void sender1(void *pvParameters)
{
	int flag = 1;
	QueueHandle_t output = (QueueHandle_t)pvParameters;
	
	for (;;)
	{
		xQueueSend(output, &flag, portMAX_DELAY);
	}
}

void sender2(void *pvParameters)
{
	int flag = 2;
	QueueHandle_t output = (QueueHandle_t)pvParameters;
	
	for (;;)
	{
		xQueueSend(output, &flag, portMAX_DELAY);
	}
}

void receiver(void *pvParameters)
{
	QueueHandle_t input = (QueueHandle_t)pvParameters;
	int n;
	
	for (;;)
	{
		xQueueReceive(input, &n, portMAX_DELAY);
		//gpio_set_pin_level()
		
		if (n % 2) {
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