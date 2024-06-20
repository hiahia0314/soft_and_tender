//
// Created by 23125 on 2023/10/9.
//
#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int chen = 1;
    int jia = 0;
    for (int i = 1; i < n + 1; i++) {
        chen = (i % 10007) * chen;
        chen = chen % 10007;
        jia = jia + chen;
    }
    jia = jia % 10007;

    printf("%d", jia);
    return 0;
}