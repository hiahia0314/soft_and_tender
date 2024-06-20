//
// Created by 23125 on 2023/10/15.
//
#include <stdio.h>
#include <string.h>
#include <math.h>
char str[1500];
int sum[10009] = {0};
int ture[10090]={0};

int main() {

    int n, len;
    scanf("%d ", &n);
    for (int j = 0; j < n; j++) {
        scanf("%s",str);
        len = strlen(str);
        for (int k = 0; k < len; k++) {
            if(str[k]!='0'&&str[k]!='1'&&str[k]!='Z'){
                ture[j]=-1;
                break;
            }
            if (str[k] == 'Z') {
                str[k] = str[k] - 'Z' - 1;
            } else {
                str[k] = str[k] - '0';
            }
            sum[j] += str[k] * pow(3, len - k - 1);
        }
    }
    for(int j=0;j<n;j++) {
        if(ture[j] == -1){
            printf("Radix Error\n");
        }else{
            printf("%d\n",sum[j]);
        }
    }
    return 0;
}