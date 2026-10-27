#ifndef SENSOR_OOP_H
#define SENSOR_OOP_H


/// class sensor
typedef struct Sensor Sensor;

struct Sensor {
    int filter_frequency;
    int update_frequency;
    int value;
}

int sensor_get_filter_frequency(const Sensor* const me);
int sensor_set_filter_frequency(const Sensor* const me, f);


#endif