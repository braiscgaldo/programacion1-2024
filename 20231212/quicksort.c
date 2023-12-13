//
// Created by brais on 12/12/2023.
//

#include <stdio.h>

void intercambiar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particion(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            intercambiar(&array[i], &array[j]);
        }
    }
    intercambiar(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pi = particion(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void imprimirArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int data[] = {8, 7, 6, 1, 0, 9, 2};
    int n = sizeof(data) / sizeof(data[0]);
    quickSort(data, 0, n - 1);
    printf("Array ordenado con quicksort: \n");
    imprimirArray(data, n);
}