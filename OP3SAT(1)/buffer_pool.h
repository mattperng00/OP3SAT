/*
 * buffer_pool.h
 *
 * Created: 4/13/2021 6:59:59 PM
 *  Author: anyis
 */ 


#ifndef BUFFER_POOL_H_
#define BUFFER_POOL_H_

#include <atmel_start.h>

QueueHandle_t FBQ;

int free_buffer_init(int num_buffers, int buf_size);


#endif /* BUFFER_POOL_H_ */