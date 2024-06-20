//
// Created by 23125 on 2023/11/9.
//
#include <stdio.h>

#define LEN 100000

int Max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, m;
    int money[LEN] = {0};
    int value[LEN] = {0};
    int fp[LEN] = {0};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &money[i], &value[i]);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = n; j >= money[i]; --j) {
            fp[j] = Max(fp[j], fp[j - money[i]] + money[i] * value[i]);
        }
    }
    printf("%d", fp[1000]);
    return 0;
}