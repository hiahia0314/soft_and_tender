//
// Created by 23125 on 2023/12/16.
//
#include <stdio.h>

void Print(int plus[], int max);

#define LEN 100
char var[LEN] = {0};

int main() {
    int jie1, jie2;
    int P1[LEN] = {0};
    int P2[LEN] = {0};
    int plus[LEN] = {0};
    int dim[LEN] = {0};
    int ji[LEN] = {0};
    scanf("%d%d", &jie1, &jie2);
    scanf("%s", var);
    for (int i = 0; i <= jie1; ++i) {
        scanf("%d", &P1[i]);
    }
    for (int i = 0; i <= jie2; ++i) {
        scanf("%d", &P2[i]);
    }
    int max = jie2 > jie1 ? jie2 : jie1;

    //jia
    for (int i = 0; i <= max; ++i) {
        if (jie2 - i < 0) {
            plus[i] = P1[jie1 - i];
        } else if (jie1 - i < 0) {
            plus[i] = P2[jie2 - i];
        } else {
            plus[i] = P2[jie2 - i] + P1[jie1 - i];
        }
    }

    //jian
    for (int i = 0; i <= max; ++i) {
        if (jie2 - i < 0) {
            dim[i] = P1[jie1 - i];
        } else if (jie1 - i < 0) {
            dim[i] = -P2[jie2 - i];
        } else {
            dim[i] = P1[jie1 - i] - P2[jie2 - i];
        }
    }
    //ji
    for (int i = 0; i <= jie1; ++i) {
        for (int j = 0; j <= jie2; ++j) {
            ji[i + j] += P1[jie1 - i] * P2[jie2 - j];
        }
    }


    Print(plus, max);
    printf("\n");
    Print(dim, max);
    printf("\n");
    Print(ji, jie1 + jie2);
    return 0;
}

void Print(int plus[], int max) {
    for (int i = max; i >= 0; i--) {
        if (plus[i] == 0) {
            continue;
        }
        if (i == 0) {
            if (plus[0] > 0) {
                printf("+%d", plus[0]);
            } else {
                printf("%d", plus[0]);
            }
            break;
        }

        if (plus[i] > 0 && i != max) {
            if (plus[i] == 1 && i != 1) {
                printf("+%s^%d", var, i);
            }
            if (plus[i] == 1 && i == 1) {
                printf("+%s", var);
            }
            if (plus[i] != 1 && i == 1) {
                printf("+%d%s", plus[i], var);
            }
            if (plus[i] != 1 && i != 1) {
                printf("+%d%s^%d", plus[i], var, i);
            }
        } else if (plus[i] > 0 && i == max) {
            if (plus[i] == 1 && i != 1) {
                printf("%s^%d", var, i);
            }
            if (plus[i] == 1 && i == 1) {
                printf("%s", var);
            }
            if (plus[i] != 1 && i == 1) {
                printf("%d%s", plus[i], var);
            }
            if (plus[i] != 1 && i != 1) {
                printf("%d%s^%d", plus[i], var, i);
            }
        } else {//plus[i]<0
            if (plus[i] == -1 && i != 1) {
                printf("-%s^%d", var, i);
            }
            if (plus[i] == -1 && i == 1) {
                printf("-%s", var);
            }
            if (plus[i] != -1 && i == 1) {
                printf("%d%s", plus[i], var);
            }
            if (plus[i] != -1 && i != 1) {
                printf("%d%s^%d", plus[i], var, i);
            }
        }
    }

}

