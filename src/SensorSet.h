//
// Created by thomas on 25/11/17.
//

#ifndef SENSOR_SENSORSET_H
#define SENSOR_SENSORSET_H

#include "SensorFacade.h"

class Sensor;

class SensorFacade;

/**
 * A sensor set helps you to add sensor metrics to one container. e.g. a sensor that can reads the temperature as well
 * the pressure.
 *
 */
class SensorSet : public ISensor {
protected:
	ITimeProvider *timeProvider;
	SensorLinkedList<Sensor *> sensors;

	/**
	 * add a sensor to the sensor set
	 *
	 * @param sensor
	 */
	void addSensor(Sensor *sensor);

	/**
	 *
	 * @brief The standard says (ISO/IEC 14882:2003, section 11.4.8): Friendship is neither inherited nor transitive.
	 * Intermediate step required!
	 *
	 * @param sensor reference
	 * @param data object
	 */
	void setSensorData(Sensor *sensor, Data data);
	// The standard says (ISO/IEC 14882:2003, section 11.4.8):
	// Friendship is neither inherited nor transitive.
	// Intermediate step required!

public:
	/**
	 * creates a sensor set
	 */
	SensorSet();

	/**
	 * creates a sensor set with a time provider
	 * @param timeProvider
	 */
	SensorSet(ITimeProvider *timeProvider);

	/**
	 * call begin function of all sensors
	 */
	void begin() override;

	/**
	 * call update function of all sensors
	 */
	void update() override;

	/**
	 *
	 * @return all the sensors of the container
	 */
	SensorLinkedList<Sensor *> getSensors();

	friend SensorFacade;
};

#endif //SENSOR_SENSORSET_H
