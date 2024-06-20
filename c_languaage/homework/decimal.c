//
// Created by 23125 on 2023/10/14.
//
#include <stdio.h>
#include <math.h>


int main() {
    int t = 0;
    int sum = 0;
    int len, n;
    scanf("%d%d", &len, &n);
    char num[1000] = {0};
    for (int i = 0; i < len; i++) {
        scanf(" %c", &num[i]);
    }
    for (int j = 0; j < len; j++) {
        if (num[j] >= '0' && num[j] <= '9') {
            num[j] = num[j] - '0';
        } else if (num[j] >= 'A' && num[j] <= 'F') {
            num[j] = num[j] - 'A' + 10;
        }
    }
    for(int j=0;j<len;j++) {
        if (num[j] >= n) {
            printf("Error");
            t=1;

            break;
        }
    }
    if(t==0) {
            for (int i = 0; i < len; i++) {
                sum += num[i] * pow(n, len - 1 - i);
            }
            printf("%d", sum);

        }
    }

