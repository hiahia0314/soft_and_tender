//
// Created by 23125 on 2023/11/7.
//
#include <stdio.h>

int Max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t, m;
    scanf("%d%d", &t, &m);
    int daxiao[1000] = {0};
    int jiazhi[1000] = {0};
    int dp[1000] = {0};
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &daxiao[i], &jiazhi[i]);
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = t; j >= daxiao[i]; --j) {
            dp[j] = Max(dp[j], dp[j - daxiao[i]] + jiazhi[i]);
        }
    }
    printf("%d", dp[t]);
    return 0;
}