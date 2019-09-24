//Quiz1. Lab.
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
	printf("%d\n", p);
	printf("%x\n", p);
	printf("%016x\n", p);
	printf("%08x\n", align4(p, 3));
	printf("%d\n", ~~~0x03);
	printf("%08x\n", -4);
	printf("%08x\n", (((0x1006) + (0x03)) & (~0x03)));
	__uint32_t aa = 1;
	printf("value of a = 0x%x\n", aa);
	int arr[5] = {0};
	printf("%d\n", arr[4]);
	int mask = -123 >> 1;
	printf("%d\n", mask);
	int pp = 0x01;
	printf("%x\n", pp);
	return 0;
}
