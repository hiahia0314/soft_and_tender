//
// Created by 23125 on 2023/11/28.
//
#include <stdio.h>


void game();

void menu();

void test();


int main() {
    test();
    return 0;
}


void menu() {
    printf("*******************\n"
           "******1.play*******\n"
           "******0.exit*******\n"
           "*******************\n");
}

void game() {
    printf("search mine\n");
}

void test() {
    int input;
    do {
        menu();
        printf("choose please :>\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                printf("exit\n");
                break;
            default:
                printf("choose again\n");
                break;
        }
    } while (input);

}