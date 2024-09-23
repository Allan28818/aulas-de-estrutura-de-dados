#ifndef PRINT_ARRAY
#define PRINT_ARRAY
enum Type { INT, FLOAT, DOUBLE, CHAR };

void printArray(void* array, int size, enum Type type);
#endif