//
// Created by 23125 on 2023/11/22.
//
#include <stdio.h>

#define LEN 100

int main() {
    int L, N;
    int count = 0;
    int shu[LEN] = {0};
    scanf("%d%d", &L, &N);
    for (int i = 0; i <= L; ++i) {
        shu[i] = 1;
    }
    for (int i = 0; i < N; ++i) {
        int dir, start, end;
        scanf("%d%d%d", &dir, &start, &end);
        if (dir == 0) {
            for (int j = start; j <= end; ++j) {
                if (shu[j] == 2) {
                    count++;
                }
                shu[j] = 0;
            }
        }
        if (dir == 1) {
            for (int j = start; j <= end; ++j) {
                if (shu[j] == 0) {
                    shu[j] = 2;
                }
            }
        }
    }
    int numshu = 0;
    for (int i = 0; i <= L; ++i) {
        if (shu[i] == 2) {
            numshu++;
        }
    }
    printf("%d\n%d", numshu, count);

    return 0;
}