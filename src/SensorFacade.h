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

extern "C" {
#include "user_interface.h"
}

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
	SensorFacade();

	explicit SensorFacade(ITimeProvider *timeProvider);

	explicit SensorFacade(void (*sensorItr)(String, Data));

	SensorFacade(ITimeProvider *timeProvider, void (*sensorItr)(String, Data));

	void addSensor(Sensor *sensor);

	void addSensorSet(SensorSet *sensorSet);

	Sensor *getSensor(int index);

	void setSensorItr(void (*sensorItr)(String, Data));

	void ItrSensor();

	int size();

	void update() override;

	void begin() override;
};

#endif //SENSOR_SENSORFACADE_H
