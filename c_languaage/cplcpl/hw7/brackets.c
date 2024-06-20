//
// Created by 23125 on 2023/11/18.
//
#include <stdio.h>
#include <string.h>

#define LEN 100005

int main() {
    int n;
    int ans[31] = {0};
    char str[LEN] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char stack[LEN] = {0};
        int count = 0;
        scanf("%s", str);

        for (int j = 0; j < strlen(str); ++j) {
            if (str[j] == '(' || str[j] == '[' || str[j] == '{') {
                //        if (numlian == 0 || str[j - 1] == '(' || str[j - 1] == '{' || str[j - 1] == '[') {
                stack[count] = str[j];
                count++;
//                } else {
//                    ans[i] = -1;
//                    break;
//                }

            } else {
                if ((stack[count - 1] != '(' && str[j] == ')')
                    || (stack[count - 1] != '{' && str[j] == '}') ||
                    (stack[count - 1] != '[' && str[j] == ']') || count == 0) {
                    ans[i] = -1;//false
                    break;
                } else {
                    count--;
                }
            }
            if (count >= strlen(str) / 2 + 1) {
                ans[i] = -1;
                break;
            }
        }
        if (count != 0) {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 0) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }

    return 0;
}