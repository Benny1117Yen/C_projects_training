#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


static inline uint32_t sex32(int32_t x) {
    union {
        int w;
        struct { uint32_t lo, hi; }; /* FIXME: little-endian */
    } z = {.w = x};
    return z.hi;
}


static inline int abs_with_sex(int x) {
    return (x ^ sex32(x)) | sex32(x);
}

int main() {
	printf("%d\n", SEX(123));
	printf("%d\n", abs_with_sex(1));
	return 0;
}
