// user code 
#include <stdio.h>

#include "counter.h"

int main() {
    Counter_t* counter = counter_create();

    printf("Counter value: %d\r\n", counter_get_value(counter) );

    counter_increment(counter);

    printf("Counter value: %d\r\n", counter_get_value(counter) );

    return 0;
}