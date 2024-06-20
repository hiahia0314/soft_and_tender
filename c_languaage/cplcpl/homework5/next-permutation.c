//
// Created by 23125 on 2023/10/28.
//

#include <stdio.h>

int FindHouZhui(int arr[], int n);

int FindBigger(int arr[], int index, int n);

int main() {
    int index, indexbb, n = 0;
    int arr[50] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    index = FindHouZhui(arr, n);  //找到后缀的起始编号
    indexbb = FindBigger(arr, index, n);
    int tem = arr[index - 1];
    arr[index - 1] = arr[indexbb];
    arr[indexbb] = tem;
    for (int i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }
    for (int i = n - 1; i >= index; i--) {
        printf("%d ", arr[i]);
    }
    //printf("%d", indexbb);
    return 0;
}

int FindHouZhui(int arr[], int n) {
    int count = 0;
    for (int j = 0; j < n; j++) {
        for (int i = j; i < n; i++) {
            if (arr[i] > arr[i + 1]) {
                count++;
            }
        }
        if (count == n - j) {
            return j;
        } else {
            count = 0;
        }
    }
}

int FindBigger(int arr[], int index, int n) {
    for (int j = n - 1; j >= index; j--) {
        if (arr[j] > arr[index - 1]) {
            return j;
        }
    }
}
