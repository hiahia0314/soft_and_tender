#include <stdio.h>

void findde(int n, int arr[], int min, int nfound) {
    if (n == 0) {
        for (int i = 0; i < nfound; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = min; i <= n; i++) {
        arr[nfound] = i;
        findde(n - i, arr, i, nfound + 1);
    }
}

int main() {
    int num;
    scanf("%d", &num);
    int arr[num];
    findde(num, arr, 1, 0);
    return 0;
}