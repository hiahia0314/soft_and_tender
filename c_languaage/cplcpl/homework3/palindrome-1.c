//
// Created by 23125 on 2023/10/14.
//
#include <stdio.h>

int main() {
    int n;
    char zu[10000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &zu[i]);
    }
    for (int j = 0; j < n; j++) {
        if (zu[j] == 63) {
            zu[j] = zu[n - 1 - j];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%c", zu[i]);
    }
    //printf("%c %c", zu[1], zu[2]);
    return 0;
}