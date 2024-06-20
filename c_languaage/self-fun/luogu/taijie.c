//
// Created by 23125 on 2023/11/16.
//
#include <stdio.h>

#define LEN 100
#define MOD 100003

int main() {
    int n, k;
    int fp[LEN] = {1};
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - j >= 0) {
                fp[i] += fp[i - j];
            } else {
                break;
            }
        }
    }
    printf("%d", fp[n]);


    return 0;
}