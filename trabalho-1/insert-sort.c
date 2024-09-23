#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#include "insert-sort.h"

int* insertSort(int array[], int arraySize) {
    int* arrayToSort = (int*) malloc(arraySize * sizeof(int));
    
    int i, j;

    for(i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    if(arraySize == 1) {
        return arrayToSort;
    }

    for(i = 1; i < arraySize; i++) {
        int currentItem = arrayToSort[i];
        j = i - 1;

        while(j >= 0 && arrayToSort[j] > currentItem) {
            arrayToSort[j + 1] = arrayToSort[j];
            j--;
        }

        arrayToSort[j + 1] = currentItem;
    }

    return arrayToSort;
}
