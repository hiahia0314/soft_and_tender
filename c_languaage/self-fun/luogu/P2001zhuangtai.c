//
// Created by 23125 on 2023/11/7.
//
#include <stdio.h>

int Max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int v, n;
    int tiji[30000] = {0};
    int dp[30000] = {0};
    scanf("%d%d", &v, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tiji[i]);
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = v; i >= tiji[j]; --i) {
            dp[i] = Max(dp[i - tiji[j]] + tiji[j], dp[i]);
        }
    }
    printf("%d", v - dp[v]);
    return 0;
}

