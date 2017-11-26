//
// Created by thomas on 26/11/17.
//

#ifndef SENSORFACADE_BMPHOLDER_H
#define SENSORFACADE_BMPHOLDER_H

#include "Arduino.h"
//#include <Wire.h>
#include "Adafruit_Sensor.h"
#include "Adafruit_BMP085_U.h"

#include "SensorFacade.h"

class BMPholder : public SensorSet {
private:
	Adafruit_BMP085_Unified *bmp;
	ITimeProvider *timeProvider;
	bool init;

	// pointers for ease use
	Sensor *temperatureSensor;
	Sensor *pressureSensor;
	Sensor *altitudeSensor;

public:
	explicit BMPholder(ITimeProvider *timeProvider);

	void registerPressureSensor(Sensor *pressureSensor) {
		this->pressureSensor = pressureSensor; // direct pointer
		this->addSensor(pressureSensor); // register in sensorSet
	}

	void registerTemperatureSensor(Sensor *temperatureSensor) {
		this->temperatureSensor = temperatureSensor; // direct pointer
		this->addSensor(temperatureSensor); // register in sensorSet
	}

	void registerAltitudeSensor(Sensor *altitudeSensor) {
		this->altitudeSensor = altitudeSensor; // direct pointer
		this->addSensor(altitudeSensor); // register in sensorSet
	}

	void update() override;

	void begin() override;
};

#endif //SENSORFACADE_BMPHOLDER_H
