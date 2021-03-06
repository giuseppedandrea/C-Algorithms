#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>

void  BubbleSort      (void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b));
void  SelectionSort   (void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b));
void  InsertionSort   (void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b));
void  ShellSort       (void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b));
void  CountingSort    (int *arr, size_t n_data, size_t max_data);
void  MergeSort       (void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b));
void  QuickSort       (void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b));

#endif
