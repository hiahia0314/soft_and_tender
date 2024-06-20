//
// Created by 23125 on 2023/12/7.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 100

int main() {
    char key[LEN] = {0};
    char dark[LEN] = {0};
    char ans[LEN] = {0};
    scanf("%s%s", key, dark);
    int lenkey = strlen(key);
    int lendark = strlen(dark);
    for (int i = 0; i < lendark; ++i) {
        int m;
        if (isupper(dark[i])) {
            m = 'A';
        } else {
            m = 'a';
        }
        ans[i] = (26 + dark[i] - m - toupper(key[i % lenkey]) + 'A') % 26 + m;

    }
    printf("%s", ans);


    return 0;
}