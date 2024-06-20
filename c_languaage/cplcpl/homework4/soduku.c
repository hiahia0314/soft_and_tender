//
// Created by 23125 on 2023/10/21.
//
#include <stdio.h>

int main() {
    int shudu[9][9] = {0};
    int answer = 1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &shudu[i][j]);
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (shudu[i][j] > 9) {
                answer = -1;
            }

        }
    }
    for (int i = 0; i < 9; i++) {
        int jian[10] = {0};
        for (int j = 0; j < 9; j++) {
            jian[shudu[i][j]]++;
            if (jian[shudu[i][j]] >= 2) {
                answer = -1;
                break;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        int jian[10] = {0};
        for (int j = 0; j < 9; j++) {
            jian[shudu[j][i]]++;
            if (jian[shudu[j][i]] >= 2) {
                answer = -1;
                break;
            }
        }

    }
    for (int i = 0; i < 9; i++) {
        int jian[10] = {0};
        for (int j = 0; j < 9; j++) {
            int hang = i / 3 * 3 + j / 3;
            int lie = i % 3 * 3 + j % 3;
            jian[shudu[hang][lie]]++;
            if (jian[shudu[hang][lie]] >= 2) {
                answer = -1;
            }
        }

    }

    if (answer == 1) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}