#include <stdio.h>
#define align4(x, k) (((x) + k) & (-4))

int main(){
	//printf("%d\n", (12^10));
	//printf("%x\n", (~12));
	printf("%08x\n", 0x1997);
	printf("%08x\n", ~0x0001);
	printf("%08x\n", 0x1997 & ~0x0001);
	printf("%08x\n", 0x2000 & -0x0100);
	printf("%08x\n", 0x1997 + (4-1) & -4);
	printf("%08x\n", 0x1997 + 3);
	int p = 0x1997;
	printf("%x\n", p);
	printf("%08x\n", align4(p, 3));
	return 0;
}
