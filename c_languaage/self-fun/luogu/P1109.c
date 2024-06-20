//
// Created by 23125 on 2023/11/29.
//
#include <stdio.h>

int main() {
    int n, L, R;
    int sum = 0;
    int ans1 = 0;
    int ans2 = 0;
    int student[51] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &student[i]);
        sum += student[i];
    }
    scanf("%d%d", &L, &R);
    if (sum > R * n || sum < L * n) {
        printf("-1");
    } else {
        for (int i = 0; i < n; ++i) {
            if (student[i] > R) {
                ans1 += student[i] - R;
            } else if (student[i] < L) {
                ans2 += L - student[i];
            }
        }
        printf("%d", ans1 > ans2 ? ans1 : ans2);


    }


    return 0;
}