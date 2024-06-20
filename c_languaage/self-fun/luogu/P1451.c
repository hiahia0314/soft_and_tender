//
// Created by 23125 on 2023/11/30.
//
#include <stdio.h>

#define LEN 100
int n, m;

int board[LEN][LEN] = {0};
int count = 0;

void seach(int x, int y) {
    if (x > n || y > m || x < 1 || y < 1 || board[x][y] == 0) {
        return;
    }
    board[x][y] = 0;
    int wert[4][2] = {1, 0,
                      0, 1,
                      -1, 0,
                      0, -1};
    for (int k = 0; k < 4; ++k) {
        int newx = x + wert[k][0];
        int newy = y + wert[k][1];
        seach(newx, newy);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%1d", &board[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (board[i][j] != 0) {
                count++;
                seach(i, j);
            }
        }
    }
    printf("%d", count);

    return 0;
}
