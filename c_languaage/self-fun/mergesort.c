#include <stdio.h>

#define LEN 100
int grade[LEN] = {0};
int copy[LEN] = {0};

void mergesort(int grade[LEN], int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) >> 1;
    mergesort(grade, l, mid);
    mergesort(grade, mid + 1, r);
    int left = l, right = mid + 1, cnt = l;
    while (left <= mid && right <= r) {
        if (grade[left] <= grade[right]) {
            copy[cnt] = grade[left];
            cnt++;
            left++;
        } else {
            copy[cnt] = grade[right];
            cnt++;
            right++;
        }
    }
    while (left <= mid) {
        copy[cnt++] = grade[left++];
    }
    while (right <= r) {
        copy[cnt++] = grade[right++];
    }
    for (int i = l; i <= r; ++i) {
        grade[i] = copy[i];
    }

}


int main() {
    int N, K;
    int ans = 0;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &grade[i]);
    }
    mergesort(grade, 0, N - 1);
    int delta[LEN] = {0};
    for (int i = 0; i < N - 1; ++i) {
        delta[i] = grade[i + 1] - grade[i];
    }
    mergesort(delta, 0, N - 2);
    for (int i = 0; i < K; ++i) {
        ans += delta[i];
    }
    printf("%d", ans);


    return 0;
}