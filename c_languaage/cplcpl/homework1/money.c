#include <stdio.h>
int main(){
    int n=0;

    int fifty=0;
    int twenty=0;
    int ten=0;
    int five=0;
    int one=0;
    scanf("%d",&n);
    fifty= n / 50;
    twenty= (n - fifty * 50) / 20;
    ten= (n - fifty * 50 - twenty * 20) / 10;
    five= (n - fifty * 50 - twenty * 20 - ten * 10) / 5;

    one=(n - fifty * 50 - twenty * 20 - ten * 10 - five * 5);
    printf("%d\n%d\n%d\n%d\n%d\n",fifty,twenty,ten,five,one);
    return 0;

}