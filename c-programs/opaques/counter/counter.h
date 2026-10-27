#ifndef COUNTER_H
#define COUNTER_H

#include "stdint.h"

typedef struct Counter_t Counter_t;

// API -> users can only interact through this
Counter_t* counter_create(void);
void counter_increment(Counter_t* counter);
uint32_t counter_get_value(const Counter_t* counter);
void counter_destroy(Counter_t* counter);

#endif