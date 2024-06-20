//
// Created by 23125 on 2023/9/23.
//
#include <stdio.h>
int main(){
    char month[10];
    char weekday[10];
    int day,year,hour,minute,second;
    scanf("%s %d %d %s %d %d %d",month,&day,&year,weekday,&hour,&minute,&second);
    printf("%.3s %.3s %02d %02d:%02d:%02d %04d",weekday,month,day,hour,minute,second,year);
    return 0;
}
