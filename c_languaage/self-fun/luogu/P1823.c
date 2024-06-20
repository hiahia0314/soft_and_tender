#include <stdio.h>

long long st[10000], n, top = 1, ans, m;

int main() {
    scanf("%lld", &n);
    long long int a;
    scanf("%lld", &st[1]);
    for (int i = 2; i <= n; ++i) {
        scanf("%lld", &a);
        if (st[top] > a) {
            top++;
            ans++;
            st[top] = a;
        } else {
            long long int l = 1, r = top;
            while (l < r) {
                m = (l + r) >> 1;
                if (r == l + 1) {
                    m = r;
                }
                if (a >= st[m]) {
                    r = m - 1;
                } else {
                    l = m;
                }
            }
            ans += top - l + 1;
            while (top > 0 && st[top] < a) {
                top--;
            }
            st[++top] = a;

        }
    }
    printf("%lld", ans);

}