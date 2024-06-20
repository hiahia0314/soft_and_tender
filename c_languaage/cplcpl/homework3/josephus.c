//
// Created by 23125 on 2023/10/14.
//
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int zu[10000] = {0};
    int next[10000];
    for (int i = 1; i < n; i++) {
        next[i] = i + 1;
        next[n] = 1;
    }
    int yi = 1;
    for (int p = 0; p < n - 1; p++) {
        for (int j = 1; j < k; j++) {
            yi = next[yi];

            if (zu[yi] == 1) {
                j--;
            }

        }
        zu[yi] = 1;
        while (zu[next[yi]] == 1) {
            yi = next[yi];
        }
        yi = next[yi];
    }
    for (int i = 1; i < 1 + n; i++) {
        if (zu[i] == 0) {
            printf("%d", i);
        }
    }
    return 0;
}