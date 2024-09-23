#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubble-sort.h"
#include "select-sort.h"
#include "insert-sort.h"
#include "merge-sort.h"
#include "quick-sort.h"
#include "heap-sort.h"
#include "shell-sort.h"

#include "print-array.h"

#define ARRAY_SIZE 6

int main() {
  int randomArray[ARRAY_SIZE];

  srand(time(NULL));
  
  int min = 0;
  int max = 1000;
  
  int i;

  for(i=0; i < ARRAY_SIZE; i++) {
    randomArray[i] = min + rand() % (max - min) + 1;
  }
  
  printf("Original array ");
  printArray(randomArray, ARRAY_SIZE, INT);
  

  int* arrayFromBubbleSort = bubbleSort(randomArray, ARRAY_SIZE);
  int* arrayFromSelectSort = selectSort(randomArray, ARRAY_SIZE, ASC);
  int* arrayFromInsertSort = insertSort(randomArray, ARRAY_SIZE);
  int* arrayFromMergeSort = mergeSort(randomArray, ARRAY_SIZE);
  int* arrayFromQuickSort = quickSort(randomArray, ARRAY_SIZE);
  int* arrayFromHeapSort = heapSort(randomArray, ARRAY_SIZE);
  int* arrayFromShellSort = shellSort(randomArray, ARRAY_SIZE);

  printf("Bubble sort ");
  printArray(arrayFromBubbleSort, ARRAY_SIZE, INT);

  printf("Select sort ");
  printArray(arrayFromSelectSort, ARRAY_SIZE, INT);

  printf("Insert sort ");
  printArray(arrayFromInsertSort, ARRAY_SIZE, INT);
  
  printf("Merge sort ");
  printArray(arrayFromMergeSort, ARRAY_SIZE, INT);
  
  printf("Quick sort ");
  printArray(arrayFromQuickSort, ARRAY_SIZE, INT);
  
  printf("Heap sort ");
  printArray(arrayFromHeapSort, ARRAY_SIZE, INT);
  
  printf("Shell sort ");
  printArray(arrayFromShellSort, ARRAY_SIZE, INT);
  
  free(arrayFromBubbleSort);
  free(arrayFromSelectSort);
  free(arrayFromInsertSort);
  free(arrayFromMergeSort);
  free(arrayFromQuickSort);
  free(arrayFromHeapSort);
  free(arrayFromShellSort);

  return 0;
}