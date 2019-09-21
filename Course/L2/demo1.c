#include <stdbool.h>
#include <stdio.h>

enum {
    opType1 = 0x1 << 0, opType2 = 0x1 << 1,
    opType3 = 0x1 << 4, opType4 = 0x1 << 5,
};

static int operate(int op, int a, int b) {
    switch (op) {
    case opType1: return a + b;
    case opType2: return a - b;
    case opType3: return a * b;
    case opType4: return (int) a / b;
    }
    return 0;
}

static char op_to_char(int op) {
    return "+-*/?"[op - 1];
}
static int op_to_prio(int op) {
    return ((int[]){opType1, opType2, opType3, opType4, -1})[op - 1];
}

static int calc(int op1, int op2, int op3) {
    op1 = op_to_prio(op1);
    op2 = op_to_prio(op2);
    op3 = op_to_prio(op3);

    bool p1 = (op1 & 0x0F) == 0;  // = 1 for * or /
    bool p2 = (op2 & 0x0F) == 0;  // else = 0
    bool p3 = (op3 & 0x0F) == 0;

    // (4 + 4 + 4 + 4) or (4 / 4 / 4 / 4)
    if ((p1 == p2) && (p2 == p3))
        return operate(op3, operate(op2, operate(op1, 4, 4), 4), 4);
    /* Write your code here */

    return 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int sol[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &sol[i]);

    bool validSolution = false;
    for (int i = 0; i < n; i++) {
        for (int op1 = 4; op1 > 0; op1--) {
            for (int op2 = 4; op2 > 0; op2--) {
                for (int op3 = 4; op3 > 0; op3--) {
                    int sol_checked = calc(op1, op2, op3);
                    if (sol_checked == sol[i]) {
                        validSolution = true;

                        char op1char = op_to_char(op1);
                        char op2char = op_to_char(op2);
                        char op3char = op_to_char(op3);

                        printf("4 %c 4 %c 4 %c 4 = %d\n", op1char, op2char,
                               op3char, sol[i]);
                        op1 = -1; op2 = -1; op3 = -1;
                        break;
                    }
                }
            }
        }
        if (!validSolution)
            printf("no solution\n");
        validSolution = false;
    }
    return 0;
}
