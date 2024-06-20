//
// Created by 23125 on 2023/10/22.
//
#include <stdio.h>

int main() {
    int n, m, x, y; //x时行 y是列
    char board[55][55] = {0};
    char bool[55][55] = {0};
    int length = 0;
    char pp;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    scanf("%c", &pp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%c", &board[i][j]);
        }
        getchar();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == '#') {
                length++;
            }
        }
    }
    printf("%d\n", length);
    bool[x][y] = 1;
    int vectors[4][2] = {{0,  1},
                         {0,  -1},
                         {1,  0},
                         {-1, 0}};
    for (int i = 0; i < length; i++) {
        printf("%d %d\n", x, y);
        bool[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            int newx = x + vectors[k][0];
            int newy = y + vectors[k][1];
            if (board[newx][newy] == '#' && bool[newx][newy] == 0) {
                x = newx;
                y = newy;
                break;
            }
        }

    }
    return 0;
}