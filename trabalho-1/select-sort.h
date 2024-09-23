#ifndef SELECT_SORT
#define SELECT_SORT
enum SortOrder { ASC, DESC };

int* selectSort(int array[], int arraySize, enum SortOrder sortOrder);
#endif