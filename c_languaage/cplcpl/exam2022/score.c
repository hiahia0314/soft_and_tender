//
// Created by 23125 on 2023/12/28.
//
#include <stdio.h>

int main() {
    int board[3][3];
    int a, b, c;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &board[i][j]);
        }
    }
    scanf("%d%d%d", &a, &b, &c);


    int max = 0;
    int ai, aj, bi, bj, ci, cj;
    for (ai = 0; ai < 3; ++ai) {
        for (aj = 0; aj < 3; ++aj) {
            for (bi = 0; bi < 3; ++bi) {
                for (bj = 0; bj < 3; ++bj) {
                    if (ai == bi && aj == bj) {
                        continue;
                    }
                    for (ci = 0; ci < 3; ++ci) {
                        for (cj = 0; cj < 3; ++cj) {
                            if (ai == bi && bi == ci) {
                                continue;
                            }
                            if (aj == bj && bj == cj) {
                                continue;
                            }
                            if (ai + bi + ci == 3 && aj + cj + bj == 3) {
                                continue;
                            }
                            if (ai == ci && aj == cj) {
                                continue;
                            }
                            if (bi == ci && bj == cj) {
                                continue;
                            }

                            int m = board[ai][aj] * a + board[bi][bj] * b + board[ci][cj] * c;
                            max = m > max ? m : max;
                        }
                    }
                }
            }
        }
    }
    printf("%d", max);

    return 0;
}