/*
 * receiver_tasks.c
 *
 * Created: 3/4/2021 5:05:49 PM
 *  Author: mattp
 */ 
#include "send_transmit.h"
#include <FreeRTOS.h>

void process_command_task(void *command)
{
	while(1)
	{
		transmit();	
		//vTaskDelay(1000);
	}
	//vTaskDelete(NULL);
}