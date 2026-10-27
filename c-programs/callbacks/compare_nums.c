#include <stdio.h>

// callback function to compare 2 number
int comp(int a, int b) {
    if (a > b) return a;
    return b;
}

void max(int (*comp_cb)(int, int), int x, int y) {
    int r = comp_cb(x, y);
    printf("Given numbers: %d, %d\n", x, y);
    printf("%d is greater\n", r);
}


int main() {
    int j = 7, k = 89;

    max(comp, j, k);

    return 0;
}