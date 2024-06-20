//
// Created by 23125 on 2023/11/2.
//
#include <stdio.h>
int main(){
    int n=0;
    int count=0;
    int arr[100]={0};
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    count =n;
    for (int i = 0; i < n; ++i) {
        for (int j = 1+i; j <n ; ++j) {
            if(arr[i]==arr[j]){
                arr[i]=-1;
                count--;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
             if(arr[j]>arr[j+1]){
                 int temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;
             }
        }
    }
    printf("%d\n",count);
    for (int i = 0; i < n; ++i) {
        if(arr[i]!=-1){
            printf("%d ",arr[i]);
        }
    }
    return 0;
}