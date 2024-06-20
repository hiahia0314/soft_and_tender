//
// Created by 23125 on 2023/10/29.
//
#include <stdio.h>
#include <math.h>

#define LEN 10000
int zu1[LEN] = {0};
int zu2[LEN] = {0};

int Erfen(int arr[], int zu0, int length, int t);

int main() {

    int i, j, t;
    scanf("%d%d%d", &i, &j, &t);
    for (int a = 0; a < i; a++) {
        scanf("%d", &zu1[a]);
    }
    for (int b = 0; b < j; ++b) {
        scanf("%d", &zu2[b]);
    }
    int min = t + 1;
    for (int k = 0; k < j; ++k) {
        if (min > Erfen(zu1, t - zu2[k], i, t)) {
            min = Erfen(zu1, t - zu2[k], i, t);
        }
    }
    if (min == t + 1) {
        printf("-1");
    } else {
        printf("%d", min);

    }
    return 0;

}

int Erfen(int arr[], int zu0, int length, int t) {
    int low = 0;
    int high = length - 1;
    int mid = (low + high) / 2;
    for (int i = 0; pow(2, i) < length; ++i) {
        if (zu0 - arr[mid] < 0) {
            high = mid - 1;
            mid = (low + high) / 2;
        } else if (zu0 - arr[mid] == 0) {
            break;
        } else {
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }
    if (zu0 - arr[mid] < 0) {
        return t + 1;
    }
    return (zu0 - arr[mid]);
}



