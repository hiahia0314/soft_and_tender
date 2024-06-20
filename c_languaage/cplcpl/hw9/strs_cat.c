//
// Created by 23125 on 2023/12/2.
//
#include <stdio.h>
#include <string.h>

#define LEN 100

void mystr(char *s1, char *s2) {
    int t = strlen(s1) > strlen(s2) ? strlen(s1) - strlen(s2) : 0;
    for (int i = t; i < strlen(s1); ++i) {
        int flag = 1;

        if (s1[i] == s2[0]) {
            for (int j = 0; j < strlen(s2) && i + j < strlen(s1); ++j) {
                if (s1[i + j] != s2[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                for (int j = 0; j < i; ++j) {
                    printf("%c", s1[j]);
                }
                printf("%s", s2);
                return;
            }
        }
        if (i == strlen(s1) - 1) {
            printf("%s%s", s1, s2);
            return;
        }
    }

}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        char s1[LEN];
        char s2[LEN];
        scanf("%s", s1);
        scanf("%s", s2);
        //mystr(s1, s2);
        size_t ls1 = strlen(s1);
        size_t ls2 = strlen(s2);
        for (size_t j = (ls1 > ls2) ? (ls1 - ls2) : 0; j <= ls1; ++j) {
            char *qq = strstr(s2, s1 + j);
            if (strstr(s2, s1 + j) != s2) {
                continue;
            }
            printf("%s%s", s1, s2 + ls1 - j);
            break;
        }
    }
    return 0;
}