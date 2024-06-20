//
// Created by 23125 on 2023/11/27.
//
#include <stdio.h>

int count;
int n, m, t, sx, sy, fx, fy;

int board[10][10];

void search(int x, int y) {
    if (x <= 0 || x > n || y <= 0 || y > m) {
        return;
    }
    if (x == fx && y == fy) {
        count++;
        return;
    }
    if (board[x][y] == -1 || board[x][y] == 1) {
        return;
    }
    board[x][y] = 1;
    search(x + 1, y);
    search(x, y + 1);
    search(x, y - 1);
    search(x - 1, y);
    board[x][y] = 0;
}

int main() {
    scanf("%d%d%d%d%d%d%d", &n, &m, &t, &sx, &sy, &fx, &fy);
    for (int i = 0; i < t; ++i) {
        int m, n;
        scanf("%d%d", &m, &n);
        board[m][n] = -1;//障碍-1；
    }
    search(sx, sy);
    if (board[fx][fy] == -1) {
        printf("0");
    } else {
        printf("%d", count);
    }


    return 0;
}
