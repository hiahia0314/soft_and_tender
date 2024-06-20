//
// Created by 23125 on 2023/11/13.
//
#include <stdio.h>
#include <math.h>

#define LEN 50

double F(int f[], int n, double a, double b, int p) {
    double ans1, ans2, ans3;
    ans1 = 0;
    ans2 = 0;
    ans3 = 0;
    for (int i = 0; i <= n; i++) {
        ans1 = ans1 + f[i] * pow((a + b) / 2.0, i);
    }
    for (int i = 0; i <= n; i++) {
        ans2 = ans2 + f[i] * pow((a) / 1.0, i);
    }
    for (int i = 0; i <= n; i++) {
        ans3 = ans3 + f[i] * pow((b) / 1.0, i);
    }
    return (4 * pow(ans1, p) + pow(ans2, p) + pow(ans3, p)) / 6.0 * (b - a);
}

double ji(int f[], int n, double a, double b, int p, double e) {
    double mid = (a + b) / 2.0;
    double SL = F(f, n, a, mid, p);
    double SR = F(f, n, mid, b, p);
    double S = F(f, n, a, b, p);
    if (fabs(SL + SR - S) <= e) {
        return SL + SR + (SL + SR - S) / 15.0;
    } else {
        e /= 2;
        return ji(f, n, a, mid, p, e) + ji(f, n, mid, b, p, e);
    }
}

int main() {
    int n, p;
    double a, b;
    double e = 0.00015;
    int f[LEN] = {0};
    scanf("%d%d", &n, &p);
    for (int i = 0; i <= n; ++i) {
        scanf("%d", &f[i]);
    }
    scanf("%lf%lf", &a, &b);
    printf("%f", ji(f, n, a, b, p, e));


}