//
// Created by 23125 on 2023/10/27.
//

#include <stdio.h>

#define LEN 50

void PaiShangChuJie(int zu[][LEN], int hangzong, int lie, int n);

void PaiZhanWei(int zu[][LEN], int hang, int lie, int n);

void PaiYouChuJie(int zu[][LEN], int hang, int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    int zu[LEN][LEN] = {0};
    zu[0][n / 2] = 1;
    int hang = n - 1;
    int lie = (n - 1) / 2;

    PaiShangChuJie(zu, n - 1, lie, 1);
    if (n == 2) {
        n++;
    }
    lie++;
    for (int i = 3; i <= n * n; i++) {
        if (hang - 1 >= 0 && lie + 1 <= n - 1) {//都不出界
            if (zu[hang - 1][lie + 1] == 0) {
                hang--;
                lie++;
                zu[hang][lie] = i;
            } else {
                PaiZhanWei(zu, hang, lie, zu[hang][lie]);
                hang++;
            }
        } else if (hang - 1 < 0 && lie + 1 <= n - 1) {
            PaiShangChuJie(zu, n - 1, lie, zu[hang][lie]);
            hang = n - 1;
            lie++;
        } else if (hang == 0 && lie == n - 1) {
            PaiZhanWei(zu, hang, lie, zu[hang][lie]);
            hang++;
        } else if (hang - 1 >= 0 && lie + 1 > n - 1) {
            PaiYouChuJie(zu, hang, zu[hang][lie]);
            hang--;
            lie = 0;
        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", zu[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void PaiShangChuJie(int zu[][LEN], int hangzong, int lie, int n) {
    zu[hangzong][lie + 1] = n + 1;
}

void PaiZhanWei(int zu[][LEN], int hang, int lie, int n) {
    zu[hang + 1][lie] = n + 1;
}

void PaiYouChuJie(int zu[][LEN], int hang, int n) {
    zu[hang - 1][0] = n + 1;
}
