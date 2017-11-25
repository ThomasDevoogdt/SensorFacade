//
//
// Created by thomas on 25/11/17.
//

#ifndef SENSOR_ISENSOR_H
#define SENSOR_ISENSOR_H

class ISensor {
public:
	virtual void update() {
		// use for sensors that needs periodic attention
	}

	virtual void begin() {
		// use for sensors that needs initialization
	}
};

#endif //SENSOR_ISENSOR_H
