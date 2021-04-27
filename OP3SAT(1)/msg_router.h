/*
 * msg_router.h
 *
 * Created: 4/1/2021 7:00:54 PM
 *  Author: mattp
 */ 


#ifndef MSG_ROUTER_H_
#define MSG_ROUTER_H_

#include <atmel_start.h>
#include <stdint.h>
#include "spp.h"
#include "sppe.h"

void msg_router_task(void *pvParameters);

QueueHandle_t MRQ;


#endif /* MSG_ROUTER_H_ */