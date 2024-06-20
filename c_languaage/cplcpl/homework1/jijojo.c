#include <stdio.h>

int main() {
    int live[10000] = {0};
    int min[1000] = {0};
    int qiang = 0;
    int n, k, b, l = 0;//n个人,报数k
    scanf("%d%d%d%d", &n, &k, &b, &l);
    int t = 0;
    for (int j; j < 1000; j++) {
        min[j] = l;
    }
    qiang = b;
    for (int i = 1; i < l * n; i++) {
        for (int j = 0; j < k; j++) {
            t++;
            if (t == n) {
                t = 0;
            }
            if (live[t] == 1) {
                j--;
            }
        }
        if (qiang == 0) {
            qiang = b;
            i--;
            continue;
        } else {
            if (min[t] == 1) {
                live[t] = 1;
            } else {
                min[t]--;
            }
            qiang--;
        }

    }
    for (int i = 1; i <= n; i++) {
        if (live[i] == 0) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}