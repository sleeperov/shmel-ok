
// Utility functions

#pragma once

#include <math.h>
#include <soc/soc.h>
#include <soc/rtc_cntl_reg.h>

const float ONE_G = 9.80665;

float mapf(long x, long in_min, long in_max, float out_min, float out_max) {
	return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

float mapff(float x, float in_min, float in_max, float out_min, float out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Wrap angle to [-PI, PI)
float wrapAngle(float angle) {
	angle = fmodf(angle, 2 * PI);
	if (angle > PI) {
		angle -= 2 * PI;
	} else if (angle < -PI) {
		angle += 2 * PI;
	}
	return angle;
}

template <typename T, int N>
void printArray(const T (&arr)[N]) {
	for (int i = 0; i < N; i++) {
		Serial.printf("%g ", static_cast<float>(arr[i]));
	}
	Serial.println();
}

// Disable reset on low voltage
void disableBrownOut() {
	REG_CLR_BIT(RTC_CNTL_BROWN_OUT_REG, RTC_CNTL_BROWN_OUT_ENA);
}
