//
// Created by 23125 on 2023/12/16.
//
#include <stdio.h>
#include <stdlib.h>

#define LEN 10

int comp(const void *left, const void *right) {
    int *l = left;
    int *r = right;
    return (*l > *r) - (*r - *l);
}

int main() {
    int n;
    int sum_attack[LEN] = {0};
    int sum_defence[LEN] = {0};
    int sum_organize[LEN] = {0};

    char country[LEN][20] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", country[i]);
        for (int j = 0; j < 11; ++j) {
            int attack, defence, organize;
            char name[20] = {0};
            scanf("%s", name);
            scanf("%d%d%d", &attack, &defence, &organize);
            sum_attack[i] += attack;
            sum_defence[i] += defence;
            sum_organize[i] += organize;
        }
//        qsort(sum_attack,i,
//              sizeof(sum_attack[0]),comp);

    }
    for (int i = 0; i < n; ++i) {
        int t = -1;
        int max = 0;
        for (int j = 0; j < n; ++j) {
            if (max < sum_attack[j]) {
                max = sum_attack[j];
                t = j;
            }
        }
        sum_attack[t] = 0;
        printf("%s ", country[t]);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        int t = -1;
        int max = 0;
        for (int j = 0; j < n; ++j) {
            if (max < sum_defence[j]) {
                max = sum_defence[j];
                t = j;
            }
        }
        sum_defence[t] = 0;
        printf("%s ", country[t]);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        int t = -1;
        int max = 0;
        for (int j = 0; j < n; ++j) {
            if (max < sum_organize[j]) {
                max = sum_organize[j];
                t = j;
            }
        }
        sum_organize[t] = 0;
        printf("%s ", country[t]);
    }


    return 0;
}
