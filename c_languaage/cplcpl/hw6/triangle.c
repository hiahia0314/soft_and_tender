#include <stdio.h>
#include <math.h>

#define LEN 1000

void paint(char board[][LEN], int n, int x, int y) {
    if (n == 1) {
        board[x][y] = '/';
        board[x - 1][y + 1] = '/';
        board[x + 1][y] = '\\';
        board[x + 2][y + 1] = '\\';
        board[x][y + 1] = '_';
        board[x + 1][y + 1] = '_';
    } else {
        paint(board, n - 1, x, y);
        paint(board, n - 1, x + pow(2, n - 1), y + pow(2, n - 1));
        paint(board, n - 1, x - pow(2, n - 1), y + pow(2, n - 1));
    }

}

int main() {
    char board[LEN][LEN];
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j < LEN; ++j) {
            board[i][j] = '.';
        }
    }
    int n;
    scanf("%d", &n);
    paint(board, n, pow(2, n), 1);
    for (int i = 1; i <= pow(2, n); ++i) {
        for (int j = 1; j <= pow(2, n + 1); ++j) {
            if (board[j][i] != '.') {
                printf("%c", board[j][i]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}