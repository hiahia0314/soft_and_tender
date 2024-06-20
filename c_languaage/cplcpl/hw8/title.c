//
// Created by 23125 on 2023/11/26.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *str = malloc(4096);
    if (str == NULL) {
        printf("0");
        return 0;
    }
    gets(str);
    printf("%c", toupper(*str));
    for (int i = 1; i < strlen(str); ++i) {
        if (*(str + i) == ' ') {
            i++;
            printf(" ");
            printf("%c", toupper(*(str + i)));
        } else {
            printf("%c", tolower(*(str + i)));
        }

    }

    free(str);
    return 0;
}