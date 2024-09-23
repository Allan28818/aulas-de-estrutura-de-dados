#include <stdio.h>
#include <stdlib.h>

#include "select-sort.h"

int* selectSort(int array[], int arraySize, enum SortOrder sortOrder) {
  int* arrayToSort = (int*) malloc(arraySize * sizeof(int));
  
  int itemsToIterate = arraySize - 1;  
  
  int i;

  for(i=0; i<arraySize; i++) {
    arrayToSort[i] = array[i];
  }

  if(arraySize == 1) {
    return arrayToSort;
  }

  if(sortOrder != ASC && sortOrder != DESC) {
    printf("Metodo de ordenacao invalido!\n");
    return arrayToSort;
  }  

  for (int i = 0; i < itemsToIterate; i++) {
    int selectedIndex = i;
    
    for (int j = i + 1; j < arraySize; j++) {
      if (sortOrder == ASC) {            
        if (arrayToSort[j] < arrayToSort[selectedIndex]) {
            selectedIndex = j;
        }
      } else {              
        if (arrayToSort[j] > arrayToSort[selectedIndex]) {
            selectedIndex = j;
        }
      }
    }
    
    if (selectedIndex != i) {
      int temp = arrayToSort[i];
      arrayToSort[i] = arrayToSort[selectedIndex];
      arrayToSort[selectedIndex] = temp;
    }              
  }

  return arrayToSort;
}