//
// Created by 23125 on 2023/11/28.
//
#include <stdio.h>

//
//int ans = 0;
//
//void find(int m) {
//    if (m <= 1) {
//        return;
//    } else {
//        for (int i = 1; i <= m / 2; ++i) {
//            find(i);
//            ans++;
//        }
//    }
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    find(n);
//    printf("%d", ans + 1);
//
//
//    return 0;
//}
int main() {
    int n;
    int f[1005] = {0};
    f[0] = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            f[i] = f[i - 1];//7和6一样 7/2==6/2==3；
        } else {
            f[i] = f[i - 1] + f[i / 2];
        }//偶数的时候，显然包含一个n/2,与一个n-2....主要在于除以2.
    }
    printf("%d", f[n]);

    return 0;
}