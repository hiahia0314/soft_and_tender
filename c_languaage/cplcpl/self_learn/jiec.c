//
// Created by 23125 on 2023/12/2.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN 1000
char *x1 = NULL;
char *x2 = NULL;
char s3[LEN] = {0};

void inter(char *s1, char *s2, int d1, int d2, int size, int count) {
    if (s1 >= x1 && s2 >= x2) {
        return;//防止越界
    }
    if (size <= 1) {
        return;
    }
    for (int i = 0; i < d1; ++i) {
        if (s1 + i >= x1) {
            break;
        }
        s3[count] = *(s1 + i);
        count++;
        size--;
        if (size <= 1) {
            return;
        }
    }
    for (int i = 0; i < d2; ++i) {
        if (s2 + i >= x2) {
            break;
        }
        s3[count] = *(s2 + i);
        count++;
        size--;
        if (size <= 1) {
            return;
        }
    }
    inter(s1 + d1, s2 + d2, d1, d2, size, count);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        memset(s3, 0, sizeof s3);
        int count = 0;
        int d1, d2, size;
        char dic[LEN] = {0};
        scanf("%s", dic);
        char fen = ';';
        char *s1 = strtok(dic, &fen);
        x1 = s1 + strlen(s1);//x1,x2标记界限
        char *s2 = strtok(NULL, &fen);
        x2 = s2 + strlen(s2);
        char *d_1 = strtok(NULL, &fen);
        char *d_2 = strtok(NULL, &fen);
        char *s_ize = strtok(NULL, &fen);
        d1 = atoi(d_1);
        d2 = atoi(d_2);
        size = atoi(s_ize);
        inter(s1, s2, d1, d2, size, count);
        printf("%s", s3);

        printf("\n");

        //printf("%s%s%d%d%d", s1, s2, d1, d2, size);

    }

    return 0;
}
