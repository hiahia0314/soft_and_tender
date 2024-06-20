//
// Created by 23125 on 2023/11/11.
//
#include <stdio.h>

int main() {
    int board[100][100] = {0};
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int j = x1; j <= x2; ++j) {
            for (int k = y1; k <= y2; ++k) {
                board[j][k]++;
            }

        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d", board[i][j]);

        }
        printf("\n");

    }

}