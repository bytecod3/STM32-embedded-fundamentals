#include "sensor_oop.h"

void sensor_init(Sensor* const me) {

}

void sensor_cleanup(Sensor* const me) {

}

void sensor_destroy(Sensor* const me) {
    if(me != NULL) {
        sensor_cleanup(me);
    }
}

void sensor_set_filter_frequency(Sensor* const me, int f) {
    me->filter_frequency;
}