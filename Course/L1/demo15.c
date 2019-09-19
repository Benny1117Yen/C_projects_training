#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _s1 {
    char a[5];
} s1;
//#pragma pack(1)
typedef struct _test1 {
    char c[3];
    int num[256];
} test1;
//#pragma pack(pop)

typedef struct _test2 {
    char c[3];
    int num[256];
} test2;
int main() {
    s1 p[10];
    printf("struct s1 size: %ld byte\n", sizeof(s1));
	printf("struct s1 size: %ld byte\n", sizeof(test1));
	printf("struct s1 size: %ld byte\n", sizeof(test2));
    for(int i = 0; i < 10; i++) {
        printf("the struct p[%d] address =%p\n", i, p + i);
    }
}
