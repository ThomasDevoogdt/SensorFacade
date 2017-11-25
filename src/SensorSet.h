//
// Created by thomas on 25/11/17.
//

#ifndef SENSOR_SENSORSET_H
#define SENSOR_SENSORSET_H

#include "SensorFacade.h"

class Sensor;

class SensorFacade;

class SensorSet : public ISensor {
protected:
	ITimeProvider *timeProvider;
	SensorLinkedList<Sensor *> sensors;

	void addSensor(Sensor *sensor);

	// The standard says (ISO/IEC 14882:2003, section 11.4.8):
	// Friendship is neither inherited nor transitive.
	// Intermediate step required!
	void setSensorData(Sensor *sensor, Data data);

public:
	SensorSet();

	SensorSet(ITimeProvider *timeProvider);

	void begin() override;

	void update() override;

	SensorLinkedList<Sensor *> getSensors();

	friend SensorFacade;
};

#endif //SENSOR_SENSORSET_H
