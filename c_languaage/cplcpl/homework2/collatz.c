//
// Created by 23125 on 2023/10/9.
//
#include <stdio.h>

int main() {
    int x, j, max;
    scanf("%d", &x);
    max = x;
    for (j = 0; x != 1; j++) {
        if (x % 2 == 0) {
            x = x / 2;
        } else {
            x = 1 + 3 * x;
        }
        if (max < x) {
            max = x;
        }
    }
    printf("%d %d", j, max);
    return 0;
}