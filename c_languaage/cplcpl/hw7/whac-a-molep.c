//
// Created by 23125 on 2023/11/19.
//
#include <stdio.h>

#define LEN 100
#define kuo 10

int main() {
    int n, m, d;
    int maxvalue[LEN][LEN] = {0};
    int board[LEN][LEN] = {0};
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1 + kuo; i <= n + kuo; ++i) {
        for (int j = 1 + kuo; j <= m + kuo; ++j) {
            scanf("%d", &board[i][j]);
        }
    }
    int y = 1 + kuo;
    int x = 1 + kuo;
    maxvalue[x][y] = board[x][y];
    for (int i = 0; i <= d; ++i) {
        for (int j = 0; j <= d - i; j++) {
            if (i != 0 && j != 0) {
                maxvalue[x][y] +=
                        board[x + i][y + j] + board[x + i][y - j] + board[x - i][y + j] + board[x - i][y - j];
            } else if (i == 0 && j != 0) {
                maxvalue[x][y] += board[x][y + j] + board[x][y - j];
            } else if (i != 0 && j == 0) {
                maxvalue[x][y] += board[x + i][y] + board[x - i][y];

            }
        }
    }
    for (x = 1 + kuo; x <= n + kuo; x++) {
        for (int y = 1+kuo; y <=m+kuo ; ++y) {
            maxvalue[x][y]=maxvalue[x][y-1]+
        }


    }
    int max = maxvalue[1 + kuo][1 + kuo];
    int counttable[LEN][2] = {0};
    int count = 0;
    for (int i = 1 + kuo; i <= n + kuo; ++i) {
        for (int j = 1 + kuo; j <= m + kuo; ++j) {
            if (max < maxvalue[i][j]) {
                max = maxvalue[i][j];
            }
        }
    }
    for (int i = 1 + kuo; i <= n + kuo; ++i) {
        for (int j = 1 + kuo; j <= m + kuo; ++j) {
            if (max == maxvalue[i][j]) {
                counttable[count][0] = i - kuo;
                counttable[count][1] = j - kuo;
                count++;
            }
        }
    }
    printf("%d %d\n", max, count);
    for (int i = 0; i < count; ++i) {
        printf("%d %d", counttable[i][0], counttable[i][1]);
    }


    return 0;
}