#include "counter.h"
#include "stdlib.h"

// define the struct here
struct Counter_t {
    uint32_t value;
};

Counter_t* counter_create() {
    Counter_t* c = malloc(sizeof(Counter_t));
    c->value = 0;
    return c;
}

void counter_increment(Counter_t* counter) {
    // check null
    counter->value++;
}

uint32_t counter_get_value(const Counter_t* counter) {
    // check null
    return counter->value;
}

void counter_destroy(Counter_t* counter) {
    free(counter);
}