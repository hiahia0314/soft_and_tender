//
// Created by 23125 on 2023/11/11.
//
#include <stdio.h>

#include <string.h>

int main() {
    char ming[105] = {0};
    char mi[105] = {0};
    char shuru[105] = {0};
    int tong1[26] = {0}; //检查Ming
    int tong2[26] = {0};//检查Mi
    scanf("%s", ming);
    int check = 1;
    scanf("%s", mi);
    for (int i = 0; i < strlen(ming); ++i) {
        tong1[ming[i] - 'A']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (tong1[i] == 0) {
            printf("Failed");
            check = 0;
            break;
        }
    }


    for (int i = 0; i < strlen(ming); ++i) {
        tong2[mi[i] - 'A']++;
    }
    if (check == 1) {
        for (int i = 0; i < 26; ++i) {
            if (tong2[i] == 0) {
                printf("Failed");
                check = 0;
                break;
            }
        }
    }

    if (check == 1) {
        for (int j = 0; j < strlen(ming); ++j) {
            for (int i = 0; i < strlen(ming); ++i) {
                if (ming[j] == ming[i] && mi[j] != mi[i]) {
                    printf("Failed");
                    check = 0;
                    j = 101;

                    break;

                }
            }
        }
    }

    scanf("%s", shuru);
    if (check == 1) {
        for (int j = 0; j < strlen(shuru); ++j) {
            for (int i = 0; i < strlen(ming); ++i) {
                if (shuru[j] == ming[i]) {
                    printf("%c", mi[i]);
                    break;
                }
            }
        }

    }


    return 0;
}
