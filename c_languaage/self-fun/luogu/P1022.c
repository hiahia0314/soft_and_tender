//
// Created by 23125 on 2023/12/12.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 100

int main() {
    char str[LEN] = {0};
    int b = 0, fuhao = 1, now = 1, x = 0, k = 0, r = 0;
    char a = 0;//判断未知数
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] == '-') {
            r = 0;
            b += now * fuhao * x;
            fuhao = -1;
            x = 0;//x为项的系数
        }
        if (str[i] == '+') {
            r = 0;
            b += now * fuhao * x;
            fuhao = 1;
            x = 0;
        }
        if (str[i] == '=') {
            r = 0;
            b += now * fuhao * x;
            fuhao = 1;
            x = 0;
            now = -1;
        }
        if (isdigit(str[i])) {
            r = 1;//表示可能为未知数的系数
            x = x * 10 + str[i] - '0';//碰到数字就累加，表示俩符号之间的数字
        }
        if (isalpha(str[i])) {
            if (r == 1) {
                k += now * fuhao * x;
                x = 0;
            } else {
                k += now * fuhao;//1或-1
            }
            a = str[i];
            r = 0;
        }

    }
    b += now * fuhao * x;
    double ans = (double) (-b * 1.0 / k);
    if (ans == -0.0) {
        ans = 0;
    }
    printf("%c=%.3lf", a, ans);


    return 0;
}