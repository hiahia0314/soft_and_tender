//
// Created by 23125 on 2023/11/19.
//
//
// Created by 23125 on 2023/11/18.
//
#include <stdio.h>
#include <math.h>

#define LEN 1000

int HowBigCi(int m) {
    for (int i = 0; 1; ++i) {
        if (pow(2, i - 1) < m && m <= pow(2, i)) {
            return i;
        }
    }
}


int main() {
    int n, q;
    int ans[LEN] = {0};
    int lian = 1;
    int cunid[LEN] = {0};
    int copy[LEN] = {0};
    char dir[5];
    int count = 0;
    scanf("%d%d", &n, &q);
    int minci = n;
    for (int i = 0; i < q; ++i) {
        scanf("%s", dir);
        if (dir[0] == 'A') {
            int id, m;
            scanf("%d%d", &id, &m);
            count++;
            if (count == 1) {
                cunid[1] = id;
            }
            if (HowBigCi(m) < minci) {
                int t = 0;//delta
                while (HowBigCi(m) < minci) {
                    t++;
                    minci--;
                }
                lian += t;
                cunid[lian + 1 - (n - HowBigCi(m))] = id;

                // cunid[numlian] = id;
            } else if (HowBigCi(m) > minci) {
                cunid[lian + 1 - (n - HowBigCi(m))] = id;
            } else if (HowBigCi(m) == minci) {
                minci++;
                cunid[lian + 1 - (n - HowBigCi(m))] = id;
            }
        }
        if (dir[0] == 'Q') {
            printf("%d\n", lian);
            for (int j = 1; j <= lian; ++j) {
                printf("%d ", cunid[j]);
            }
            printf("\n");

        }

    }

    return 0;
}