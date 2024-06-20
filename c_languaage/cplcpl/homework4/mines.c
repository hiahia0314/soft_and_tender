//
// Created by 23125 on 2023/10/22.
//
#include <stdio.h>

int main() {
    char board[20][20] = {'o'};
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {      //下标1到n
            scanf(" %c", &board[i][j]);
        }
    }
    int vectors[8][2] = {{0, 1},
                         {0, -1},
                         {1, 0},
                         {-1, 0},
                         {1, -1},
                         {-1, 1},
                         {1, 1},
                         {-1, -1}};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int count = 0;
            for (int k = 0; k < 8; ++k) {
                int newI = i + vectors[k][0];
                int newJ = j + vectors[k][1];
                if (board[newI][newJ] == '*') {
                    count++;
                }
            }
            if (board[i][j] != '*') {
                board[i][j] = count;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] != '*') {
                printf("%d", board[i][j]);
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}