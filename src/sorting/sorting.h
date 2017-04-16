#ifndef SORTING_H
#define SORTING_H

#include "sorting_item.h"

void  BubbleSort      (void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b));
void  SelectionSort   (SortingItem *A, int l, int r);
void  InsertionSort   (SortingItem *A, int l, int r);
void  ShellSort       (SortingItem *A, int l, int r);
void  CountingSort    (SortingItem *A, int l, int r, int k);
void  MergeSort       (SortingItem *A, int l, int r);
void  QuickSort       (SortingItem *A, int l, int r);

#endif
