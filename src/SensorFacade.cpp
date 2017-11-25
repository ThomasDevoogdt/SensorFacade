//
// Created by thomas on 16/11/17.
//

#include "SensorFacade.h"

SensorFacade::SensorFacade() :
		sensorList(SensorLinkedList<Sensor *>([](Sensor *p) { delete p; })),
		updateList(SensorLinkedList<ISensor *>([](ISensor *p) { delete p; })) {
	this->timeProvider = new ITimeProvider();
	this->sensorItr = nullptr;
}

SensorFacade::SensorFacade(void (*sensorItr)(String, Data)) :
		sensorList(SensorLinkedList<Sensor *>([](Sensor *p) { delete p; })),
		updateList(SensorLinkedList<ISensor *>([](ISensor *p) { delete p; })) {
	this->timeProvider = new ITimeProvider();
	this->sensorItr = sensorItr;
}

SensorFacade::SensorFacade(ITimeProvider *timeProvider) :
		sensorList(SensorLinkedList<Sensor *>([](Sensor *p) { delete p; })),
		updateList(SensorLinkedList<ISensor *>([](ISensor *p) { delete p; })) {
	this->timeProvider = timeProvider;
	this->sensorItr = nullptr;
}

SensorFacade::SensorFacade(ITimeProvider *timeProvider, void (*sensorItr)(String, Data)) :
		sensorList(SensorLinkedList<Sensor *>([](Sensor *p) { delete p; })),
		updateList(SensorLinkedList<ISensor *>([](ISensor *p) { delete p; })) {
	this->timeProvider = timeProvider;
	this->sensorItr = sensorItr;
}


void SensorFacade::addSensor(Sensor *sensor) {
	sensorList.add(sensor);
	updateList.add(sensor);
}

void SensorFacade::addSensorSet(SensorSet *sensorSet) {
	updateList.add(sensorSet);
	for (const auto &sensor:sensorSet->getSensors()) {
		sensorList.add(sensor);
	}
}

Sensor *SensorFacade::getSensor(int index) {
	return *sensorList.nth((size_t) index);
}

void SensorFacade::setSensorItr(void (*sensorItr)(String, Data)) {
	this->sensorItr = sensorItr;
}

void SensorFacade::ItrSensor() {
	for (const auto &sensor: sensorList) {
		sensorItr(sensor->getName(), sensor->getData());
	}
}

int SensorFacade::size() {
	return sensorList.length();
}

void SensorFacade::update() {
	for (const auto &sensor: updateList) {
		sensor->update();
	}
}

void SensorFacade::begin() {
	for (const auto &sensor: updateList) {
		sensor->begin();
	}
}

