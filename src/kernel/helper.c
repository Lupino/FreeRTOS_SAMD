#include "helper.h"

void rt_delayMicroseconds(uint32_t usec) {

	vTaskDelay(usec / portTICK_PERIOD_US);
}

uint32_t rt_micros(void) {
	return xTaskGetTickCount() * portTICK_PERIOD_US;
}

uint32_t rt_millis(void) {
	return (xTaskGetTickCount() * portTICK_PERIOD_US) / 1000;
}

void rt_delay(uint32_t ms) {
	vTaskDelay((ms * 1000) / portTICK_PERIOD_US);
}

void rtos_run() {
	vTaskStartScheduler();
}

extern void (*rtosSysTick_Handler)(void);
void rtos_stop() {
	portENTER_CRITICAL();
	rtosSysTick_Handler = NULL;
	portEXIT_CRITICAL();
}
