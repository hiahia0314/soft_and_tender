//
// Created by 23125 on 2023/11/17.
//
#include <stdio.h>

int pay = 0;

#define LEN 100

int Find(int value[], int max[], int n, int l) {
    int index = 1;
    for (int i = 1; i <= n; ++i) {
        if (value[index] <= value[i]) {
            index = i;
        }
    }
    while (max[index] > 0) {
        if (l == 0) {
            return pay;
        }
        l--;
        max[index]--;
        pay += value[index];
    }
    value[index] = -1;
    return Find(value, max, n, l);
}

int main() {
    int n, l;
    scanf("%d%d", &n, &l);
    int value[LEN] = {0};
    int max[LEN] = {0};
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &value[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &max[i]);
    }
    printf("%d", Find(value, max, n, l));


}
