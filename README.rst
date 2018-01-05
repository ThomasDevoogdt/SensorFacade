SensorFacade
============

Link to github: https://github.com/ThomasDevoogdt/SensorFacade.git

|travis| |appveyor| |codacy| |licenses| |readthedocs|

.. |travis| image:: https://travis-ci.org/ThomasDevoogdt/SensorFacade.svg?branch=master
   :target: https://travis-ci.org/ThomasDevoogdt/SensorFacade
   :alt: Build-Status
.. |appveyor| image:: https://ci.appveyor.com/api/projects/status/0nv4cain07atylad?svg=true
   :target: https://ci.appveyor.com/project/ThomasDevoogdt/sensorfacade
   :alt: Build-status
.. |codacy| image:: https://api.codacy.com/project/badge/Grade/179f0487570841ff9782e92fa1551740
   :target: https://www.codacy.com/app/ThomasDevoogdt/SensorFacade?utm_source=github.com&utm_medium=referral&utm_content=ThomasDevoogdt/SensorFacade&utm_campaign=Badge_Grade
   :alt: Codacy-Badge
.. |licenses| image:: https://img.shields.io/badge/License-MIT-yellow.svg
   :target: https://opensource.org/licenses/MIT
   :alt: License: MIT
.. |readthedocs| image:: https://readthedocs.org/projects/sensorfacade/badge/?version=latest
   :target: http://sensorfacade.readthedocs.io/en/latest/?badge=latest
   :alt: Documentation Status

This library provides a facade for sensor data. It provides a way to
attach, initialize, update and read the data. New sensors should inherit
from the **Sensor** class. If the sensor needs periodic attention or the
read out takes a long time, implement the *update* function. If the
sensor is just a simple analog reader, implement the *getData* function.
Each sensors is provided with a name so it can directly used for e.g. a
MQTT topic. Sensors with multiple metrics should inherit from
**SensorSet** with contains a set of sensors


TODO:
=====

-  Port to arduino-IDE
-  Add sensors

Note: I’m working on Ubuntu 16.04 with PlatformIO, version 3.4.1 and GCC
version 5.4.0

Install
=======

::

    pio lib install https://github.com/ThomasDevoogdt/SensorFacade.git

platformio.ini
==============

If you’re trying to compile sensor_bmp, add all the necessary
dependencies

.. code:: ini

    [env:d1_mini]
    platform = espressif8266
    board = d1_mini
    framework = arduino

    lib_deps =
        Adafruit BMP085 Unified
        Adafruit Unified Sensor
        Wire

Usage
=====

.. code:: cpp

    //
    // Created by thomas on 25/11/17.
    //

    #include <SensorFacade.h>
    #include "CostumSensorHolder.h"
    #include "CostumSensor.h"

    SensorFacade sensorFacade = SensorFacade();

    void setup() {
        Serial.begin(115200);
        Serial.println("Starting Up");

        auto *costumSensorHolder = new CostumSensorHolder();
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

Add single sensor
=================

.. code:: cpp

    //
    // Created by thomas on 25/11/17.
    //

    #ifndef SENSORFACADE_COSTUMSENSOR_H
    #define SENSORFACADE_COSTUMSENSOR_H

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
        }

        // or

        // in this case don't impliment update()
        Data getData() override {
            data.value = NAN;
            data.time = timeProvider->getTime();
            return data;
        }
    };

    #endif //SENSORFACADE_COSTUMSENSOR_H

Add sensor group
================

.. code:: cpp

    //
    // Created by thomas on 25/11/17.
    //

    #ifndef SENSORFACADE_COSTUMSENSORHOLDER_H
    #define SENSORFACADE_COSTUMSENSORHOLDER_H

    #include "Arduino.h"
    #include "SensorFacade.h"

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

    #endif //SENSORFACADE_COSTUMSENSORHOLDER_H


----

This software is released under an MIT license. See the attached LICENSE file for details.