//
// Created by 23125 on 2023/12/28.
//
#include <stdio.h>
#include <string.h>

#define LEN 100

int main() {
    int t;
    char str[LEN] = {0};
    char copy[LEN] = {0};
    scanf("%d", &t);
    scanf("%s", str + 1);
    int len = (int) strlen(str + 1);

    while (t--) {
        for (int i = 1; i <= len; ++i) {

            if (str[i] == 'A') {
                int left = i - 1;
                int right = i + 1;
                if (str[left] == 'I' && str[right] == 'I') {
                    copy[i] = '#';
                } else if (str[left] == 'I' && str[right] != 'I') {
                    copy[i] = 'A';
                    copy[right] = 'A';

                } else if (str[left] != 'I' && str[right] == 'I') {
                    copy[left] = 'A';
                    copy[i] = 'A';

                } else {
                    copy[i] = 'A';
                    copy[left] = 'A';
                    copy[right] = 'A';
                }
            } else if (copy[i] != 'A') {
                copy[i] = str[i];
            }

        }
        memcpy(str + 1, copy + 1, len);
    }
    for (int i = 1; i <= len; i++) {
        printf("%c", str[i]);
    }
    return 0;
}