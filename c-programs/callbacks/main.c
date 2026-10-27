#include "stdio.h"

void A() {
    printf("I am function A");
}

// callback function
void B( void(*func)() ) {
    // callback to A
    (*func)();

}

int main() {
    // function pointer to A
    void (*ptr)() = &A;

    B(ptr);

    return 0;
}