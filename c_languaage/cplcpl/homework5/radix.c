//
// Created by 23125 on 2023/10/28.
//
#include <stdio.h>

int IRadix(int t, int i);

int CatchMax(int t);

int main() {
    int p, q, r, pmax, qmax, rmax = 0;
    scanf("%d%d%d", &p, &q, &r);
    pmax = CatchMax(p);
    qmax = CatchMax(q);
    rmax = CatchMax(r);
    for (int i = 1; i <= 40; i++) {
        int a = IRadix(q, i);
        int b = IRadix(p, i);
        int c = IRadix(r, i);
        if (a * b == c) {
            if (i < 10 && i > rmax && i > pmax && i > qmax) {
                printf("%d", i);
                break;
            } else if (i >= 10) {
                printf("%d", i);
                break;
            }
        }
        if (i == 40) {
            printf("0");
        }
    }
    return 0;
}

int IRadix(int t, int i) {
    int q = 0;
    if (t >= 10) {
        q = t / 10 * i + t % 10;
    } else {
        q = t;
    }
    return q;
}

int CatchMax(int t) {
    if (t < 10) {
        return t;
    } else {
        if (t / 10 > t % 10) {
            return t / 10;
        } else {
            return t % 10;
        }
    }
}