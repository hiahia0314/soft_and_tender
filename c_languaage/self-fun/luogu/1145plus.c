#include <stdio.h>

int check(int m, int k);

int main() {
    int k = 3;
    scanf("%d", &k);
    int m;
    for (m = k;; m++) {
        if (check(m, k) == 1) {
            printf("%d", m);
            break;
        }
    }
    return 0;
}

int check(int m, int k) {
    int pos = 0;
    int live[100] = {0};
    for (int i = 0; i < k; ++i) {
        int n = m % (2 * k - i);//n代替了m m/(2k-i)就是兜的圈数，无用
        if (m >= 2 * k - i) {
            n += 2 * k - i;//后期m比剩余人大很多，多加一圈，起码得把剩余人的live状态遍历吧，1.n圈==k.n圈！=0.n圈
        }
        for (int j = 0; j < n; j++) {
            pos++;
            if (pos == 2 * k + 1) {
                pos = 1;
            }
            if (live[pos] == 1) {
                j--;
            }

        }
        if (pos <= k) {
            return -1;
        }
        live[pos] = 1;
    }

    return 1;

}