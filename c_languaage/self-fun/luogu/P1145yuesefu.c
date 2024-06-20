#include <stdio.h>

int main() {
    int k = 3;
    scanf("%d", &k);
    int m, ans;
    int flag = 0;
    for (m = k;; m++) {
        ans = 0;
        for (int i = 0; i < k; ++i) {
            ans = (ans + m - 1) % (2 * k - i);
            if (ans < k) {
                break;
            }
            if (i == k - 1) {
                flag = 1;
            }
        }
        if (flag == 1) {
            printf("%d", m);
            break;
        }
    }
    return 0;
}