#include <string.h>
#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {20, 10, 50};
    int arr3[] = {45, 88, 99};
    int *ptrr[] = {arr1, arr2, arr3};
    printf("%d", *(ptrr[0]));
    return 0;
}