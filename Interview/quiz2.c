#include <stdio.h>

int fun(int x) { /* ex. 456 & 455 = 111000000 -> 448; 448 & 447 = 110000000 -> 384;
384 & 383 = 100000000 -> 256; 256 & 255 = 0; Total count = 4 */
    int count = 0;
    while(x) {
        count++;
        x = x & (x - 1);
    }
    return count;
}

int main() {
    int a = fun(456);
    int b = fun(123);
    int c = fun(789);
    int d = a + b + c;
    printf("%d\t", d);
    return 0;
}