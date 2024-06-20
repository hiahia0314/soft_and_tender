//
// Created by 23125 on 2023/12/26.
//
#include <stdio.h>
#include <string.h>

#define LEN 1005

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int flag = 1;//满足
        int zu[LEN] = {0};
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &zu[i]);
        }
        while (m--) {
            int w;
            scanf("%d", &w);
            int tmp = zu[w];
            for (int i = w; i >= 1; --i) {
                zu[i] = zu[i - 1];
            }
            zu[1] = tmp;
        }

        for (int i = 1; i < n; ++i) {
            if (zu[i + 1] < zu[i]) {
                flag = 0;//not
                break;
            }
        }
        if (flag == 1) {
            printf("I love C programming language\n");
        } else {
            printf("mayi is a good teacher\n");
        }

    }

    return 0;
}