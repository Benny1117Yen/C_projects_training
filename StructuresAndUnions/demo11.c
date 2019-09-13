#include <stdio.h>

union val {
	int int_num;
	float fl_num;
	char str[20];
};

union val nums[10];
int k;

int main() {
	for (k = 0; k < 10; k++) {
		nums[k].int_num = k;
	}

	for (k = 0; k < 10; k++) {
		printf("%d\n ", nums[k].int_num);
	}
return 0;
}
