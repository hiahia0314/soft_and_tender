//
// Created by 23125 on 2023/12/25.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 2005

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int flag = 0;//correct
        int where[LEN] = {0};//标记双重？的位置
        int bat[100] = {0};//桶计数法
        int n;
        int count = 0;
        scanf("%d", &n);
        char input[LEN] = {0};
        scanf("%s", input);
        char ans[LEN] = {0};
        scanf("%s", ans);

        for (int i = 0; i < n / 2; ++i) {//看题目能不能是回文的，有没有解
            if (input[i] == '?' || input[n - 1 - i] == '?') {
                continue;
            } else {
                if (input[i] != input[n - 1 - i]) {
                    flag = 1;
                    break;
                }
            }
        }

        for (int i = 0; i < n; ++i) {//记录有多少个双重问好，并用where记录他们的位置
            if (input[i] == '?') {
                if (input[n - 1 - i] == '?') {
                    where[count] = i;
                    count++;
                }
                continue;
            }
            if (ans[i + count] != input[i]) {//看答案有没有把题目改了
                flag = 1;
            }
        }


        int len = strlen(ans);
        for (int i = 0; i < len / 2; ++i) {
            if (ans[i] != ans[len - 1 - i]) {//答案回文？
                flag = 1;
                break;
            }
        }

        for (int i = 0; i < count / 2; ++i) {//根据where的标记
            if (!isdigit(ans[where[i] + i]) || !isdigit(ans[where[i] + i + 1])) {//两者必须是数字
                flag = 1;
            } else {
                bat[(ans[where[i] + i] - '0') * 10 + (ans[where[i] + i + 1] - '0')]++;//算出数字的值
            }
        }

        for (int i = 0; i < 100; ++i) {//桶计数
            if (bat[i] > 2 || (bat[i] == 2 && (i / 10 == i % 10))) {//9898可以但是1111不行
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            printf("Wrong Answer!\n");
        } else {
            printf("Correct.\n");
        }

    }

    return 0;
}
