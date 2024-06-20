//
// Created by 23125 on 2023/11/22.
//
#include <stdio.h>
#include <string.h>

#define LEN 100000

int main() {

    int A[LEN] = {0};
    char A1[LEN] = {0};
    int B[LEN] = {0};
    char B1[LEN] = {0};
    int C[LEN] = {0};
    int ans[LEN] = {0};
    scanf("%s", A1);

    for (int i = 0; i < strlen(A1); ++i) {
        A[i] = A1[strlen(A1) - i - 1] - '0';
    }
    scanf("%s", B1);
    for (int i = 0; i < strlen(B1); ++i) {
        B[i] = B1[strlen(B1) - i - 1] - '0';
    }
    int m = strlen(A1) > strlen(B1) ? strlen(A1) : strlen(B1);
    for (int i = 0; i < m; ++i) {
        if (A[i] + B[i] + C[i - 1] >= 10) {
            C[i] = 1;
        }
    }
    if (C[m - 1] == 1) {
        m++;
    }
    for (int i = 0; i < m; ++i) {
        ans[i] = (C[i - 1] + A[i] + B[i]) % 10;
    }

    for (int i = m - 1; i >= 0; --i) {
        printf("%d", ans[i]);
    }
    printf("\n");


    return 0;
}