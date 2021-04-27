/*
 * tod_processor.h
 *
 * Created: 4/26/2021 6:51:37 PM
 *  Author: anyis
 */ 


#ifndef TOD_PROCESSOR_H_
#define TOD_PROCESSOR_H_

#include <atmel_start.h>
#include "sppe.h"
#include "spp.h"
#include "msg_router.h"
#include "timeofday.h"

void tod_processor_task(void *pvParameters);



#endif /* TOD_PROCESSOR_H_ */