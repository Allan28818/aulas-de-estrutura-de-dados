#include <stdio.h>
#include <stdlib.h>

#include "heap-sort.h"

void heapify(int arrayToSort[], int arraySize, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < arraySize && arrayToSort[left] > arrayToSort[largest])
        largest = left;

    if (right < arraySize && arrayToSort[right] > arrayToSort[largest])
        largest = right;

    if (largest != i) {
        int temp = arrayToSort[i];
        arrayToSort[i] = arrayToSort[largest];
        arrayToSort[largest] = temp;

        heapify(arrayToSort, arraySize, largest);
    }
}

int* heapSort(int array[], int arraySize) {
    int* arrayToSort = (int*) malloc(arraySize * sizeof(int));
    int i;

    for (i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    if (arraySize == 1) {
        return arrayToSort;
    }

    for (i = arraySize / 2 - 1; i >= 0; i--) {
        heapify(arrayToSort, arraySize, i);
    }

    for (i = arraySize - 1; i >= 0; i--) {
        int temp = arrayToSort[0];
        arrayToSort[0] = arrayToSort[i];
        arrayToSort[i] = temp;

        heapify(arrayToSort, i, 0);
    }

    return arrayToSort;
}
