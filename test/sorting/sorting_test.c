#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#include "../../src/sorting/sorting.h"

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
  SortingItem *input=(SortingItem*)malloc(n*sizeof(*input));
  for (i=0; i<n; i++) {
    input[i]=SORTINGitemScan(fp_test);
  }

  SortingItem *bubble_sort=(SortingItem*)malloc(n*sizeof(*input));
  for (i=0; i<n; i++) {
    bubble_sort[i]=input[i];
  }
  printf("BubbleSort array input\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(bubble_sort[i], stdout);
    printf("\n");
  }
  BubbleSort(bubble_sort, 0, n-1);
  printf("BubbleSort array sorted\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(bubble_sort[i], stdout);
    printf("\n");
  }

  SortingItem *selection_sort=(SortingItem*)malloc(n*sizeof(*input));
  for (i=0; i<n; i++) {
    selection_sort[i]=input[i];
  }
  printf("SelectionSort array input\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(selection_sort[i], stdout);
    printf("\n");
  }
  SelectionSort(selection_sort, 0, n-1);
  printf("SelectionSort array sorted\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(selection_sort[i], stdout);
    printf("\n");
  }

  SortingItem *insertion_sort=(SortingItem*)malloc(n*sizeof(*input));
  for (i=0; i<n; i++) {
    insertion_sort[i]=input[i];
  }
  printf("InsertionSort array input\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(insertion_sort[i], stdout);
    printf("\n");
  }
  InsertionSort(insertion_sort, 0, n-1);
  printf("InsertionSort array sorted\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(insertion_sort[i], stdout);
    printf("\n");
  }

  SortingItem *shell_sort=(SortingItem*)malloc(n*sizeof(*input));
  for (i=0; i<n; i++) {
    shell_sort[i]=input[i];
  }
  printf("ShellSort array input\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(shell_sort[i], stdout);
    printf("\n");
  }
  ShellSort(shell_sort, 0, n-1);
  printf("ShellSort array sorted\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(shell_sort[i], stdout);
    printf("\n");
  }

  SortingItem *counting_sort=(SortingItem*)malloc(n*sizeof(*input));
  for (i=0; i<n; i++) {
    counting_sort[i]=input[i];
  }
  printf("CountingSort array input\n");
  int max=INT_MIN;
  for (i=0; i<n; i++) {
    SORTINGitemShow(counting_sort[i], stdout);
    printf("\n");
    if (SORTINGkeyGet(counting_sort[i])>max) {
      max=SORTINGkeyGet(counting_sort[i]);
    }
  }
  CountingSort(counting_sort, 0, n-1, max+1);
  printf("CountingSort array sorted\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(counting_sort[i], stdout);
    printf("\n");
  }

  SortingItem *merge_sort=(SortingItem*)malloc(n*sizeof(*input));
  for (i=0; i<n; i++) {
    merge_sort[i]=input[i];
  }
  printf("MergeSort array input\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(merge_sort[i], stdout);
    printf("\n");
  }
  MergeSort(merge_sort, 0, n-1);
  printf("MergeSort array sorted\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(merge_sort[i], stdout);
    printf("\n");
  }

  SortingItem *quick_sort=(SortingItem*)malloc(n*sizeof(*input));
  for (i=0; i<n; i++) {
    quick_sort[i]=input[i];
  }
  printf("QuickSort array input\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(quick_sort[i], stdout);
    printf("\n");
  }
  QuickSort(quick_sort, 0, n-1);
  printf("QuickSort array sorted\n");
  for (i=0; i<n; i++) {
    SORTINGitemShow(quick_sort[i], stdout);
    printf("\n");
  }

  return(0);
}
