//
// Created by 23125 on 2023/9/23.
//
#include <stdio.h>
int main(){
    const double G=6.674e-11;
    double m,R,F;
    double M=77.15;
    scanf("%lf %lf",&m,&R);
    F=G*M*m/(R*R);
    printf("%.3e",F);


    return 0;
}