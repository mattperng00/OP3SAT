/*
 * free_buffers.h
 *
 * Created: 4/13/2021 6:59:59 PM
 *  Author: anyis
 */ 


#ifndef FREE_BUFFERS_H_
#define FREE_BUFFERS_H_

#include <atmel_start.h>

QueueHandle_t FBQ;

int free_buffer_init(int num_buffers, int buf_size);

void return_buffer(void* buffer);

#endif /* FREE_BUFFERS_H_ */