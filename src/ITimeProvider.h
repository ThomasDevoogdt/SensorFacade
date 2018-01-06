//
// Created by thomas on 25/11/17.
//

#ifndef SENSOR_ITIMERPROVIDER_H
#define SENSOR_ITIMERPROVIDER_H

#include <Arduino.h>

/**
 * an abstract time provider class
 *
 */
class ITimeProvider {
public:
	/**
	 *
	 * @return abstract version returns always NAN
	 */
	virtual unsigned long getTime() { return NAN; }
};

#endif //SENSOR_ITIMERPROVIDER_H
