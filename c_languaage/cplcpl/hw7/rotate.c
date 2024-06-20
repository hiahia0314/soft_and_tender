//
// Created by 23125 on 2023/11/19.
//
#include <stdio.h>
#include <string.h>

#define LEN 10


int main() {
    int a, b, c, t;
    char dir[LEN];
    scanf("%d%d%d", &a, &b, &c);
    int x1 = 0;
    int x2 = a;
    int y1 = 0;
    int y2 = b;
    scanf("%s", dir);
    for (int i = 0; i < strlen(dir); ++i) {
        if (dir[i] == 'S') {//qian
            x1 = x2;
            x2 += c;
            t = a;
            a = c;
            c = t;
        } else if (dir[i] == 'W') {//hou
            x2 = x1;
            x1 -= c;
            t = a;
            a = c;
            c = t;
        } else if (dir[i] == 'A') {//left
            y2 = y1;
            y1 -= c;
            t = c;
            c = b;
            b = t;

        } else if (dir[i] == 'D') {
            y1 = y2;
            y2 += c;
            t = c;
            c = b;
            b = t;
        }
    }
    printf("%d %d %d %d", x1, x2, y1, y2);


    return 0;
}