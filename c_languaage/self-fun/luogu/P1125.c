//
// Created by 23125 on 2023/11/27.
//
#include <string.h>
#include <stdio.h>


#define LEN 100
char str[LEN];
int tong[26];

int isprime(int a) {
    if (a == 1 || a == 0) {
        return 0;
    }
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int max;
    int min;
    scanf("%s", str);
    for (int i = 0; i < strlen(str); ++i) {
        tong[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (tong[i] >= 1) {
            max = tong[i];
            min = tong[i];
            break;

        }

    }
    for (int i = 0; i < 26; ++i) {
        if (tong[i] >= 1) {
            if (max < tong[i]) {
                max = tong[i];
            }
            if (min > tong[i]) {
                min = tong[i];
            }
        }

    }
    if (isprime(max - min) == 1) {
        printf("Lucky Word\n%d", max - min);
    } else {
        printf("No Answer\n0");
    }


    return 0;
}