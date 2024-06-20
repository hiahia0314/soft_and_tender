//
// Created by 23125 on 2023/11/15.
//
#include <stdio.h>

int count = 0;

double f(double a, double b, double c, double d, double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

void check(double a, double b, double c, double d, double x, double y) {
    if (count == 3) {
        return;
    }
    if (f(a, b, c, d, x) * f(a, b, c, d, y) > 0) {
        return;
    }
    if (f(a, b, c, d, x) == 0 || y - x <= 0.001) {//保证精度
        printf("%.2f ", x);
        count++;
        return;
    } else if (f(a, b, c, d, x) * f(a, b, c, d, y) < 0) {
        if (f(a, b, c, d, (x + y) / 2) * f(a, b, c, d, x) < 0) {
            return check(a, b, c, d, x, (x + y) / 2);
        } else {
            return check(a, b, c, d, (x + y) / 2, y);
        }
    }
}

int main() {
    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    for (double i = -100; i <= 100; ++i) {
        if (count == 3) {
            break;
        }
        check(a, b, c, d, i, i + 1);

    }
    return 0;
}