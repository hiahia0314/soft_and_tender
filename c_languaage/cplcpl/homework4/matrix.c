//
// Created by 23125 on 2023/10/21.
//
#include <stdio.h>

int main() {
    int m, n, p;
    int c[100][100] = {0};
    int a[100][100] = {0};
    int b[100][100] = {0};
    scanf("%d", &m);
    scanf("%d", &n);
    scanf("%d", &p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {//hang
        for (int j = 0; j < p; j++) {//lie
            for (int q = 0; q < n; q++) {
                c[i][j] += a[i][q] * b[q][j];
            }
        }

    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}