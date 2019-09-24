#include <stdio.h>


#define ALIGN(x,a)        __ALIGN_MASK(x,(typeof(x))(a)-1)
#define __ALIGN_MASK(x,mask)	(((x)+(mask))&~(mask))


int main() {
	int x = 0x1006;
	printf("%08x\n", ALIGN(x, 4));
	return 0;
}
