# Install

```
pio lib install https://github.com/ThomasDevoogdt/SensorFacade.git
```

# Usage

```c++
#include <SensorFacade.h>

SensorFacade sensorFacade();

void setup() {
    auto *costumSensorHolder = new CostumSensorHolder();
    costumSensorHolder->registerCostumSensor1(new Sensor("name"));
    costumSensorHolder->registerCostumSensor2(new Sensor("name"));
    costumSensorHolder->registerCostumSensor3(new Sensor("name"));
    sensorFacade.addSensorSet(costumSensorHolder);

    sensorFacade.addSensor(new CostumSensor("name"))

    sensorFacade.setSensorItr([](String name, Data data) {
            //data.value - data.time
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

```

# Add single sensor

```c++
//
// Created by thomas on 24/11/17.
//

#ifndef COSTUM_SENSOR
#define COSTUM_SENSOR

#include "Arduino.h"
#include "SensorFacade.h"

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
		return data;
    }

	// or

	// in this case don't impliment update()
	Data getData() override {
		data.value = NAN;
		data.time = timeProvider->getTime();
		return data;
	}
};

#endif
```

# Add sensor group

```c++
//
// Created by thomas on 16/11/17.
//

#ifndef COSTUM_SENSOR_GROUP
#define COSTUM_SENSOR_GROUP

#include "Arduino.h"
#include "SensorFacade.h"

class CostumSensorHolder : public SensorSet {
private:

	// pointers for ease use
	Sensor *costumSensor1;
	Sensor *costumSensor2;
	Sensor *costumSensor3;

public:
	explicit CostumSensorHolder();

	void registerCostumSensor1(Sensor *costumSensor1) {
		this->costumSensor1 = costumSensor1; // direct pointer
		this->addSensor(costumSensor1); // register in sensorSet
	}

	void registerCostumSensor1(Sensor *costumSensor2) {
		this->costumSensor2 = costumSensor2; // direct pointer
		this->addSensor(costumSensor2); // register in sensorSet
	}

	void registerCostumSensor1(Sensor *costumSensor3) {
		this->costumSensor1 = costumSensor3; // direct pointer
		this->addSensor(costumSensor3); // register in sensorSet
	}

	void update() {
        if (costumSensor1 != nullptr) {
            setSensorData(costumSensor1, Data(
                    NAN,
                    timeProvider->getTime()
            ));
        }

		if (costumSensor2 != nullptr) {
            setSensorData(costumSensor2, Data(
                    NAN,
                    timeProvider->getTime()
            ));
        }

        if (costumSensor3 != nullptr) {
            setSensorData(costumSensor3, Data(
                    NAN,
                    timeProvider->getTime()
            ));
        }
    }

	void begin() {

    }
};

#endif //COSTUM_SENSOR_GROUP
```
