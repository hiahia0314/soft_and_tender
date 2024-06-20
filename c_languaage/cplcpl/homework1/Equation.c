//
// Created by 23125 on 2023/9/23.
//
#include <stdio.h>
#include <math.h>

int main() {
    int q, p;
    double x, d;
    scanf("%d %d", &p, &q);
    d = sqrt((q * 1.0 / 2) * (q * 1.0 / 2) + (p * 1.0 / 3) * (p * 1.0 / 3) * (p * 1.0 / 3));
    x = cbrt(-(1.0 * q / 2) + d) + cbrt(-(1.0 * q / 2) - d);
    printf("%.3f", x);
    return 0;
}
