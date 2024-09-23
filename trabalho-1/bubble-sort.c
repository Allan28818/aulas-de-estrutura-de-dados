#include <stdio.h>
#include <stdlib.h>

#include "bubble-sort.h"

int* bubbleSort(int array[], int arraySize) {
  int* arrayToSort = (int*) malloc(arraySize * sizeof(int));
  

  int itemsToIterate = arraySize - 1;
  
  int i, j;  

  for(i=0; i<arraySize; i++) {
    arrayToSort[i] = array[i];
  }


  if(arraySize == 1) {
    return arrayToSort;
  }  

  for(i=0; i<itemsToIterate; i++) {    
    int noSwaps = 1;
    for(j=0; j< (itemsToIterate - i); j++) {           
      int nextIndex = j + 1;
      int currentItem = arrayToSort[j];
      int nextItem = arrayToSort[nextIndex];
   
      if(currentItem > nextItem) {       

        arrayToSort[j] = arrayToSort[nextIndex];
        arrayToSort[nextIndex] = currentItem;

        noSwaps = 0;
      } 
    }

    if(noSwaps == 1) {
      return arrayToSort;
    }
  }

  return arrayToSort;
}