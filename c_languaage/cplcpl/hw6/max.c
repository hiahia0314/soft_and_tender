//
// Created by 23125 on 2023/11/13.
//
#include <stdio.h>

#define LEN 100

void Maxlr(int arr[], int len, int i, int ans[][2]) {
    int r = i;
    int l = i;
    while (1) {
        if (arr[r + 1] > arr[i] || r == len) {
            break;
        }
        r++;
    }
    while (1) {
        if (arr[l - 1] > arr[i] || l == 1) {
            break;
        }
        l--;
    }
    ans[i][0] = l;
    ans[i][1] = r;
}

int main() {
    int n;
    int ans[LEN][2] = {0};

    int arr[LEN] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);

    }
    for (int i = 1; i <= n; ++i) {
        Maxlr(arr, n, i, ans);

    }
    for (int j = 1; j <= n; j++) {
        printf("%d %d\n ", ans[j][0], ans[j][1]);
    }

    return 0;
}