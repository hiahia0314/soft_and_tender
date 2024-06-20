//
// Created by 23125 on 2023/11/18.
//
#include <stdio.h>

int aha(int va, int vb, int vc, int a, int b, int c, int a0, int b0, int c0, int k) {
    if (k == -1) {
        return 0;
    }
    if (a == a0 && b == b0 && c == c0) {
        return 1;
    }
    int a1 = a + b > va ? va : a + b;
    int a2 = a + c > va ? va : a + c;
    int b1 = a + b > vb ? vb : a + b;
    int b2 = c + b > vb ? vb : c + b;
    int c1 = a + c > vc ? vc : a + c;
    int c2 = c + b > vc ? vc : c + b;
    return (aha(va, vb, vc, a1, 0, c, a0, b0, c0, k - 1)
            || aha(va, vb, vc, a2, b, 0, a0, b0, c0, k - 1)
            || aha(va, vb, vc, 0, b1, c, a0, b0, c0, k - 1)
            || aha(va, vb, vc, a, b2, 0, a0, b0, c0, k - 1)
            || aha(va, vb, vc, 0, b, c1, a0, b0, c0, k - 1)
            || aha(va, vb, vc, a, 0, c2, a0, b0, c0, k - 1)
    );


}

int main() {
    int k, va, vb, vc, a, b, c, a0, b0, c0;
    scanf("%d%d%d%d%d%d%d%d%d%d", &k, &va, &vb, &vc, &a, &b, &c, &a0, &b0, &c0);
    if (aha(va, vb, vc, a, b, c, a0, b0, c0, k) == 1) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}