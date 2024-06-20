//
// Created by 23125 on 2023/12/14.
//
#include <stdio.h>
#include <math.h>

int main() {
    int field[21][21] = {0};
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &field[i][j]);
        }
    }
    int sum = 0;
    int pre_x = 0, pre_y = 0;
    int max_x, max_y;
    while (t >= 0) {
        int max = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (max < field[i][j]) {
                    max = field[i][j];
                    max_x = i;
                    max_y = j;
                }
            }
        }
        t--;
        if (pre_x == 0) {
            t -= max_x;
        } else {
            t -= abs(max_x - pre_x) + abs(max_y - pre_y);
        }
        if (t < 0 || t - max_x < 0) {
            break;
        }
        sum += field[max_x][max_y];
        field[max_x][max_y] = 0;

        pre_x = max_x;
        pre_y = max_y;
    }
    printf("%d", sum);

    return 0;
}