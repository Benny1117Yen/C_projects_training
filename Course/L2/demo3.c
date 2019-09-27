#include <stdint.h>
#include <stdio.h>
static inline uint32_t sex32(int32_t x) {
    union {
        uint64_t w;
        struct { uint32_t lo, hi; }; /* FIXME: little-endian */
    } z = {.w = x};
    return z.hi;
}
int main() {
	printf("%08x\n", sex32(-3));
	return 0;
}
