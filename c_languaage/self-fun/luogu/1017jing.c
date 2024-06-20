//
// Created by 23125 on 2023/11/6.
//
#include <stdio.h>


int mod(int a, int b);

int main() {
    int n, r;
    int count = 0;
    int wei[100000] = {0};
    scanf("%d%d", &n, &r);
    int ann = n;
    for (int i = 0; n != 0; ++i) {
        wei[i] = mod(n, r);
        if (n % r < 0) {
            n = n / r + 1;
        } else {
            n /= r;
        }
        count++;
    }
    printf("%d=", ann);
    for (int i = count - 1; i >= 0; i--) {
        if (wei[i] >= 10) {
            printf("%c", wei[i] + 55);
        } else {
            printf("%d", wei[i]);
        }
    }
    printf("(base%d)", r);

    return 0;
}

int mod(int a, int b) {
    if (a % b < 0) {
        return a - (a / b + 1) * b; //or return a%b-b; (自己算算就行
    } else {         //解决余数为负数...
        return a % b;
    }
}