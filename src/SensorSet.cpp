//
// Created by thomas on 25/11/17.
//

#include "SensorSet.h"

SensorSet::SensorSet() :
		sensors(SensorLinkedList<Sensor *>()) {
	//sensors(SensorLinkedList<Sensor *>([](Sensor *p) { delete p; })) {
	this->timeProvider = new ITimeProvider();
}

SensorSet::SensorSet(ITimeProvider *timeProvider) :
		sensors(SensorLinkedList<Sensor *>()) {
	//sensors(SensorLinkedList<Sensor *>([](Sensor *p) { delete p; })) {
	this->timeProvider = timeProvider;
}

void SensorSet::addSensor(Sensor *sensor) {
	sensors.add(sensor);
}

void SensorSet::setSensorData(Sensor *sensor, Data data) {
	sensor->setData(data);
}

void SensorSet::begin() {
	for (const auto &sensor: sensors) {
		sensor->begin();
	}
}

void SensorSet::update() {
	for (const auto &sensor: sensors) {
		sensor->update();
	}
}

SensorLinkedList<Sensor *> SensorSet::getSensors() {
	return sensors;
}