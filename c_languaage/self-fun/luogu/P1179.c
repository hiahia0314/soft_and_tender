//
// Created by 23125 on 2023/10/30.
//
#include <stdio.h>

int main() {
    int L, R, count;
    count=0;
    scanf("%d%d", &L, &R);
    for (int i = L; i <= R; i++) {
        if (i == 2) {
            count++;
        } else if (i > 10 && i < 100) {
            if (i % 10 == 2 ){
                count++;
            }
            if( i / 10 == 2) {
                count++;
            }
        } else if (i > 100 && i < 1000) {
            if (i / 100 == 2) {
                count++;
            }
            if(i % 10 == 2){
                count++;
            }
            if(i / 10 % 10 == 2) {
                    count++;
                }
            }else if (i > 1000 && i < 10000) {
            if (i / 1000 == 2 ){
                count++;
            }if( i % 10 == 2 ){
                count++;
            }if( i / 100 % 10 == 2 ){
                count++;
            }if( i / 10 % 10 == 2) {
                count++;
            }
        } else if (i > 10000 && i < 100000) {
            if (i / 10000 == 2 ){
                count++;
            }if( i % 10 == 2 ){
                count++;
            }if( i / 1000 % 10 == 2 ){
                count++;
            }if( i / 100 % 10 == 2 ){
                count++;
            }if( i / 10 % 10 == 2) {
                count++;
            }
        } else if (i > 100000 && i < 1000000) {
            if (i / 100000 == 2 ){
                count++;
            }if( i % 10 == 2 ){
                count++;
            }if( i / 10000 % 10 == 2 ){
                count++;
            }if( i / 1000 % 10 == 2 ){
                count++;
            }if( i / 100 % 10 == 2 ){
               count++;
            }if(i / 10 % 10 == 2) {
                count++;
            }

        }

    }
    printf("%d",count);
    return 0;
}