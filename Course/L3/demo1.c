#include <stdio.h>
#include <stdlib.h>

float ReLU(float x) {
    union {
        float f;
        __uint32_t i;                          
    } out = {.f = x};
	printf("%08x\n", out.i);
	printf("%08x\n", (out.i >> 16));
	printf("%08x\n", ~(out.i >> 31));
    out.i = out.i &  ~(out.i >> 31);
    return out.f;
}

int main() {
	printf("%f\n", ReLU(-1000));
	return 0;
}
