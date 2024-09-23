#include <stdio.h>
#include <stdlib.h>

#include "quick-sort.h"

int partition(int arrayToSort[], int low, int high) {
    int pivot = arrayToSort[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arrayToSort[j] <= pivot) {
            i++;
            int temp = arrayToSort[i];
            arrayToSort[i] = arrayToSort[j];
            arrayToSort[j] = temp;
        }
    }

    int temp = arrayToSort[i + 1];
    arrayToSort[i + 1] = arrayToSort[high];
    arrayToSort[high] = temp;

    return i + 1;
}

void recursiveQuickSort(int arrayToSort[], int low, int high) {
    if(low < high) {
        int pi = partition(arrayToSort, low, high);

        recursiveQuickSort(arrayToSort, low, pi - 1);
        recursiveQuickSort(arrayToSort, pi + 1, high);
    }
}

int* quickSort(int array[], int arraySize) {
    int* arrayToSort = (int*) malloc(arraySize * sizeof(int));

    for(int i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    if(arraySize > 1) {
        recursiveQuickSort(arrayToSort, 0, arraySize - 1);
    }

    return arrayToSort;
}
