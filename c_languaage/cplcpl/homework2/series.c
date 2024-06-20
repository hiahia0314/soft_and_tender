//
// Created by 23125 on 2023/10/9.
//
#include <stdio.h>
#include <math.h>

int main() {

    int n;
    double t = 0;
    double x;
    scanf("%lf %d", &x, &n);
    for (int i = 0; i < n + 1; i++)
        t = t + (pow(-1, i) * pow(x, 2 * i + 1)) / (2 * i + 1);
    printf("%.10f", 4 * t);

    return 0;
}