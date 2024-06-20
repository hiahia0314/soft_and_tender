//
// Created by 23125 on 2023/9/23.
//
#include <stdio.h>
int main(){
    const double MOL=6.02e23;
    const int G_PER_MOL=32;
    int mass=6;
    double quantity=mass*1.0/G_PER_MOL*MOL;//mass/6==0,mass*1.0
    printf("quantity=%.5g\nquantity=%.3e\n",quantity,quantity);//%e表示科学技术法 也是默认小数点后六位
                                                                    //保留五位有效数字 g：重要数字..


    return 0;
}