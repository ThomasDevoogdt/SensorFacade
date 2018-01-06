//
// Created by thomas on 25/11/17.
//

#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include <Arduino.h>

struct Data {
	/**
	 * default struct constructor
	 *
	 */
	Data() = default;

	/**
	 *
	 * @param value
	 * @param time
	 */
	Data(float value, unsigned long time) {
		this->value = value;
		this->time = time;
	}

	float value = NAN; /**< data enum value */
	unsigned long time = NAN; /**< data enum time */
};

#endif //SENSOR_DATA_H
