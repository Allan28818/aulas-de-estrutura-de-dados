#include <stdio.h>
#include <stdlib.h>

#include "merge-sort.h"

void merge(int arrayToSort[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArray = (int*) malloc(n1 * sizeof(int));
    int* rightArray = (int*) malloc(n2 * sizeof(int));

    for(i = 0; i < n1; i++)
        leftArray[i] = arrayToSort[left + i];        
    for(j = 0; j < n2; j++)
        rightArray[j] = arrayToSort[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2) {
        if(leftArray[i] <= rightArray[j]) {
            arrayToSort[k] = leftArray[i];
            i++;
        } else {
            arrayToSort[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arrayToSort[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < n2) {
        arrayToSort[k] = rightArray[j];
        j++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}

void recursiveMergeSort(int arrayToSort[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        recursiveMergeSort(arrayToSort, left, mid);
        recursiveMergeSort(arrayToSort, mid + 1, right);
        merge(arrayToSort, left, mid, right);
    }
}

int* mergeSort(int array[], int arraySize) {
    int* arrayToSort = (int*) malloc(arraySize * sizeof(int));

    for(int i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    if(arraySize > 1) {
        recursiveMergeSort(arrayToSort, 0, arraySize - 1);
    }

    return arrayToSort;
}
