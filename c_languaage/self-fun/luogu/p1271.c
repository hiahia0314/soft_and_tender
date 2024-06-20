//
// Created by 23125 on 2023/11/30.
//
#include <stdio.h>

#define LEN 1000

int main() {
    int n, m;
    int tong[LEN] = {0};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int p;
        scanf("%d", &p);
        tong[p]++;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= tong[i]; ++j) {
            printf("%d ", i);
        }
    }


    return 0;
}