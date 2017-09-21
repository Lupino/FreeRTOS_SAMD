#ifndef HELPER_H_
#define HELPER_H_

#include <Arduino.h>
#include "FreeRTOS.h"
#include "task.h"

#define portTICK_PERIOD_US			( ( TickType_t ) 1000000 / configTICK_RATE_HZ )

#ifdef __cplusplus
extern "C" {
#endif


void rtos_run(void);
void rtos_stop(void);

void rt_delayMicroseconds(uint32_t usec);
uint32_t rt_micros(void);
uint32_t rt_millis(void);
void rt_delay(uint32_t ms);

#ifdef __cplusplus
}
#endif


#endif /* HELPER_H_ */
