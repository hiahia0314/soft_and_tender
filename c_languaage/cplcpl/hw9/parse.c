//
// Created by 23125 on 2023/12/2.
//
#include <stdio.h>
#include <string.h>


#define LEN 1400

int main() {
    char dic[LEN] = {0};
    char input[LEN][LEN] = {0};
    scanf("%s", dic);
    int len = strlen(dic);
    int i = 0;
    while (scanf("%s", input[++i]) != EOF) {}//input从1开始，一共i-1个
    // int count = 2;
    // while (count--) {
    //     scanf("%s", input[++i]);
    // }//从1开始到i
    i--;//因为是++i; 现在开始一共有i个
    for (int j = 2; j <= i; ++j) {//input[1]是程序名，所以从2开始遍历
        if (input[j][0] == '-') {//从-开始才是有用的
            int flag = 0;//=0为没找到匹配的
            for (int k = 0; k < len; ++k) {
                if (input[j][1] == dic[k]) {
                    if (dic[k + 1] == ':' && j + 1 > i) {//参数后有“:”但是input[j]后面没东西了（j+1>i即后面空了）
                        printf("%s: option requires an argument"
                               " -- '%c'", input[1], input[j][1]);
                        return 0;
                    } else {
                        j++;//下一个作为参数，跳过判断
                    }
                    flag = 1;//找到匹配的了
                }
            }
            if (flag == 0) {
                printf("%s: invalid option -- '%c'", input[1], input[j][1]);
                return 0;
            }
        }
    }
    printf("%s\n", input[1]);//程序名
    for (int j = 2; j <= i; ++j) {
        if (input[j][0] != '-') {//不以-开头就跳过
            continue;
        }
        int flag = 0;//用来判断是不是后面有冒号
        for (int k = 0; k < len; ++k) {
            if (dic[k] == input[j][1] && dic[k + 1] == ':') {
                flag = 1;//有冒号
                printf("%c=%s\n", input[j][1], input[j + 1]);
                j++;//跳过下一个input
                break;
            }
        }
        if (flag == 0) {//无冒号
            printf("%c\n", input[j][1]);
        }
    }

    return 0;
}