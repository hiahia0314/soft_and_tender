//
// Created by 23125 on 2023/10/23.
//
#include <stdio.h>

int main() {
    int n = 0;
    char str[1009], pp;
    int count1[1009] = {0};
    int shu[1009] = {0};
    int max = 0;
    int zongzimu = 0;
    int jianhao = 0;
    scanf("%d", &n);
    scanf("%c", &pp);
    for (int i = 0; i < n; i++) {
        scanf("%c", &str[i]);
    }
    for (int i = 0; i < n; i++) {
        shu[i] = str[i] - '@'; //A=1 a=33
        count1[shu[i]]++;
    }
    for (int j = 0; j < 1009; j++) {
        if (max <= count1[j]) {
            max = count1[j];     //最多的有多少
        }
    }
    int count2[1009] = {0};
    for (int i = 0; i < 1009; i++) {//把count1复制到count2
        count2[i] = count1[i];
    }
    for (int j = 0; j < max; j++) {
        for (int i = 33; i <= 58; i++) {
            int t = 0;
            if (count2[i] != 0) {
                if (count2[i] - max >= 0) {
                    printf("=");
                    jianhao++;
                } else {
                    count2[i]++;
                    printf(" ");
                    jianhao++;
                }
                t = 1;

            }
            if (count2[i - 32] != 0) {
                if (count2[i - 32] - max >= 0) {
                    printf("=");
                    jianhao++;
                } else {
                    count2[i - 32]++;
                    printf(" ");
                    jianhao++;
                }
                t = 1;
            }
            if (t == 1) {
                printf(" ");
                jianhao++;
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 1009; i++) {  //多少个不同的字母
        if (count1[i] != 0) {
            zongzimu++;
        }
    }
    //printf("%d %d", zongzimu, daxiaoxie);
    for (int i = 0; i < jianhao / max - 1; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 33; i <= 58; i++) {
        int q = 0;
        if (count1[i] != 0) {
            printf("%c", i + '@');
            q = 1;
        }
        if (count1[i - 32] != 0) {
            printf("%c", i - 32 + '@');
            q = 1;
        }
        if (q == 1) {
            printf(" ");
        }

    }
    return 0;
}