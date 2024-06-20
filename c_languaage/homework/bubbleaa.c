//
// Created by 23125 on 2023/10/14.
//
#include <stdio.h>
#include <time.h>

int main() {
    time_t start,end;

    start= time(NULL);
    int a[100]={0};
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 2; j++) { // not j < n - i - 1
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    end= time(NULL);
    printf("%f",(float)(end-start));
    return 0;
}