//
// Created by 23125 on 2023/12/28.
//
#include <stdio.h>
#include <stdlib.h>

int cmp(void const *l, void const *r) {
    int *le = (int *) l;
    int *ri = (int *) r;
    return (*le - *ri) - (*ri - *le);

}

#define LEN 100

int main() {
    int n;
    int zu[LEN] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &zu[i]);
    }
    qsort(zu, n, sizeof(zu[0]), cmp);
    for (int i = 0; i < n; ++i) {
        printf("%d ", zu[i]);
    }

    return 0;
}