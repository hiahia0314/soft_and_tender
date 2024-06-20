#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int t, d1, d2, size;
    char s1[100] = {0};
    char s2[100] = {0};
    char s[200] = {0};
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++) {
        for (int a = 0;; a++) {
            char ch;
            ch = getchar();
            if (ch == ';') {
                break;
            } else {
                s1[a] = ch;
            }
        }
        for (int a = 0;; a++) {
            char ch;
            ch = getchar();
            if (ch == ';') {
                break;
            } else {
                s2[a] = ch;
            }
        }
        scanf("%d;%d;%d", &d1, &d2, &size);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int k = 0, p = 0, q = 0, r = 0;
        do {
            if (len1 - d1 >= 0) {
                for (; k < r + d1; k++) {
                    if (k == size - 1) {
                        break;
                    }
                    s[k] = s1[p];
                    p++;
                }
                len1 -= d1;
            } else {
                for (int m = strlen(s1) - len1; m < strlen(s1); m++) {
                    if (k == size - 1) {
                        break;
                    }
                    s[k] = s1[m];
                    k++;
                }
                for (int n = strlen(s2) - len2; n < strlen(s2); n++) {
                    if (k == size - 1) {
                        break;
                    }
                    s[k] = s2[n];
                    k++;
                }
                //break;
            }
            //k++;
            r = k;
            if (len2 - d2 >= 0) {
                for (; k < r + d2; k++) {
                    if (k == size - 1) {
                        break;
                    }
                    s[k] = s2[q];
                    q++;
                }
                len2 -= d2;
            } else {
                for (int m = strlen(s2) - len2; m < strlen(s2); m++) {
                    if (k == size - 1) {
                        break;
                    }
                    s[k] = s2[m];
                    k++;
                }
                for (int n = strlen(s1) - len1; n < strlen(s1); n++) {
                    if (k == size - 1) {
                        break;
                    }
                    s[k] = s1[n];
                    k++;
                }
                break;
            }
            //k++;
            r = k;
            if (k == size - 1) {
                //break;
            }
        } while (k < size && len1 > 0 && len2 > 0);
        printf("%s\n", s);
    }
}
