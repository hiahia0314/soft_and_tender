//
// Created by 23125 on 2023/11/26.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *S = malloc(100000 * sizeof(*S));
    scanf("%s", S);
    char *T = malloc(strlen(S) * sizeof(*T));
    scanf("%s", T);
    if (S == NULL || T == NULL) {
        printf("no");
        return 0;
    }
    int lent = strlen(T);
    int lens = strlen(S);
    for (int i = 0; i <= lens - lent; ++i) {
        if (*(S + i) == *(T)) {
            int flag = 0;
            for (int j = 0; j < lent; ++j) {
                if (*(S + i + j) != *(T + j)) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                printf("%d ", i);
            }
        }
    }
    free(S);
    free(T);


}