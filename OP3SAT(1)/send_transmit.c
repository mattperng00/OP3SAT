/*
 * send_transmit.c
 *
 * Created: 3/4/2021 5:27:02 PM
 *  Author: mattp
 */

#include "send_transmit.h"

void serial_rx_cb(const struct usart_async_descriptor *const io_descr);

void transmit(void);
void receive_callback();

volatile uint8_t serial_receiving = 0;
volatile uint8_t serial_complete = 0;

// bytes received counters
volatile uint8_t byteCount = 0;
volatile uint8_t totalBytes = 0;

//receive buffer size
#define SERIAL_BUFFER_SIZE 128

//Receive and transmit buffers
volatile uint8_t rx_buffer[SERIAL_BUFFER_SIZE] = {0x00};
volatile uint8_t tx_buffer[SERIAL_BUFFER_SIZE + 20] = {0x00};
//volatile uint8_t command_buffer[SERIAL_BUFFER_SIZE] = {0x00};

static SPPEvent Rxevent;

//Receive Callback function
void serial_rx_cb(const struct usart_async_descriptor *const io_descr)
{
	 //QueueBuffer queueBuff;
	//vTaskSuspendAll();
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
			//total bytes
			totalBytes = byteCount - 2;
			
			//reset flags
			serial_receiving = 0;
			serial_complete = 0;
			
			//copy message
			//memcpy(tx_buffer + 20, rx_buffer, SERIAL_BUFFER_SIZE); //get rid of "Processing Command: " from buffer
			//memcpy(command_buffer, rx_buffer, SERIAL_BUFFER_SIZE); // can delete this later
			
			//stores command into struct
			Rxevent.pvData = rx_buffer;
			Rxevent.eventType = eUSARTRxEvent;
			
			xQueueSendFromISR(SPQ, &Rxevent, configMAX_PRIORITIES-1);
			//print message
			
			//io_write(&SERIAL.io, &tx_buffer, totalBytes + 22);
			
			//clear memory
			memset(&rx_buffer, 0x00, SERIAL_BUFFER_SIZE);
			
		}
		//overflow check
		if (byteCount >= SERIAL_BUFFER_SIZE)
		{
			//reset buffer counter
			byteCount = 0;
		}
	}
}


static void serial_tx_cb(const struct usart_async_descriptor *const io_descr) {
	
}

void async_setup() {
	usart_async_register_callback(&SERIAL, USART_ASYNC_TXC_CB, serial_tx_cb);
	usart_async_register_callback(&SERIAL, USART_ASYNC_RXC_CB, serial_rx_cb);
	usart_async_enable(&SERIAL);
}