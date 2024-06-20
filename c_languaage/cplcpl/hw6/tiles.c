#include <stdio.h>

int countWays(int n) {
    int dp[100] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", countWays(n));
    return 0;
}
