//
// Created by 23125 on 2023/10/14.
//
#include <stdio.h>

int main() {
    int n;
    int cishu[2000] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((j % i) == 0) {
                cishu[j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cishu[i] % 2 != 0) {
            printf("%d  ", i);
        }
    }
    return 0;
}
