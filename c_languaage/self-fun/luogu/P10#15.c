#include <stdio.h>

#define LEN 5002

int main() {
    long long int people[LEN] = {0};
    long long int stack[LEN] = {0};
    int n;
    long long int zhan = 1;
    int count = 0;
    scanf("%d", &n);
    count = n - 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &people[i]);
    }
    stack[1] = people[1];
    for (int i = 1; i <= n; ++i) {
        if (people[i] >= stack[zhan]) {
            for (int j = zhan; j >= 1; --j) {

                if (people[i] < stack[j]) {
                    zhan++;
                    break;
                }

                stack[j] = people[i];
                zhan--;
                if (zhan >= 1) {
                    count++;
                }
                if (zhan == 0) {
                    zhan = 1;
                }


            }
        } else {
            zhan++;
            stack[zhan] = people[i];
        }


    }
    printf("%d", count);
    return 0;
}