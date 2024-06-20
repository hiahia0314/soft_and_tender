//
// Created by 23125 on 2023/10/16.
//


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str1[100];
    int lentotal[10000] = {0};
    int n;
    int sum = 0;
    int num[1000] = {0};
    int len = 0;
    int answer[1000] = {0};
    scanf("%d", &n);
    for (int m = 0; m < n; m++) {
        scanf("%s", &str1);
        if(atoi(str1)>0){
            int t = atoi(str1);
            for (int i = 0; t != 0; i++) {
                num[i] = t % 3;
                t /= 3;
                lentotal[m]++;
            }
            for (int j = 0; j < lentotal[m]; j++) {
                if (num[j] == 2) {
                    num[j] = -1;
                    num[j + 1]++;
                }
                if (num[j] == 3) {
                    num[j] = 0;
                    num[j + 1]++;
                }
            }
            if (num[lentotal[m]] != 0) {
                lentotal[m]++;
            }
            for (int j = 0; j < lentotal[m] / 2; j++) {
                int tem = num[j];
                num[j] = num[lentotal[m] - j - 1];
                num[lentotal[m] - j - 1] = tem;
            }//交换顺序
            for (int i = 0; i < lentotal[m]; i++) {
                answer[sum + i + m] = num[i];
            }
        }
        if(atoi(str1)==0){
            answer[sum+m]=0;
            lentotal[m]=1;
        }
        if(atoi(str1)<0){
            int t=-1* atoi(str1);
            for (int i = 0; t != 0; i++) {
                num[i] = t % 3;
                t /= 3;
                lentotal[m]++;
            }
            for (int j = 0; j < lentotal[m]; j++) {
                if (num[j] == 2) {
                    num[j] = -1;
                    num[j + 1]++;
                }
                if (num[j] == 3) {
                    num[j] = 0;
                    num[j + 1]++;
                }
            }
            if (num[lentotal[m]] != 0) {
                lentotal[m]++;
            }
            for(int i=0;i<lentotal[m];i++) {
                if (num[i]==-1){
                    num[i]=1;
                } else if(num[i]==1){
                    num[i]=-1;
                }
            }
            for (int j = 0; j < lentotal[m] / 2; j++) {
                int tem = num[j];
                num[j] = num[lentotal[m] - j - 1];
                num[lentotal[m] - j - 1] = tem;
            }//交换顺序
            for (int i = 0; i < lentotal[m]; i++) {
                answer[sum + i + m] = num[i];
            }
        }
        for(int i=0;i< strlen(str1);i++){
            if((str1[i]!='-'&&str1[i]!='0'&&str1[i]!='1'&&str1[i]!='2'&&str1[i]!='3'&&str1[i]!='4'
            &&str1[i]!='5'&&str1[i]!='6'&&str1[i]!='7'&&str1[i]!='8'&&str1[i]!='9')|| strlen(str1)>15){
                answer[sum+m]=11;
                lentotal[m]=1;
            }
        }
        sum += lentotal[m];
        answer[sum + m] = 10;
        for(int i=0;i<sum+m+1;i++){
            num[i]=0;
        }
    }

    for (int i = 0; i < sum + n; i++) {
     if(answer[i]==10){
         printf("\n");
     } else if(answer[i]==11){
         printf("Radix Error");
     }else if(answer[i]==-1){
         printf("%c",'Z');
     } else{
         printf("%d",answer[i]);
     }
    }
    return 0;
}