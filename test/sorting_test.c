#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#include "../../src/sorting/sorting.h"

int cmp(const void *a, const void *b) {
   return((*(int*)a)-(*(int*)b));
}

int main(int argc, char const *argv[]) {
  int i, n;
  FILE *fp_test;

  if (argc!=2) {
    printf("Arguments error!\n");
    printf("Usage: %s <input_file>\n", argv[0]);
    return(EXIT_FAILURE);
  }

  fp_test=fopen(argv[1], "r");

  if (fp_test==NULL) {
    printf("Failed to open file \"%s\"\n", argv[1]);
    return(EXIT_FAILURE);
  }

  fscanf(fp_test, "%d", &n);
  int *input=(int*)malloc(n*sizeof(*input));
  for (i=0; i<n; i++) {
    fscanf(fp_test, "%d", &input[i]);
  }

  int *bubble_sort=(int*)malloc(n*sizeof(*bubble_sort));
  for (i=0; i<n; i++) {
    bubble_sort[i]=input[i];
  }
  printf("BubbleSort array input\n");
  for (i=0; i<n; i++) {
    printf("%d ", bubble_sort[i]);
  }
  printf("\n");
  BubbleSort(bubble_sort, n, sizeof(int), cmp);
  printf("BubbleSort array sorted\n");
  for (i=0; i<n; i++) {
    printf("%d ", bubble_sort[i]);
  }
  printf("\n");

  int *selection_sort=(int*)malloc(n*sizeof(*selection_sort));
  for (i=0; i<n; i++) {
    selection_sort[i]=input[i];
  }
  printf("SelectionSort array input\n");
  for (i=0; i<n; i++) {
    printf("%d ", selection_sort[i]);
  }
  printf("\n");
  SelectionSort(selection_sort, n, sizeof(int), cmp);
  printf("SelectionSort array sorted\n");
  for (i=0; i<n; i++) {
    printf("%d ", selection_sort[i]);
  }
  printf("\n");

  int *insertion_sort=(int*)malloc(n*sizeof(*insertion_sort));
  for (i=0; i<n; i++) {
    insertion_sort[i]=input[i];
  }
  printf("InsertionSort array input\n");
  for (i=0; i<n; i++) {
    printf("%d ", insertion_sort[i]);
  }
  printf("\n");
  InsertionSort(insertion_sort, n, sizeof(int), cmp);
  printf("InsertionSort array sorted\n");
  for (i=0; i<n; i++) {
    printf("%d ", insertion_sort[i]);
  }
  printf("\n");

  int *shell_sort=(int*)malloc(n*sizeof(*shell_sort));
  for (i=0; i<n; i++) {
    shell_sort[i]=input[i];
  }
  printf("ShellSort array input\n");
  for (i=0; i<n; i++) {
    printf("%d ", shell_sort[i]);
  }
  printf("\n");
  ShellSort(shell_sort, n, sizeof(int), cmp);
  printf("ShellSort array sorted\n");
  for (i=0; i<n; i++) {
    printf("%d ", shell_sort[i]);
  }
  printf("\n");

  int *counting_sort=(int*)malloc(n*sizeof(*counting_sort));
  for (i=0; i<n; i++) {
    counting_sort[i]=input[i];
  }
  printf("CountingSort array input\n");
  int max=INT_MIN;
  for (i=0; i<n; i++) {
    printf("%d ", counting_sort[i]);
    if (counting_sort[i]>max) {
      max=counting_sort[i];
    }
  }
  printf("\n");
  CountingSort(counting_sort, n, max);
  printf("CountingSort array sorted\n");
  for (i=0; i<n; i++) {
    printf("%d ", counting_sort[i]);
  }
  printf("\n");

  int *merge_sort=(int*)malloc(n*sizeof(*merge_sort));
  for (i=0; i<n; i++) {
    merge_sort[i]=input[i];
  }
  printf("MergeSort array input\n");
  for (i=0; i<n; i++) {
    printf("%d ", merge_sort[i]);
  }
  printf("\n");
  MergeSort(merge_sort, n, sizeof(int), cmp);
  printf("MergeSort array sorted\n");
  for (i=0; i<n; i++) {
    printf("%d ", merge_sort[i]);
  }
  printf("\n");

  int *quick_sort=(int*)malloc(n*sizeof(*quick_sort));
  for (i=0; i<n; i++) {
    quick_sort[i]=input[i];
  }
  printf("QuickSort array input\n");
  for (i=0; i<n; i++) {
    printf("%d ", quick_sort[i]);
  }
  printf("\n");
  QuickSort(quick_sort, n, sizeof(int), cmp);
  printf("QuickSort array sorted\n");
  for (i=0; i<n; i++) {
    printf("%d ", quick_sort[i]);
  }
  printf("\n");

  return(0);
}
