//
// Created by 23125 on 2023/11/7.
//
#include <stdio.h>

int feibo(int n) {

    if (n >= 2) {
        return feibo(n - 1) + feibo(n - 2);

    } else if (n == 1) {
        return 1;
    } else if (n == 0) {
        return 1;
    }
}

int main() {
    int n = 0;
    printf("%d", feibo(40));
    return 0;
}

