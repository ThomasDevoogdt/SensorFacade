//
// Created by thomas on 25/11/17.
//

#ifndef SENSOR_SENSOR_H
#define SENSOR_SENSOR_H

#include "SensorFacade.h"

class SensorFacade;

class SensorSet;

class Sensor : public ISensor {
	// Class Fields
protected:
	Data data;
	String name;
	ITimeProvider *timeProvider;

	// Class Methods
protected:
	virtual void setData(Data data);

public:
	explicit Sensor(String name, ITimeProvider *timeProvider);

	Sensor(String name);

	virtual Data getData();

	String getName();

	friend SensorFacade;
	friend SensorSet;
};

#endif //SENSOR_SENSOR_H
