//
// Created by thomas on 26/11/17.
//

#include "BMPholder.h"

BMPholder::BMPholder(ITimeProvider *timeProvider) : SensorSet(timeProvider) {
	this->timeProvider = timeProvider;
	bmp = new Adafruit_BMP085_Unified(10085);

	begin();
}

void BMPholder::begin() {
	init = bmp->begin();
	if (!init) {
		/* There was a problem detecting the BMP085 ... check your connections */
		Serial.print("Ooops, no BMP085 detected ... Check your wiring or I2C ADDR!");
	}
}

void BMPholder::update() {
	if (init) {
		/* Get a new sensor event */
		sensors_event_t event;
		bmp->getEvent(&event);

		/* Display the results (barometric pressure is measure in hPa) */
		if (event.pressure) {
			if (pressureSensor != nullptr) {
				setSensorData(pressureSensor, Data(
						event.pressure,
						timeProvider->getTime()
				));
			}

			float temperature;
			bmp->getTemperature(&temperature);

			if (temperatureSensor != nullptr) {
				setSensorData(temperatureSensor, Data(
						temperature,
						timeProvider->getTime()
				));
			}

			float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;

			if (altitudeSensor != nullptr) {
				setSensorData(altitudeSensor, Data(
						bmp->pressureToAltitude(seaLevelPressure, event.pressure),
						timeProvider->getTime()
				));
			}
		} else {
			Serial.println("BMP sensor error");
		}
	}
}