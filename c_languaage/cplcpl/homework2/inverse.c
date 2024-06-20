//
// Created by 23125 on 2023/10/9.
//
#include <stdio.h>

int main() {
    int n, k;
    char kong;
    int zu[100000] = {0};
    scanf("%d", &n);
    scanf("%c", &kong);

    for (int i = 0; i < n; i++) {
        scanf("%c", &zu[i]);
    }


    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
        printf("%c", zu[k - 1 - j]);
    }
    for (int j = 0; j < n - k; j++) {
        printf("%c", zu[n - 1 - j]);
    }

    return 0;
}