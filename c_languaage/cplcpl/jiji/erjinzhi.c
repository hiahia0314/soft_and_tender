//
// Created by 23125 on 2023/10/10.
//
#include <stdio.h>
#include <string.h>

int main() {
    char s[5][100] = {0};
//    scanf("%s", s);
//    char *position = strchr(s, ';');
//    char s1[100] = {0};
//    memmove(s1, s, position - s);
//    printf("%s", s1);
    int n = 4;
    while (n--) {
        scanf("%[^;]", s[4 - n]);
        
    }
    printf("%s %s %s %s", s[4], s[1], s[2], s[3]);


    return 0;
}