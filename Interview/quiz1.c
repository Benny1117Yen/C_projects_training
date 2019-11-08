#include <stdio.h>
#define MUX(a, b) a * b


int main() {
    printf("%d\t", MUX(10+5, 10-5));
    return 0;
}