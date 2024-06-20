//
// Created by 23125 on 2023/10/16.
//
#include <stdio.h>
int main() {
    char answer[100];
    int n;
    int length = 0;
    int num[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &length);
        for (int j = 0; j < length; j++) {
            scanf("%d",& num[j]);
        }
        int max = num[0];
        for (int j = 0; j < length; j++) {
            if (max <= num[j]) {
                max = num[j];
            }
            if (num[length - 1] == max) {
                answer[i] = 1;
            } else {
                answer[i] = -1;
            }
        }
    }
    for(int j=0;j<n;j++){
        if(answer[j]==-1){
            printf("No\n");
        } else if(answer[j]==1){
            printf("Yes\n");
        }
    }
    return 0;
}