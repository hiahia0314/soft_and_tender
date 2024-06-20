//
// Created by 23125 on 2023/10/30.
//
#include <stdio.h>
int main(){
    int l=0;
    int a,b,m=0;
    int leng[1000]={0};
    scanf("%d%d",&l,&m);
    for(int i=0;i<=l;i++){
        leng[i]=1;
    }
    for (int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        for(int j=a;j<=b;j++){
            leng[j]=-1;
        }
    }
    int count=0;
    for (int i = 0; i <= l; ++i) {
        if(leng[i]==1){
            count++;
        }
    }
    printf("%d",count);
}