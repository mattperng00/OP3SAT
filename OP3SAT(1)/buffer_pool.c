/*
 * buffer_pool.c
 *
 * Created: 4/13/2021 6:45:57 PM
 *  Author: anyis
 */ 

#include "buffer_pool.h"

int free_buffer_init(int num_buffers, int buf_size) {
	void* buf;
	
	while (num_buffers--) {
		if (!(buf = pvPortMalloc(buf_size))) {
			break;
		}
		
		xQueueSend(FBQ, buf, 0);
	}
	
	return num_buffers;
}