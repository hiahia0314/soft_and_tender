//
// Created by 23125 on 2023/12/15.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN 100

int strcomp(const void *left, const void *right) {
    const char **pp1 = left;
    const char **pp2 = right;
    return strcmp(*pp1, *pp2);


}

int main() {
    char str[LEN] = {0};
    char *string[LEN] = {0};
    scanf("%s", str);
    getchar();
    char t = getchar();
    char de[2] = {t, '\0'};
    string[0] = strtok(str, de);
    int i;
    for (i = 1;
         (string[i] = strtok(NULL, de)) != NULL;
         ++i) {}
    qsort(string, i,
          sizeof(string[0]),
          strcomp);
    for (int j = 0; j < i; ++j) {
        printf("%s\n", string[j]);
    }
    return 0;
}