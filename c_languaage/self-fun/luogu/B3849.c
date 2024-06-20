//
// Created by 23125 on 2023/11/7.
//
#include <stdio.h>

#define LEN 100

int main() {
    int n, r;
    int wei = 0;
    int answer[LEN] = {0};
    scanf("%d%d", &n, &r);
    int i = 0;
    while (n != 0) {
        answer[i] = n % r;
        n /= r;
        i++;
    }
    for (int j = i - 1; j >= 0; --j) {
        if (answer[j] >= 10) {
            printf("%c", answer[j] + 55);
        } else {
            printf("%d", answer[j]);

        }
    }

    return 0;
}