//
// Created by 23125 on 2023/11/2.
//
#include <stdio.h>
#include <string.h>

#define LEN 100

int SumA(char arr[], int b);

int SumB(char arr[], int b);

int main() {
    int n = 0;
    char kong;
    scanf("%d", &n);
    scanf("%c", &kong);
    char str[LEN];
    char newstr[LEN];
    memset(str, '.', sizeof(str));
    memset(newstr, '.', sizeof(str));
    scanf("%s", str);
    //printf("%d", strlen(str));
    for (int round = 0; round < n; round++) {
        for (int i = 0; i < strlen(str); ++i) {
            if (str[i] == 'A') {
                if (SumA(str, i) >= 5 || SumB(str, i) > 0 || SumA(str, i) <= 1) {
                    newstr[i] = '.';
                } else {
                    newstr[i] = 'A';
                }
            } else if (str[i] == 'B') {
                if (SumB(str, i) >= 5 || SumA(str, i) > 0 || SumB(str, i) <= 1) {
                    newstr[i] = '.';
                } else {
                    newstr[i] = 'B';
                }
            } else {
                if (SumA(str, i) >= 2 && SumA(str, i) <= 4 && SumB(str, i) == 0) {
                    newstr[i] = 'A';
                } else if (SumB(str, i) >= 2 && SumB(str, i) <= 4 && SumA(str, i) == 0) {
                    newstr[i] = 'B';
                } else {
                    newstr[i] = '.';
                }
            }

        }

        strncpy(str, newstr, strlen(str));
    }

    for (int i = 0; i < strlen(str); ++i) {
        printf("%c", str[i]);
    }
    return 0;
}

int SumA(char arr[], int b) {
    int count = 0;
    if (b >= 3) {
        for (int i = 1; i <= 3; ++i) {
            if (arr[b - i] == 'A') {
                count++;
            }
            if (arr[b + i] == 'A') {
                count++;
            }
        }
    } else if (b == 0) {
        for (int i = 1; i <= 3; ++i) {
            if (arr[b + i] == 'A') {
                count++;
            }
        }
    } else if (b == 1) {
        for (int i = 1; i <= 3; ++i) {
            if (arr[b + i] == 'A') {
                count++;
            }
        }
        if (arr[b - 1] == 'A') {
            count++;
        }
    } else if (b == 2) {
        for (int i = 1; i <= 3; ++i) {
            if (arr[b + i] == 'A') {
                count++;
            }
        }
        if (arr[b - 1] == 'A') {
            count++;
        }
        if (arr[b - 2] == 'A') {
            count++;
        }
    }
    return count;
}

int SumB(char arr[], int b) {
    int count = 0;
    if (b >= 3) {
        for (int i = 1; i <= 3; ++i) {
            if (arr[b - i] == 'B') {
                count++;
            }
            if (arr[b + i] == 'B') {
                count++;
            }
        }
    } else if (b == 0) {
        for (int i = 1; i <= 3; ++i) {
            if (arr[b + i] == 'B') {
                count++;
            }
        }
    } else if (b == 1) {
        for (int i = 1; i <= 3; ++i) {
            if (arr[b + i] == 'B') {
                count++;
            }
        }
        if (arr[b - 1] == 'B') {
            count++;
        }
    } else if (b == 2) {
        for (int i = 1; i <= 3; ++i) {
            if (arr[b + i] == 'B') {
                count++;
            }
        }
        if (arr[b - 1] == 'B') {
            count++;
        }
        if (arr[b - 2] == 'B') {
            count++;
        }
    }
    return count;
}
