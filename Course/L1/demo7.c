#include <stdio.h>
#define INT_SIZE_OF(n, X, Y) \
		((sizeof(n) + sizeof(int) + X) & ~(sizeof(int) + Y))

int main() {
	char arr[13];
	short int s;
	printf("%ld\n", sizeof(int));
	printf("%ld\n", INT_SIZE_OF(4, -1, -1));
	printf("%ld\n", INT_SIZE_OF(arr, -1, -1));
	printf("%ld\n", INT_SIZE_OF(s, -1, -1));
	return 0;
}
