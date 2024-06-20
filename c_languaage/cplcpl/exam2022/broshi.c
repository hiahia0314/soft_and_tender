//
// Created by 23125 on 2023/12/26.
//
#include <stdio.h>
#include <string.h>

#define LEN 100

int main(void) {
    int times = 0;
    scanf("%d", &times);

    for (int i = 0; i < times; i++) {
        int len = 0;
        char standard[LEN] = {0};
        char answer[LEN] = {0};

        scanf("%d%s%s", &len, standard, answer);
        int j = 0;
        int q = 0;
        int status = 1;
        int num = 0;
        int num_1 = 0;
        int num_2 = 0;
        int count[100] = {0};
        while (j < (len / 2))//遍历题目中前一半的元素
        {
            if (standard[j] == '?')//如果题目中被检索的位置是问号
            {
                if (standard[len - 1 - j] != '?')//如果题目的对应位置不是问号
                {
                    if (answer[q] != standard[len - 1 - j])//如果答案中填充该位置的与题目中对应回文位置的不一样
                    {
                        printf("Wrong Answer!\n");//打印答案错误
                        status = 0;//标记该答案错误
                        break;//跳出遍历题目的这个循环
                    } else//如果答案中填充该位置的与题目的对应回文位置的一样，即该位置答案填充正确
                    {
                        j++;//检索题目下一个位置
                        q++;//答案移动至与题目的对应位置
                    }
                } else//如果题目中的对应回文位置是问号
                {
                    if (answer[q] == '?' || answer[strlen(answer) - q - 1] == '?') {
                        printf("Wrong Answer!\n");//打印答案错误
                        status = 0;//标记答案错误
                        break;//跳出遍历此题目的循环
                    }
                    if (answer[q] != answer[strlen(answer) - 1 - q] || answer[q + 1] != answer[strlen(answer) - 2 - q])
                        //若判断答案中该位置填充的数字不符合回文条件
                    {
                        printf("Wrong Answer!\n");//打印答案错误
                        status = 0;//标记答案错误
                        break;//跳出遍历此题目的循环
                    } else//若判断答案中该位置填充的数字符合回文条件
                    {
                        num_1 = 10 * (answer[q] - '0') + answer[q + 1] - '0';//num_1为答案前半部分两个数字构成的两位数
                        num_2 = 10 * (answer[q + 1] - '0') + answer[q] - '0';//num_2为答案后半部分两个数字构成的两位数
                        //桶计数法，若该数字翻转后仍与原数字相同，则出现两次违法；若翻转后与原数字不同，则出现两次合法
                        if (count[num_1] > 0) {
                            num = num_2;
                        } else {
                            num = num_1;
                        }
                        count[num]++;
                        if (count[num] > 1)//若违法
                        {
                            printf("Wrong Answer!\n");
                            status = 0;
                            break;
                        } else//若不违法
                        {
                            q += 2;//答案向后移动两位
                            j++;//题目向后移动一位
                        }
                    }
                }
            } else//如果题目中被检索的位置不是问号
            {
                if (standard[strlen(standard) - j - 1] == '?')//判断其对应位置是问号
                {
                    if (standard[j] == answer[q])//判断若答案的对应位置与题目相同，即答案没有改变题目原字符
                    {
                        if (answer[q] == answer[strlen(answer) - q - 1])//判断答案中该位置与对应回文位置相同
                        {
                            j++;//题目向后移动一位
                            q++;//答案向后移动一位
                        } else//判断答案中该位置与对应回文位置不相同
                        {
                            status = 0;//标记答案错误
                            printf("Wrong Answer!\n");//打印答案错误
                            break;//跳出遍历题目的循环
                        }
                    } else//判断若答案的对应位置与题目不相同，即答案改变了题目原字符
                    {
                        status = 0;//标记答案错误
                        printf("Wrong Answer!\n");//打印答案错误
                        break;//跳出遍历题目的循环
                    }
                } else//判断其对应位置不是问号
                {
                    if (standard[j] == standard[strlen(standard) - j - 1])//判断题目在该位置是回文的
                    {
                        if (answer[q] == standard[j] &&
                            answer[strlen(answer) - q - 1] == standard[strlen(standard) - j - 1])
                            //判断答案中该位置与对应回文位置分别都与题目相同
                        {
                            j++;//题目向后移动一位
                            q++;//答案向后移动一位
                        } else//判断答案中该位置与对应回文位置分别至少有一个与题目不同
                        {
                            status = 0;//标记答案错误
                            printf("Wrong Answer!\n");//打印答案错误
                            break;//跳出遍历题目的循环
                        }
                    } else//判断题目在该位置不是回文的
                    {
                        status = 0;//标记答案错误
                        printf("Wrong Answer!\n");//打印答案错误
                        break;//跳出遍历题目的循环
                    }
                }
            }
        }
        if (status == 1)//如果答案正确
        {
            printf("Correct.\n");
        }

    }
}
