//
// Created by 23125 on 2023/12/23.
//
#include <stdio.h>
#include <stdlib.h>


struct pro {
    int sum, rk;
} a[110];

int cop(void const *l, void const *r) {
    struct pro *left = (struct pro *) l;
    struct pro *right = (struct pro *) r;
    if (left->sum != right->sum) {
        return (left->sum - right->sum) - (right->sum - left->sum);
    } else {
        return -(left->rk - right->rk) + (right->rk - left->rk);
    }

}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int j = 1; j <= n; ++j) {
        a[j].rk = j;
        for (int i = 0; i < k; ++i) {
            int s;
            scanf("%d", &s);
            a[j].sum += s;
        }
    }
    qsort(a + 1, n,
          sizeof(a[1]), cop);
    printf("%d\n%d", a[n].rk, a[n - 1].rk);

    return 0;
}