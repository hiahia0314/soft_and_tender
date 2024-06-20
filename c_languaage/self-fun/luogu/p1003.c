//会爆炸
//#include <stdio.h>
//int main(){
//    int n=0;
//    int board[1000][1000]={0};
//    scanf("%d",&n);
//    int pInt,pinhtb,pingt,pingk,x,y;
//    for(int i=1;i<=n;i++){
//        scanf("%d%d%d%d",&pInt,&pinhtb,&pingt,&pingk);
//        for(int j=pInt;j<=pInt+pingt;j++){
//            for (int l =pinhtb; l <=pinhtb+pingk ; l++) {
//                board[j][l]=i;
//            }
//        }
//    }
//    scanf("%d%d",&x,&y);
//    if(board[x][y]==0){
//        printf("-1");
//    } else{
//        printf("%d",board[x][y]);
//    }
//    return 0;
//}
#include <stdio.h>
# define LEN 10000
int main(){
    int n,x,y;
    int A[LEN]={0};
    int B[LEN]={0};
    int G[LEN]={0};
    int K[LEN]={0};

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&A[i],&B[i],&G[i],&K[i]);
    }
    scanf("%d%d",&x,&y);
    int ans=-1;
    for (int i = 0; i < n; ++i) {
        if(x>=A[i]&&x<=A[i]+G[i]&&y>=B[i]&&y<=B[i]+K[i]){
            ans=i+1;
        }
    }
    printf("%d",ans);
    return 0;
}