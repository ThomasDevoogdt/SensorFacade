//
// Created by thomas on 25/11/17.
//

#ifndef SENSOR_ITIMERPROVIDER_H
#define SENSOR_ITIMERPROVIDER_H

#include <Arduino.h>

class ITimeProvider {
public:
	/**
	 * an abstract time provider function
	 * @return abstract version returns always NAN
	 */
	virtual unsigned long getTime() { return NAN; }
};

#endif //SENSOR_ITIMERPROVIDER_H
