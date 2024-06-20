//
// Created by 23125 on 2023/12/15.
//
#include <stdio.h>
#include <stdlib.h>

#define LEN 100

int cmp(const void *left, const void *right) {
    int *pl = left;
    int *pr = right;
    return (*pl > *pr) - (*pr > *pl);

}

int main() {
    int A[LEN] = {0};
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    while (t--) {
        int a;
        scanf("%d", &a);
        int *ans = bsearch(&a, A, n,
                           sizeof(A[0]), cmp);
        if (ans != NULL) {
            printf("%d\n", ans - A);
        } else {
            printf("-1\n");
        }

    }


    return 0;
}