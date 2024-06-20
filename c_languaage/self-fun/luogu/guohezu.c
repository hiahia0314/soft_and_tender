//
// Created by 23125 on 2023/11/8.
//
#include <stdio.h>

#define LEN 50

int main() {
    int board[LEN][LEN] = {0};
    int ma[LEN][LEN] = {0};
    long long xb, yb, xma, yma;
    scanf("%d%d%d%d", &xb, &yb, &xma, &yma);
    xb += 2;
    xma += 2;
    yb += 2;
    yma += 2;

    long long dp[LEN][LEN] = {0};
    dp[2][2] = 1;

    ma[yma][xma] = -1;
    ma[yma + 2][xma + 1] = -1;
    ma[yma - 2][xma + 1] = -1;
    ma[yma + 2][xma - 1] = -1;
    ma[yma - 2][xma - 1] = -1;
    ma[yma + 1][xma + 2] = -1;
    ma[yma + 1][xma - 2] = -1;
    ma[yma - 1][xma + 2] = -1;
    ma[yma - 1][xma - 2] = -1;
    for (int i = 2; i <= yb; ++i) {
        for (int j = 2; j <= xb; ++j) {
            if (ma[i][j] == -1 || (i == 2 && j == 2)) {
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    printf("%lld", dp[yb][xb]);

    return 0;
}