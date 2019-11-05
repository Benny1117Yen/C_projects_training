#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline void add_with_carry(char *input, char num, int idx) {
    char input_num = input[idx] + num;
    if (input_num <= 9) {
        input[idx] = input_num;
        return;
    }
    char carry = input_num / 10;
    input[idx] = input_num % 10;
    add_with_carry(input, carry, idx - 1);
}

#define max(a, b)               \
    ({                          \
        __typeof__(a) _a = (a); \
        __typeof__(b) _b = (b); \
        _a > _b ? _a : _b;      \
    })

static int add(const char *a1, const char *a2, char *ret, int *ppos) {
    int len1 = strlen(a1), len2 = strlen(a2);
    int len = max(len1, len2);

    int i;
    for (i = len - 1; i >= 0; i--) {
        unsigned char tmp;
        int len_diff = len1 - len2;
        if (len_diff >= 0) {
            tmp = a1[i] - '0';
            if (i > len_diff - 1)
                tmp += a2[i - len_diff] - '0';
        } else {
            tmp = a2[i] - '0';
            if (i > -len_diff - 1)
                tmp += a1[i + len_diff] - '0';
        }
        add_with_carry(ret, tmp, i + 1);
    }

    *ppos = 1;
    if (ret[0]) {
        len++;
        *ppos = 0;
    }

    for (i = 0; i < len + 1; i++)
        ret[i] += '0';

    return len;
}

char *mul(const char *m1, const char *m2) {
    int len = strlen(m1);
    int ret_len = len + strlen(m2);
    int n = 0, pos = 0, nblocks = len / 8;
    char str1[10], str2[10], resstr[20];

    char *tmp_ret = calloc(ret_len, 1);
    char *pow1 = calloc(len * 2, 1), *pow2 = calloc(len * 2, 1);
    char *ret = calloc(ret_len, 1);

    /* split into several blocks, 8 digits per block */
    for (int i = 0; i < nblocks; i++) {
        memcpy(str1, m1 + len - i * 8 - 8, 8);
        unsigned long im1 = atoi(str1);

        for (int j = 0; j < nblocks; j++) {
            memcpy(str2, m2 + len - j * 8 - 8, 8);
            unsigned long im2 = atoi(str2);
            unsigned long tmp_res = im1 * im2;

            /* multiplying pow(10,n) equals to preserving trailing '0' */
            int pow1size = i * 8, pow2size = j * 8;

            int reslen = sprintf(resstr, "%lu", tmp_res);
            int totlen = reslen + pow2size;

            memset(pow2, '0', totlen);
            memcpy(pow2, resstr, reslen);

            reslen = totlen;
            totlen += pow1size;
            memset(pow1, '0', totlen);
            pow1[totlen] = '\0';
            memcpy(pow1, pow2, reslen);

            memset(ret, 0, n + pos);

            n = add(pow1, tmp_ret, ret, &pos);
            memcpy(tmp_ret, ret + pos, n);
        }
    }
    memset(ret, 0, n + pos);
    memcpy(ret, tmp_ret, n);

    free(tmp_ret);
    free(pow1);
    free(pow2);

    return ret;
}

int main(int argc, char **argv) {
    if (argc < 3)
        return -1;
    char *m1 = argv[1], *m2 = argv[2];

    char *ret = mul(m1, m2);
    printf("%s\n", ret);
    free(ret);

    return 0;
}
