#ifndef QUICKSORT_H
#define QUICKSORT_H

void swap(int* p1, int* p2);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);

#endif // QUICKSORT_H
