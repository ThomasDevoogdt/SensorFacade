//
// Created by thomas on 25/11/17.
//

#ifndef SENSOR_SENSOR_H
#define SENSOR_SENSOR_H

#include "SensorFacade.h"

class SensorFacade;

class SensorSet;

/**
 * Each metric of each sensor should have an sensor implementation.
 * Implement the the update method or override the getData method.
 *
 */
class Sensor : public ISensor {
	// Class Fields
protected:
	Data data;
	String name;
	ITimeProvider *timeProvider;

	// Class Methods
protected:
	/**
	 * set sensor data, used in sensorSet
	 *
	 * @param data
	 */
	virtual void setData(Data data);

public:
	/**
	 *
	 * @param name of the sensor instance
	 * @param timeProvider
	 */
	explicit Sensor(String name, ITimeProvider *timeProvider);

	/**
	 *
	 * @param name of the sensor instance
	 */
	Sensor(String name);

	/**
	 *
	 * @return last captured data
	 */
	virtual Data getData();

	/**
	 *
	 * @return name of the sensor instance - used for e.g. MQTT topic
	 */
	String getName();

	friend SensorFacade;
	friend SensorSet;
};

#endif //SENSOR_SENSOR_H
