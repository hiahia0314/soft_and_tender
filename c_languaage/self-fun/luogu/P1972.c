//
// Created by 23125 on 2023/12/6.
//
#include <stdio.h>

#define LEN 1009

int distance(int x1, int x2, int y1, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int t;
    int location[LEN][2] = {0};
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d%d", &location[i][0], &location[i][1]);
    }
    int min = (1 << 30);
    for (int i = 0; i < t; ++i) {
        int max = 0;
        for (int j = 0; j < t; ++j) {
            if (j == i) {
                continue;
            }
            int dis = distance(location[i][0], location[j][0], location[i][1], location[j][1]);
            max = max > dis ? max : dis;
        }
        min = min > max ? max : min;
    }
    printf("%.4lf", 3.1415926535 * (double) min);
    return 0;
}