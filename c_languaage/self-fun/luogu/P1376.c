//
// Created by 23125 on 2023/11/30.
//
#include <stdio.h>

#define LEN 10000

int main() {
    long long sum = 0;
    int n, s;
    int require[LEN] = {0};
    int value[LEN] = {0};
    scanf("%d%d", &n, &s);
    scanf("%d%d", &value[0], &require[0]);
    sum += value[0] * require[0];
    int minvalue = value[0];
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &value[i], &require[i]);
        minvalue = minvalue + s > value[i] ? value[i] : minvalue + s;
        sum += minvalue * require[i];

    }
    printf("%lld", sum);


    return 0;
}