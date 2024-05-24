#include <stdio.h>
#include "quicksort.h"

int main() {
    int arr[] = {100, 72, 8, 69, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
