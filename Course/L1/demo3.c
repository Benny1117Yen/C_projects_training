//PPT_replace the last value_will get different result.
/*
#include <stdint.h>
#include <stdio.h>
int32_t abs(int32_t x) {
    int32_t mask = (x >> 31);
    return (x + mask) ^ mask;
}
int main() {
	printf("=> %d\n", abs(-2147483648));
}
*/
#include <stdio.h>
#include <stdint.h>
int32_t test(int32_t x) {
    int mask = x >> 31;
    printf("mask = %d, x + mask = %d\n", mask, x + mask);
    return (x + mask) ^ mask;
}
int main(void) {
    printf("abs(INT32_MIN) = %d\n", test(-2147483648));
    return 0;
}
