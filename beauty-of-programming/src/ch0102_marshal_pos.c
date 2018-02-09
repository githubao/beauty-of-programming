// Created by BaoQiang at 2017/4/27 20:48

/*
 * 象棋将帅的可能排序的组合
 * */

#include <stdio.h>

#define HALF_BITS_LENGTH 4
#define FULLMASK 255
#define LMASK (FULLMASK << HALF_BITS_LENGTH)
#define RMASK (FULLMASK >> HALF_BITS_LENGTH)
#define RSET(b, n) (b = ((LMASK & b) | (n)))
#define LSET(b, n) (b = ((RMASK & b) | ((n) << HALF_BITS_LENGTH)))
#define RGET(B) (RMASK & b)
#define LGET(B) ((LMASK & b) >> HALF_BITS_LENGTH)
#define GRIDW 3

int main1() {
    unsigned char b;
    for (LSET(b, 1); LGET(b) <= GRIDW * GRIDW; LSET(b, (LGET(b) + 1))) {
        for (RSET(b, 1); RGET(b) <= GRIDW * GRIDW; RSET(b, (RGET(b) + 1))) {
            if (LGET(b) % GRIDW != RGET(b) % GRIDW) {
                printf("A = %d, b=%d\n", LGET(b), RGET(b));
            }
        }
    }
    return 0;
}

int main2() {
    int i = 81;
    while (i--) {
        if (i / 9 % 3 == i % 9 % 3) {
            continue;
        }
        printf("A = %d, b=%d\n", i / 9 + 1, i % 9 + 1);
    }
};

struct {
    unsigned char a:4;
    unsigned char b:4;
} i;

int main() {
    for (i.a = 1; i.a <= 9; i.a++) {
        for (i.b = 1; i.b <= 9; i.b++) {
            if (i.a % 3 != i.b % 3) {
                printf("A = %d, b=%d\n", i.a, i.b);
            }

        }
    }
}
