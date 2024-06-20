//
// Created by 23125 on 2023/10/28.
//
#include <stdio.h>
#include <math.h>

int IsPrime(int x);

int main() {
    int n = 0;
    int count = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (i < 10) {
            if (IsPrime(i)) {
                count++;
            }
        } else if (i > 10 && i < 100) {
            if (IsPrime(i) && IsPrime(i / 10 + i % 10 * 10)) {
                count++;
            }
        } else if (i > 100 && i < 1000) {
            if (IsPrime(i) && IsPrime(i / 100 + i % 10 * 100 + i / 10 % 10 * 10)) {
                count++;
            }
        }
    }
    printf("%d", count);

    return 0;
}

int IsPrime(int x) {
    int flag = 1; // 1 表示该数是素数
    for (int i = 2; i <= sqrt(x + 0.5); i++) {
        if (x % i == 0) {
            flag = 0;
        }
    }
    return flag;
}