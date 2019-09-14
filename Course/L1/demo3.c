#include <stdint.h>
#include <stdio.h>
int32_t abs(int32_t x) {
    int32_t mask = (x >> 31);
    return (x + mask) ^ mask;
}
int main() {
	printf("=> %d\n", abs(-2147483647));
}
