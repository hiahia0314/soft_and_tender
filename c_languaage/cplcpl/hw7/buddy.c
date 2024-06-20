//
// Created by 23125 on 2023/11/20.
//
#include<stdio.h>
#include <math.h>

#define LEN 3000
int lianshu = 1;
int size[LEN];
int cunid[LEN];

int Findci(int m) {
    int k = 0;
    while (1) {
        if (pow(2, k) >= m) {
            break;
        }
        k++;
    }
    return k;
}

void paixv(int id, int ci) {
    for (int i = 1; i <= lianshu; ++i) {//刚好
        if (size[i] == ci && cunid[i] == 0) {
            cunid[i] = id;
            return;

        }
    }
    for (int j = 1; j <= lianshu; ++j) {
        if (size[j] >= ci && cunid[j] == 0) {//j分裂
            for (int i = lianshu + 1; i > j; --i) {
                cunid[i] = cunid[i - 1];
                size[i] = size[i - 1];

            }
            size[j]--;
            size[j + 1]--;
            lianshu++;
            break;
        }
    }
    paixv(id, ci);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    size[1] = n;
    for (int i = 0; i < q; ++i) {
        getchar();
        char dir;
        scanf("%c", &dir);
        if (dir == 'A') {
            int id, m;
            scanf("%d%d", &id, &m);
            paixv(id, Findci(m));
        } else {
            printf("%d\n", lianshu);
            for (int j = 1; j <= lianshu; ++j) {
                printf("%d ", cunid[j]);
            }
        }


    }

    return 0;
}