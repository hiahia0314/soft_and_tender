//
// Created by 23125 on 2023/11/9.
//
#include <stdio.h>

#define LEN 150

int Min(int a, int b) {
    return a > b ? b : a;
}

int main() {
    int n, m;
    int map[LEN][LEN] = {0};
    int dp[LEN][LEN] = {0};
    scanf("%d%d", &n, &m);//n是步数
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j != 1)dp[j][i] = Min(dp[j][i - 1] + map[j][i], dp[j - 1][i - 1] + map[j][i]);
            if (j == 1)dp[j][i] = Min(dp[m][i - 1] + map[j][i], dp[1][i - 1] + map[j][i]);
        }
    }
    int ans = dp[1][n];
    for (int i = 1; i <= m; ++i) {
        ans = Min(dp[i][n], ans);
    }
    printf("%d", ans);
    return 0;
}