#include <stdio.h>
#include <stdlib.h>

float ReLU(float x) {
    union {
        float f;
        int32_t i;                          
    } out = {.f = x};
    out.i = out.i &  ~(out.i >> 31);
    return out.f;
}

int main() {
	printf("%f\n", ReLU(123.0));
	return 0;
}
