#include <stdio.h>
#include <stdlib.h>

#include "shell-sort.h"

int* shellSort(int array[], int arraySize) {
    int* arrayToSort = (int*) malloc(arraySize * sizeof(int));
    int i, j;

    for (i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    if (arraySize == 1) {
        return arrayToSort;
    }

    int gap = arraySize / 2;

    while (gap > 0) {
        for (i = gap; i < arraySize; i++) {
            int currentItem = arrayToSort[i];
            j = i;

            while (j >= gap && arrayToSort[j - gap] > currentItem) {
                arrayToSort[j] = arrayToSort[j - gap];
                j -= gap;
            }

            arrayToSort[j] = currentItem;
        }
        gap /= 2;
    }

    return arrayToSort;
}
