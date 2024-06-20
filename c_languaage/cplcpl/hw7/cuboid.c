//
// Created by 23125 on 2023/11/21.
//
#include <stdio.h>

#define LEN 100

void paintboard(char board[][LEN], int a, int b, int c, int y) {//1,1
    if (b == 0) {
        for (int i = y; i <= y + c * 2 + 1; ++i) {
            for (int j = 1; j <= a * 2 + 1; ++j) {
                if (i % 2 == 0 && j % 2 == 0) {
                    board[i][j] = ' ';
                }
                if (i % 2 == 1 && j % 2 == 1) {
                    board[i][j] = '+';
                }
                if (i % 2 == 1 && j % 2 == 0) {
                    board[i][j] = '-';
                }
                if (i % 2 == 0 && j % 2 == 1) {
                    board[i][j] = '|';
                }
            }
        }
        return;
    }
    for (int i = 2 * b + 1; i <= 2 * b + 2 * a + 1; ++i) {
        if (i % 2 == 1) {
            board[y][i] = '+';
        } else {
            board[y][i] = '-';
        }
    }
    for (int i = 2 * b; i <= 2 * b + 2 * a; ++i) {
        if (i % 2 == 0) {
            board[y + 1][i] = '/';
        }
    }
    for (int i = 1; i <= 2 * c; ++i) {
        if (i % 2 == 0) {
            board[y + i][2 * b + 2 * a + 1] = '+';
            board[y + i + 1][2 * b + 2 * a] = '/';
        } else {
            board[y + i][2 * b + 2 * a + 1] = '|';
            board[y + i + 1][2 * b + 2 * a] = ' ';
        }
    }
    paintboard(board, a, b - 1, c, y + 2);


}

int main() {
    int t;
    scanf("%d", &t);
    for (int p = 0; p < t; ++p) {
        char board[LEN][LEN] = {0};
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        paintboard(board, a, b, c, 1);
        for (int i = 1; i <= 2 * c + 1 + 2 * b; ++i) {
            for (int j = 1; j <= 2 * a + 1 + 2 * b; ++j) {
                if (board[i][j] == 0) {
                    printf(" ");
                } else {
                    printf("%c", board[i][j]);

                }
            }
            printf("\n");

        }

    }

    return 0;
}