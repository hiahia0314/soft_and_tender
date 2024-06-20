//
// Created by 23125 on 2023/10/18.
//
#include <stdio.h>
int main(){
    int n=1;
    int t=0;
    scanf("%d",&t);
   double sum=1.0;
    while (sum<=t)   {
        n++;
        sum+=1.0/n;
    }
    printf("%d",n);
    return 0;
}