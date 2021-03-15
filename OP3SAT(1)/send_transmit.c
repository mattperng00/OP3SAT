/*
 * send_transmit.c
 *
 * Created: 3/4/2021 5:27:02 PM
 *  Author: mattp
 */ 

#include <atmel_start.h>
#include "receiver_tasks.h"

volatile uint8_t serial_receiving = 0;
volatile uint8_t serial_complete = 0;

// bytes received counters
volatile uint8_t byteCount = 0;
volatile uint8_t totalBytes = 0;

//receive buffer size
#define SERIAL_BUFFER_SIZE 200

//Receive and transmit buffers
volatile uint8_t rx_buffer[SERIAL_BUFFER_SIZE] = {0x00};
volatile uint8_t tx_buffer[SERIAL_BUFFER_SIZE + 20] = "Processing Command: ";
//Receive Callback function
static void serial_rx_cb(const struct usart_async_descriptor *const io_descr)
{
	//counters
	uint8_t ch, count;
	
	//read in char
	count = io_read(&SERIAL.io, &ch, 1);
	
	//check if receiving
	if (serial_receiving == 0)
	{
		//check for new line or return
		if(ch != '\r' && ch != '\n')
		{
			//set receive flag
			serial_receiving = 1;
			
			//reset byte counter
			byteCount = 0;
			
			//fill buffer
			rx_buffer[byteCount] = ch;
			
			//increment
			byteCount += count;
		}
	}
	else
	{
		//continue filling buffer
		rx_buffer[byteCount] = ch;
		
		//increment
		byteCount += count;
		//check for new line or return
		if (ch == '\r' || ch == '\n')
		{
			//set flag
			serial_complete =1;
			//total bytes
			totalBytes = byteCount - 2;
		}
		//overflow check
		if (byteCount >= SERIAL_BUFFER_SIZE)
		{
			//reset buffer counter
			byteCount = 0;
		}
	}
}

static uint8_t example_SERIAL[17] = "Command Processed";

static void serial_tx_cb(const struct usart_async_descriptor *const io_descr)
{
	
}


void transmit(void)
{
	struct io_descriptor *io;

	usart_async_register_callback(&SERIAL, USART_ASYNC_TXC_CB, serial_tx_cb);
	/*usart_async_register_callback(&SERIAL, USART_ASYNC_RXC_CB, rx_cb);
	usart_async_register_callback(&SERIAL, USART_ASYNC_ERROR_CB, err_cb);*/
	usart_async_get_io_descriptor(&SERIAL, &io);
	usart_async_enable(&SERIAL);

	io_write(&SERIAL.io, example_SERIAL,17);
}

void receive_callback()
{
	if (serial_receiving == 1)
	{
		//check complete
		if(serial_complete == 1)
		{
			//reset flags
			serial_receiving = 0;
			serial_complete = 0;
			
			//copy message
			memcpy(&tx_buffer[20], &rx_buffer[0], SERIAL_BUFFER_SIZE);
			//turn led message indicator on
			//print message
			io_write(&SERIAL.io, tx_buffer, totalBytes + 22);
			//clear mem
			memset(&rx_buffer, 0x00, SERIAL_BUFFER_SIZE);
			
			//xTaskCreate(process_command_task,(signed char*) "process_command_task",1024,NULL,1,NULL);
		}
	}
}
void async_setup(void)
{
	usart_async_register_callback(&SERIAL, USART_ASYNC_TXC_CB, serial_tx_cb);
	usart_async_register_callback(&SERIAL, USART_ASYNC_RXC_CB, serial_rx_cb);
	usart_async_enable(&SERIAL);
}