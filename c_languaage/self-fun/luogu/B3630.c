//
// Created by 23125 on 2023/11/14.
//
#include <stdio.h>

#define LEN 100

void PR(int after[], int n, int first) {
    if (n == 1) {
        return;
    }

    printf(" %d", after[first]);
    PR(after, n - 1, after[first]);
}

int main() {
    int n;
    scanf("%d", &n);
    int after[LEN] = {0};
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &after[i]);
    }
    int first = 0;
    scanf("%d", &first);
    printf("%d", first);
    PR(after, n, first);

    return 0;
}
