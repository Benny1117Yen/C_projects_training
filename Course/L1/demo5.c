//Quiz3. rewrite program.
#include <stdbool.h>
#include <stdio.h>
bool func(unsigned int x) {
    return x && ((x & (~x + 1)) == x);       
}

bool func1(unsigned int x) {
    unsigned int unknown = 0;
    while(x && unknown <=1) {
        if ((x & 1) == 1)
            unknown++;
        x >>= 1;
   }
   return (unknown == 1);
}

int main() {
	printf("%d\n",func(0));
	printf("%d\n",func(1));
	printf("%d\n",func1(0));
	printf("%d\n",func1(1));
	return 0;
}
