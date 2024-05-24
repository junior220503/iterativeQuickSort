//SC 3037347 FELIPE CORSI
//SC 3037649 FABIANO JUNIOR
//SC 3037851 GABRIEL HENRIQUE

/*A declaração está correta ao dizer que a versão iterativa do Quicksort, ao adotar uma política inteligente 
de gerenciamento das partições, oferece uma vantagem significativa ao controlar o tamanho da pilha de 
execução, mantendo-a na ordem de O(log(n)). Essa abordagem melhora a eficiência do algoritmo e evita 
problemas de estouro da pilha, que podem ocorrer na implementação recursiva. Porém isso só acontece quando 
uma política inteligente de gerenciamento das partições é adotada, podendo ser considerado mais complexo do 
que a forma recursiva.*/

#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

void swap(int* p1, int* p2) {
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int partition(int arr[], int low, int high) {
    int holder = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < holder) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    int* stack = (int*) malloc(sizeof(int) * (high - low + 1));
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int holder = partition(arr, low, high);

        if (holder - 1 > low) {
            stack[++top] = low;
            stack[++top] = holder - 1;
        }

        if (holder + 1 < high) {
            stack[++top] = holder + 1;
            stack[++top] = high;
        }
    }
   
    free(stack);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
