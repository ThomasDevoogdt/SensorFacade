//
// Created by thomas on 25/11/17.
//

#include <SensorFacade.h>
#include "BMPholder.h"

SensorFacade sensorFacade = SensorFacade();

void setup() {
	Serial.begin(115200);
	Serial.println("Starting Up");

	// ITimeProvider is just a dummy time provider
	BMPholder *bmpHolder = new BMPholder(new ITimeProvider());
	bmpHolder->registerTemperatureSensor(new Sensor("bmp_temp"));
	bmpHolder->registerAltitudeSensor(new Sensor("bmp_alt"));
	bmpHolder->registerPressureSensor(new Sensor("bmp_press"));
	sensorFacade.addSensorSet(bmpHolder);

	sensorFacade.setSensorItr([](String name, Data data) {
		//data.value - data.time
		Serial.print("Sensor: " + name);
		Serial.println("Data: " + String(data.value));
	});

	// init sensors
	sensorFacade.begin();
}

void loop() {
	// update sensor values
	sensorFacade.update();

	// iterate over sensors
	sensorFacade.ItrSensor();

	delay(1000);
}