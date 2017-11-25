//
// Created by thomas on 25/11/17.
//

#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include <Arduino.h>

struct Data {
	Data() = default;

	Data(float value, unsigned long time) {
		this->value = value;
		this->time = time;
	}

	float value = NAN;
	unsigned long time = NAN;
};

#endif //SENSOR_DATA_H
