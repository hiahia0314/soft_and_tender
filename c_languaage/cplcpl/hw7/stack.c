//
// Created by 23125 on 2023/11/18.
//
#include <stdio.h>

#define LEN 10009

int main() {
    char stack[LEN] = {0};
    int n;
    int count = 0;
    char str[LEN][10];
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; ++i) {
        gets(str[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (str[i][0] == 'p' && str[i][1] == 'o') {//pop
            if (count == 0) {
                printf("Empty\n");
            } else {
                count--;
            }
        } else if (str[i][0] == 'p' && str[i][1] == 'u') {//push
            stack[count] = str[i][5];
            count++;
        } else if (str[i][0] == 't') {//rk
            if (count == 0) {
                printf("Empty\n");
            } else {
                printf("%c\n", stack[count - 1]);

            }
        } else if (str[i][0] == 'p' && str[i][1] == 'r') {//print
            if (count == 0) {
                printf("Empty\n");
            } else {
                for (int j = count - 1; j >= 0; --j) {
                    printf("| %c |\n", stack[j]);
                }
                printf("|===|\n");
            }

        }
    }


    return 0;
}