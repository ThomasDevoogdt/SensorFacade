//
// Created by thomas on 25/11/17.
//

#include <SensorFacade.h>

SensorFacade sensorFacade = SensorFacade();

class CostumSensor : public Sensor {
private:
public:
	CostumSensor(String name) : Sensor(name) {
		//
	}

	// when sensor needs periodic attention, don't impliment getData
	void update() override {
		data.value = NAN;
		data.time = timeProvider->getTime();
	}

	// or

	// in this case don't impliment update()
	Data getData() override {
		data.value = NAN;
		data.time = timeProvider->getTime();
		return data;
	}
};

class CostumSensorHolder : public SensorSet {
private:
	// pointers for ease use
	Sensor *costumSensor1;
	Sensor *costumSensor2;
	Sensor *costumSensor3;

public:
	explicit CostumSensorHolder() {

	};

	void registerCostumSensor1(Sensor *costumSensor1) {
		this->costumSensor1 = costumSensor1; // direct pointer
		this->addSensor(costumSensor1); // register in sensorSet
	}

	void registerCostumSensor2(Sensor *costumSensor2) {
		this->costumSensor2 = costumSensor2; // direct pointer
		this->addSensor(costumSensor2); // register in sensorSet
	}

	void registerCostumSensor3(Sensor *costumSensor3) {
		this->costumSensor3 = costumSensor3; // direct pointer
		this->addSensor(costumSensor3); // register in sensorSet
	}

	void begin() {

	}

	void update() {
		if (costumSensor1 != nullptr) {
			setSensorData(costumSensor1, Data(
					1,
					timeProvider->getTime()));
		}

		if (costumSensor2 != nullptr) {
			setSensorData(costumSensor2, Data(
					2,
					timeProvider->getTime()));
		}

		if (costumSensor3 != nullptr) {
			setSensorData(costumSensor3, Data(
					3,
					timeProvider->getTime()));
		}
	}
};

void setup() {
	Serial.begin(115200);
	Serial.println("Starting Up");

	CostumSensorHolder *costumSensorHolder = new CostumSensorHolder();
	costumSensorHolder->registerCostumSensor1(new Sensor("sensor_holder_1"));
	costumSensorHolder->registerCostumSensor2(new Sensor("sensor_holder_2"));
	costumSensorHolder->registerCostumSensor3(new Sensor("sensor_holder_3"));
	sensorFacade.addSensorSet(costumSensorHolder);

	sensorFacade.addSensor(new CostumSensor("sensor"));

	sensorFacade.setSensorItr([](String name, Data data) {
		//data.value - data.time
		Serial.print("Sensor: " + name);
		Serial.println("Data: " + String(data.value));
	});

	sensorFacade.begin();
}

void loop() {
	// update sensor values
	sensorFacade.update();

	// iterate over sensors
	sensorFacade.ItrSensor();

	delay(1000);
}