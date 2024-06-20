//
// Created by 23125 on 2023/11/2.
//
#include <stdio.h>
#define LEN 100
int CatchMax(int i);
int main(){
    int n=0;
    int max=0;
    int arr[LEN]={0};
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    max= CatchMax(arr[0]);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if(max< CatchMax(arr[i])){
                max= CatchMax(arr[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if(CatchMax(arr[i])==max){
                arr[i]=0;
                break;
            }
        }
        printf("%d",max);
    }

    return 0;
}
int CatchMax(int i){
    while (i>=10){
        i/=10;
    }
    return i;
}