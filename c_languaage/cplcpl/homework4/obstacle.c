//
// Created by 23125 on 2023/10/23.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int xa, ya, xb, yb, xc, yc;
    int length = 0;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);

    if (xa == xb && xb == xc && ((yc > yb && yc < ya) || (yc > ya && yc < yb))) {
        length = abs(xa - xb) + abs(ya - yb) + 2;
        printf("%d\n", length);
        if (ya > yb) {
            for (int i = 0; i < length - 1; i++) {
                if (ya - 1 == yc) {
                    printf("R");
                    ya = ya - 2;
                } else {
                    printf("D");
                    ya--;
                }
            }


            printf("L");
        } else {
            for (int i = 0; i < length - 1; i++) {
                if (ya + 1 == yc) {
                    printf("R");
                    ya = ya + 2;
                } else {
                    printf("U");
                    ya++;
                }
            }
            printf("L");
        }
    } else if (ya == yb && yb == yc && ((xc > xb && xc < xa) || (xc > xa && xc < xb))) {
        length = abs(xa - xb) + abs(ya - yb) + 2;
        printf("%d\n", length);

        if (xa > xb) {
            for (int i = 0; i < length - 1; i++) {
                if (xa - 1 == xc) {
                    printf("D");
                    xa = xa - 2;
                } else {
                    printf("L");
                    xa--;
                }
            }
            printf("U");
        } else {
            for (int i = 0; i < length - 1; i++) {
                if (xa + 1 == xc) {
                    printf("D");
                    xa = xa + 2;
                } else {
                    printf("R");
                    xa++;
                }
            }
            printf("U");
        }
    } else {
        length = abs(xa - xb) + abs(ya - yb);
        printf("%d\n", length);

        if (xc == xb || (xc != xb && yc != yb)) {
            for (int i = 0; i < length; i++) {
                if ((yb > ya) && (xa != xc || (xa == xc && ya + 1 != yc))) {
                    printf("U");
                    ya++;
                } else if (yb < ya && (xa != xc || (xa == xc && ya - 1 != yc))) {
                    printf("D");
                    ya--;
                } else if ((xb > xa) && (ya != yc || (ya == yc && xa + 1 != xc))) {
                    printf("R");
                    xa++;
                } else if ((xb < xa) && (ya != yc || (ya == yc && xa - 1 != xc))) {
                    printf("L");
                    xa--;
                }
            }
        } else {
            for (int i = 0; i < length; i++) {
                if ((xb > xa) && (ya != yc || (ya == yc && xa + 1 != xc))) {
                    printf("R");
                    xa++;
                } else if ((xb < xa) && (ya != yc || (ya == yc && xa - 1 != xc))) {
                    printf("L");
                    xa--;
                } else if ((yb > ya) && (xa != xc || (xa == xc && ya + 1 != yc))) {
                    printf("U");
                    ya++;
                } else if (yb < ya && (xa != xc || (xa == xc && ya - 1 != yc))) {
                    printf("D");
                    ya--;
                }

            }
        }
    }
    return 0;
}