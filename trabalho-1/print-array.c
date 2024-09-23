#include <stdio.h>

#include "print-array.h"

void printArray(void* array, int size, enum Type type) {
  int i;  
  for(i=0; i<size; i++) {
    if(i == 0) {
      printf("{");
    } 

    printf(" ");

    switch (type)
    {
    case INT:
      printf("%d", ((int*)array)[i]);
      break;
    case FLOAT:
      printf("%f", ((float*)array)[i]);
      break;
    case DOUBLE:
      printf("%lf", ((double*)array)[i]);
      break;
    case CHAR:
      printf("%c", ((char*)array)[i]);
      break;
    default:
      printf("Tipo de dado invalido!\n");
      break;
    }

    if(i == (size - 1)) {
      printf(" }\n");
    } else {
      printf(",");
    }
  }
}