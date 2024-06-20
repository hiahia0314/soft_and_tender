//
// Created by 23125 on 2023/11/11.
//
#include <stdio.h>

#define LEN 10000

int Max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    int zu[LEN] = {0};
    int fp[LEN] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &zu[i]);
    }
    fp[0] = zu[0];
    int max = zu[0];
    for (int i = 1; i < n; ++i) {
        fp[i] = Max(fp[i - 1] + zu[i], zu[i]);
        max = max > fp[i] ? max : fp[i];
    }

    printf("%d", max);
    return 0;
}