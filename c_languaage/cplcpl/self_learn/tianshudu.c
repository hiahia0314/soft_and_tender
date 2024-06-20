//
// Created by 23125 on 2023/11/22.
//
#include <stdio.h>

#define N 3
#define M 9

void Solve(int r, int c, int board[][M]); //r行，c列
int Check(int r, int c, int num, int board[][M]);

int checkbox(int r, int c, int num, int board[][M]);


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int board[M][M] = {0};
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                scanf("%1d", &board[i][j]);
            }
        }
        Solve(0, 0, board);
    }


    return 0;
}


void Solve(int r, int c, int board[][M]) {
    if (r == M) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                printf("%d", board[i][j]);
            }
            printf("\n");
        }
        return;
    }

    if (c == M) {
        Solve(r + 1, 0, board);
        return;
    }
    if (board[r][c] == 0) {
        for (int i = 1; i <= 9; ++i) {
            if (Check(r, c, i, board) == 1 && checkbox(r, c, i, board) == 1) {
                board[r][c] = i;
                Solve(r, c + 1, board);
                board[r][c] = 0;
            }
        }
    } else {
        Solve(r, c + 1, board);
    }
}

int checkbox(int r, int c, int num, int board[][M]) {
    int newr = r / 3 * 3;
    int newc = c / 3 * 3;
    for (int i = newr; i < newr + 3; ++i) {
        for (int j = newc; j < newc + 3; ++j) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;

}

int Check(int r, int c, int num, int board[][M]) {
    for (int i = 0; i < M; ++i) {
        if (board[r][i] == num || board[i][c] == num) {
            return 0;
        }
    }
    return 1;
}

