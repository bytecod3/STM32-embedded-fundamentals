#include <stdio.h>
#include <stdint.h>

typedef struct __attribute__((packed)) {
    uint32_t b;
    uint8_t a;
} Example_t;

int main() {

    size_t s = sizeof(Example_t);
    printf("Size of example struct is %d\n", s);
    return 0;

}