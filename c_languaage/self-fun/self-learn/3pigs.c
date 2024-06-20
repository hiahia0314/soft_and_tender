//
// Created by 23125 on 2023/11/8.
//
#include <stdio.h>

int Win(int board[][100], int n, int a, int k);

int main() {
    int t, x;
    char answer[100] = {0};
    scanf("%d%d", &t, &x);
    for (int q = 0; q < t; q++) {
        int board[100][100] = {0};
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                board[i][j] = -1;
            }
        }
        int n;
        scanf("%d", &n);
        for (int i = 10; i < 10 + n; ++i) {
            for (int j = 10; j < 10 + n; ++j) {
                scanf("%d", &board[i][j]);
            }
        }
        if (Win(board, n, 1, x) && !Win(board, n, 2, x) && !Win(board, n, 4, x)) {
            answer[q] = '1';
        } else if (Win(board, n, 2, x) && !Win(board, n, 1, x) && !Win(board, n, 4, x)) {
            answer[q] = '2';
        } else if (Win(board, n, 4, x) && !Win(board, n, 1, x) && !Win(board, n, 2, x)) {
            answer[q] = '4';
        } else {
            answer[q] = 'd';
        }
//        printf("%d", Win(board, n, 1, x));


    }
    for (int i = 0; i < t; ++i) {
        if (answer[i] == 'd') {
            printf("draw\n");
        } else {
            printf("%c\n", answer[i]);

        }
    }
    return 0;
}

int Win(int board[][100], int n, int a, int k) {
    int flag = 1;
    for (int i = 10; i < 10 + n; ++i) {
        for (int j = 10; j < 10 + n; ++j) {
            flag = 1;
            for (int l = 0; l < k; ++l) {
                if (board[i][j + l] != a) {
                    flag = 0;
                }
            }
            if (flag == 1) {
                return 1;
            }
            flag = 1;
            for (int l = 0; l < k; ++l) {
                if (board[j + l][i] != a) {
                    flag = 0;
                }
            }
            if (flag == 1) {
                return 1;
            }
            flag = 1;
            for (int l = 0; l < k; ++l) {
                if (board[i + l][j + l] != a) {
                    flag = 0;
                }

            }
            if (flag == 1) {
                return 1;
            }
            flag = 1;
            for (int l = 0; l < k; ++l) {
                if (board[i + l][j - l] != a) {
                    flag = 0;
                }
            }
            if (flag == 1) {
                return 1;
            }
        }
    }
    return flag;
}
