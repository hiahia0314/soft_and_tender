//
// Created by 23125 on 2023/11/29.
//
#include <stdio.h>
#include <string.h>
#include <math.h>

#define LEN 1000

int main() {
    char flag = 0;
    int sign, equal;
    char str1[LEN];
    char str[LEN];
    gets(str1);
    int len = 0;
    for (int i = 0; i < strlen(str1); ++i) {
        if (str1[i] == ' ') {
            continue;
        }
        str[len] = str1[i];
        if (str[len] == '+') {
            flag = '+';
            sign = len;
        }
        if (str[len] == '-') {
            sign = len;
            flag = '-';
        }
        if (str[len] == '=') {
            equal = len;
        }
        len++;
    }
    if (str[len - 1] == '?') {
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < sign; ++i) {
            num1 += (str[i] - '0') * pow(10, sign - i - 1);
        }
        for (int i = sign + 1; i < len - 2; ++i) {
            num2 += (str[i] - '0') * pow(10, len - i - 3);
        }
        switch (flag) {
            case '+':
                printf("%d", num1 + num2);
                break;
            case '-':
                printf("%d", num1 - num2);
        }
    } else if (str[0] == '?') {
        int num1 = 0;
        int num2 = 0;
        for (int i = 2; i < equal; ++i) {
            num1 += (str[i] - '0') * pow(10, equal - i - 1);
        }
        for (int i = equal + 1; i < len; ++i) {
            num2 += (str[i] - '0') * pow(10, len - i - 1);
        }
        switch (flag) {
            case '+':
                printf("%d", num2 - num1);
                break;
            case '-':
                printf("%d", num2 + num1);
        }
    } else {
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < sign; ++i) {
            num1 += (str[i] - '0') * pow(10, sign - i - 1);
        }
        for (int i = equal + 1; i < len; ++i) {
            num2 += (str[i] - '0') * pow(10, len - i - 1);
        }
        switch (flag) {
            case '+':
                printf("%d", num2 - num1);
                break;
            case '-':
                printf("%d", num1 - num2);
        }

    }


    return 0;
}