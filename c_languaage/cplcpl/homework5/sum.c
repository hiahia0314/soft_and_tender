//
// Created by 23125 on 2023/10/27.
//

#include <stdio.h>
#include <math.h>

int fNT(int n, int t);

int main() {
    int n = 0;
    int t = 0;
    int sum = 0;
    scanf("%d%d", &n, &t);
    for (int j = 1; j <= n; j++) {
        sum += fNT(j, t);
    }
    printf("%d", sum);
    return 0;
}

int fNT(int n, int t) {
    int sumt = 0;
    for (int i = 0; i < n; i++) {
        sumt += t * pow(10, i);
    }
    return sumt;
}
