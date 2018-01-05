//
// Created by thomas on 25/11/17.
//

#ifndef SENSOR_SENSORFACADE_H
#define SENSOR_SENSORFACADE_H

#include "Arduino.h"
#include "SensorLinkedList.h"
#include "Data.h"
#include "ITimeProvider.h"
#include "ISensor.h"
#include "Sensor.h"
#include "SensorSet.h"

class Sensor;

class SensorSet;

class SensorFacade : public ISensor {
	// Class Fields
protected:
	ITimeProvider *timeProvider;

	// list with all sensors
	SensorLinkedList<Sensor *> sensorList;

	// list for updating (individual sensors and sensor sets)
	SensorLinkedList<ISensor *> updateList;

	void (*sensorItr)(String, Data);

	// Class Methods
public:
	/**
	 * creates a sensor facade instance
	 */
	SensorFacade();

	/**
	 * creates a sensor facade instance with a time provider
	 * @param timeProvider
	 */
	explicit SensorFacade(ITimeProvider *timeProvider);

	/**
	 * creates a sensor facade instance with a iteration callback
	 * @param sensorItr
	 */
	explicit SensorFacade(void (*sensorItr)(String, Data));

	/**
	 * creates a sensor facade with a time provider and a iteration callback
	 * @param timeProvider
	 * @param sensorItr
	 */
	SensorFacade(ITimeProvider *timeProvider, void (*sensorItr)(String, Data));

	/**
	 * add a sensor
	 * @param sensor
	 */
	void addSensor(Sensor *sensor);

	/**
	 * add a sensor set
	 * @param sensorSet
	 */
	void addSensorSet(SensorSet *sensorSet);

	/**
	 * get a sensor by index
	 * @param index
	 * @return
	 */
	Sensor *getSensor(int index);

	/**
	 * set a callback for teh sensor iteration
	 * @param sensorItr
	 */
	void setSensorItr(void (*sensorItr)(String, Data));

	/**
	 * iterate over all the sensors using the predefined callback
	 */
	void ItrSensor();

	/**
	 * get number of sensors
	 * @return
	 */
	int size();

	/**
	 * call update function of all sensors
	 */
	void update() override;

	/**
	 * call begin function of all sensors
	 */
	void begin() override;
};

#endif //SENSOR_SENSORFACADE_H
