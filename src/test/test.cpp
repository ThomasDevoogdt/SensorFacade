//
// Created by thomas on 25/11/17.
//

//#define sensor_log
#define sensor_bmp

#ifdef sensor_log

#include "../../examples/sensor_log/sensor_log.ino"

#endif

#ifdef sensor_bmp

#include "../../examples/sensor_bmp/BMPholder.h"
#include "../../examples/sensor_bmp/BMPholder.cpp"
#include "../../examples/sensor_bmp/sensor_bmp.ino"

#endif
