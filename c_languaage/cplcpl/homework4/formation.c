//
// Created by 23125 on 2023/10/21.
//
#include <stdio.h>

int main() {
    int form[100][100] = {0};
    char str[100];
    int n = 0;
    int m = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        form[0][i + 1] = str[i] - '0';
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            if (((form[i - 1][j - 1] == 1) && (form[i - 1][j] == 0) && (form[i - 1][j + 1] == 0)) ||
                ((form[i - 1][j - 1] == 0) && (form[i - 1][j] == 0) && (form[i - 1][j + 1] == 0)) ||
                ((form[i - 1][j - 1] == 1) && (form[i - 1][j] == 1) && (form[i - 1][j + 1] == 1))) {
                form[i][j] = 0;
            } else {
                form[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            if (form[i][j] == 1) {
                printf("1");
            } else {
                printf("0");
            }

        }
        printf("\n");
    }
    return 0;
}
