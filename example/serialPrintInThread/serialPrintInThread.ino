#include <FreeRTOS_SAMD.h>

static void printerThread( void *pvParameters ) {
	int cycleCount = 0;
	char s[20];

	SerialUSB.println("printerThread started");

	while (1) {
		// delay and delayMicroseconds are task compatible
		rt_delayMicroseconds(1500);	// idle for 1.5 ms
		rt_delay(1500);				// idle for 1.5 s

		itoa(cycleCount++, s, 10);
		SerialUSB.print("printerThread count: ");
		SerialUSB.println(s);
	}
}

static void rtosLoopThread( void *pvParameters ) {
	while (1)
		loop();
}

void setup() {
	delay(1000);
	SerialUSB.begin(115200);
    while (!SerialUSB);

	xTaskCreate(rtosLoopThread, "loop",128, NULL, tskIDLE_PRIORITY, NULL);
	xTaskCreate(printerThread, "test", 128, NULL, tskIDLE_PRIORITY, NULL);

	//vTaskStartScheduler();
	rtos_run(); // call instead of vTaskStartScheduler, because some methods need to be remapped
}

void loop() {
	// loop is called by FreeRtos
	SerialUSB.println("threaded loop");
	rt_delay(1000);
}
