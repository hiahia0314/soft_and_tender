//
// Created by 23125 on 2023/10/10.
//
#include <stdio.h>

int main() {
    int n;
    int stand = 0;
    int tuo = 0;
    int zu[10000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &zu[i]);
    }
    for (int j = 0; j < n + 1; j++) {
        stand = stand + zu[j];
        zu[j] = j - stand + zu[j];
    }                                     //这两个for循环可以合并
    for (int i = 0; i < n + 1; i++) {
        if (tuo < zu[i]) {
            tuo = zu[i];
        }
    }
    printf("%d", tuo);
    return 0;
}