//
//
// Created by thomas on 25/11/17.
//

#ifndef SENSOR_ISENSOR_H
#define SENSOR_ISENSOR_H

/**
 * an abstract sensor class
 *
 */
class ISensor {
public:
	/**
	 * use for sensors that needs periodic attention
	 *
	 */
	virtual void update() {
		//
	}

	/**
	 * use for sensors that needs initialization
	 *
	 */
	virtual void begin() {
		//
	}
};

#endif //SENSOR_ISENSOR_H
