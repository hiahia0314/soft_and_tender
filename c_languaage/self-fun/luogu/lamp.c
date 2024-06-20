//
// Created by 23125 on 2023/10/20.
//
#include <stdio.h>
int main(){
    int n;
    double a;
    int t=0;
    int tong[1000]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&a);
        scanf("%d",&t);
        int zu[100];
        for(int j=1;j<=t;j++){
            zu[j]=j*a;
        }
        for(int j=1;j<=t;j++){
            tong[zu[j]]++;
        }
    }
    for(int i=0;i<=1000;i++){
        if(tong[i]%2==1){
            printf("%d",i);
        }
    }
    return 0;
}