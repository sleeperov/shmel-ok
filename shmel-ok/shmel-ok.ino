
#include "vector.h"
#include "quaternion.h"
#include "util.h"

#define SERIAL_BAUDRATE 115200
#define WIFI_ENABLED 1

double t = NAN; // current step time, s
float dt; // time delta from previous step, s
int16_t channels[16]; // raw rc channels
float controls[16]; // normalized controls in range [-1..1] ([0..1] for throttle)
Vector gyro; // gyroscope data
Vector acc; // accelerometer data, m/s/s
Vector rates; // filtered angular rates, rad/s
Quaternion attitude; // estimated attitude
float motors[4]; // normalized motors thrust in range [-1..1]

void setup() {
	Serial.begin(SERIAL_BAUDRATE);
	Serial.println("Initializing flix");
	disableBrownOut();
	setupParameters();
	setupLED();
	setupMotors();
	setLED(true);
#if WIFI_ENABLED
	setupWiFi();
#endif
	setupIMU();
	setupRC();
	setLED(false);
	Serial.println("Initializing complete");
}

void loop() {
	readIMU();
	step();
	readRC();
	estimate();
	control();
	sendMotors();
	parseInput();
#if WIFI_ENABLED
	processMavlink();
#endif
	logData();
	syncParameters();
}
