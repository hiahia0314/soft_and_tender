//
// Created by 23125 on 2023/10/8.
//
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int numbers[100000] = {0};
    for (int i = 0; 2 * n - 1 - i > 0; i++) {
        scanf("%d", &numbers[i]);
    }

    int b[100001] = {0};
    for (int i = 0; 2 * n - 1 - i > 0; i++) {
        b[numbers[i]]++;
    }
    for (int i = 0; i < 100001; i++) {
        if (b[i] == 1) {
            printf("%d", i);
        }
    }


    return 0;
}
