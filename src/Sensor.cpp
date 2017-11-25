//
// Created by thomas on 25/11/17.
//

#include "Sensor.h"

Sensor::Sensor(String name, ITimeProvider *timeProvider) {
	this->name = name;
	this->timeProvider = timeProvider;

	Serial.print("Begin init for: ");
	Serial.println(name);
}

Sensor::Sensor(String name) {
	this->name = name;
	this->timeProvider = new ITimeProvider();

	Serial.print("Begin init for: ");
	Serial.println(name);
}

void Sensor::setData(Data data) {
	this->data = data;
}

Data Sensor::getData() {
	return data;
}

String Sensor::getName() {
	return name;
}
