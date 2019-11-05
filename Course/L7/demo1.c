#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MSG_LEN 8

static inline bool is_divisible(u_int32_t n, u_int64_t M) {
    return n * M <= M - 1;
}

static u_int64_t M3 = __INT64_C(0xFFFFFFFFFFFFFFFF) / 3 + 1;
static u_int64_t M5 = __INT64_C(0xFFFFFFFFFFFFFFFF) / 5 + 1;

int main(int argc, char **argv) {
    for (size_t i = 1; i <= 100; i++) {
        u_int8_t div3 = is_divisible(i, M3);
        u_int8_t div5 = is_divisible(i, M5);
        unsigned int length = (2 << div3) << div5;

        char fmt[MSG_LEN + 1];
        strncpy(fmt, &"FizzBuzz%u"[(MSG_LEN >> div5) >> (div3 << 2)], length);
        fmt[length] = '\0';

        printf(fmt, i);
        printf("\n");
    }
    return 0;
}
