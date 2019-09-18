//Quiz1.
#include <stdio.h>
#define align4(x) (((x) + 3) & (-4))
int main(void) {
    int p = 0x1997;
    printf("align4(p) is %08x\n", align4(p));
    return 0;
}
