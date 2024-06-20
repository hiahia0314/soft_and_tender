//
// Created by 23125 on 2023/12/27.
//
#include <stdio.h>

#define LEN 100

int main() {
    int A[LEN] = {0};
    int B[LEN] = {0};
    int ans[LEN] = {0};
    int a, b;
    scanf("%d", &a);

    int maxa = a - 1;
    for (int i = 0; i < a; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < a; ++i) {
        if (A[i] > A[i + 1]) {
            maxa = i;
            break;
        }
    }


    scanf("%d", &b);
    int maxb = b - 1;
    for (int i = 0; i < b; ++i) {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < b; ++i) {
        if (B[i] > B[i + 1]) {
            maxb = i;
            break;
        }
    }

    int count = 0;
    int aa = 0;
    int bb = 0;
    while (aa <= maxa && bb <= maxb) {
        if (A[aa] < B[bb]) {
            ans[count] = A[aa];
            count++;
            aa++;
        } else if (A[aa] == B[bb]) {
            ans[count] = A[aa];
            aa++;
            count++;
            ans[count] = B[bb];
            bb++;
            count++;
        } else {
            ans[count] = B[bb];
            bb++;
            count++;
        }

        if (aa > maxa) {
            while (bb <= maxb) {
                ans[count] = B[bb];
                count++;
                bb++;
            }
        }
        if (bb > maxb) {
            while (aa <= maxa) {
                ans[count] = A[aa];
                count++;
                aa++;
            }
        }
    }

    while (aa < a && bb < b) {
        if (A[aa] > B[bb]) {
            ans[count] = A[aa];
            count++;
            aa++;
        } else if (A[aa] == B[bb]) {
            ans[count] = A[aa];
            aa++;
            count++;
            ans[count] = B[bb];
            bb++;
            count++;
        } else {
            ans[count] = B[bb];
            bb++;
            count++;
        }

        if (aa == a) {
            while (bb < b) {
                ans[count] = B[bb];
                count++;
                bb++;
            }
        }
        if (bb == b) {
            while (aa < a) {
                ans[count] = A[aa];
                count++;
                aa++;
            }
        }
    }
    for (int i = 0; i < count; ++i) {
        printf("%d ", ans[i]);
    }

    return 0;
}