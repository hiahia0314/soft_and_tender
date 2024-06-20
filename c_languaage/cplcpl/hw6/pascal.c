//
// Created by 23125 on 2023/11/12.
//
#include <stdio.h>

int pailie(int x, int y) {
    if (y == 0 || x == y) {
        return 1;
    }
    return pailie(x - 1, y - 1) + pailie(x - 1, y);
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int m = pailie(a - 1, b - 1);
    printf("%d", m);


    return 0;
}
