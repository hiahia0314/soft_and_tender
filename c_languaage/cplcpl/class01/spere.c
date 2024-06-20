//
// Created by 23125 on 2023/9/23.
//
#include <stdio.h>
int main() {
    const double PI = 3.1415;
    int radius = 100;
    double volume = 4.0 / 3 * PI * radius * radius * radius;//4/3整数相除只会得整数，所以4.0/3
    double surface_area=4.0*PI*radius*radius;
    printf("%-15.4f:volume\n"
           "%-15.4f:surface_area",volume,surface_area);//15. 表示至少输出15个字符，
                                                      //默认情况下是右对齐  -：使得左对齐
    return 0;
}