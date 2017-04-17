#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorting.h"

void CopyMem(void *dest, void *src, size_t length) {
  size_t i;
  char *p=dest, *q=src;
  if (p!=q) {
    for (i=0; i<length; i++) {
      p[i]=q[i];
    }
  }
}

void Swap(void *a, void *b, size_t length) {
  void *tmp=(void *)malloc(length);
  CopyMem(tmp, a, length);
  CopyMem(a, b, length);
  CopyMem(b, tmp, length);
}

void BubbleSort(void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b)) {
  size_t i, j;
  int flag;
  for(i=0, flag=1; i<n_data && flag==1; i++) {
    flag=0;
    for (j=0; j<(n_data-i-1); j++) {
      if (cmp((arr+(j*data_size)),(arr+((j+1)*data_size)))>0) {
        flag=1;
        Swap(arr+(j*data_size), arr+((j+1)*data_size), data_size);
      }
    }
  }
  return;
}

void SelectionSort(void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b)) {
  size_t i, j, min;
  for(i=0; i<n_data; i++) {
    min=i;
  	for (j=(i+1); j<n_data; j++) {
      if (cmp((arr+(j*data_size)),(arr+(min*data_size)))<0) {
        min=j;
      }
    }
    Swap(arr+(i*data_size), arr+(min*data_size), data_size);
  }
  return;
}

void InsertionSort(void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b)) {
  size_t i, j;
  void *x=(void *)malloc(data_size);
  for (i=1; i<n_data; i++) {
    CopyMem(x, (arr+(i*data_size)), data_size);
    j=(i-1);
    while ((j>=0) && (cmp(x,(arr+(j*data_size)))<0)) {
      CopyMem((arr+((j+1)*data_size)), (arr+(j*data_size)), data_size);
      j--;
    }
    CopyMem((arr+((j+1)*data_size)), x, data_size);
  }
}

void ShellSort(void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b)) {
  size_t i, j, h=1;
  void *tmp=(void *)malloc(data_size);
  while (h<(n_data/3)) {
    h=((3*h)+1);
  }
  while(h>=1) {
    for (i=h; i<n_data; i++) {
      j=i;
      CopyMem(tmp, (arr+(j*data_size)), data_size);
      while ((j>=h) && (cmp(tmp,(arr+((j-h)*data_size)))<0)) {
        CopyMem((arr+((j)*data_size)), (arr+((j-h)*data_size)), data_size);
        j-=h;
      }
      CopyMem((arr+(j*data_size)), tmp, data_size);
    }
    h=(h/3);
  }
}

void CountingSort(int *arr, int n_data, int max_data) {
  size_t i, k=max_data+1;
  int *occ, *out;
  occ=(int*)calloc(k, sizeof(*occ));
  out=(int*)malloc(n_data*sizeof(*out));
  for (i=0; i<n_data; i++) {
    occ[arr[i]]++;
  }
  for (i=1; i<k; i++) {
    occ[i]+=occ[i-1];
  }
  for (i=(n_data-1); i>=1; i--) {
    out[occ[arr[i]]-1]=arr[i];
    occ[arr[i]]--;
  }
  for (i=0; i<n_data; i++) {
    arr[i]=out[i];
  }
}

void Merge(void *arr, void *out, size_t l, size_t q, size_t r, size_t data_size, int (*cmp)(const void *a, const void *b)) {
  size_t i, j, k;
  i=l;
  j=q+1;
  for(k=l; k<=r; k++) {
    if (i>q) {
      CopyMem((out+(k*data_size)), (arr+((j++)*data_size)), data_size);
    } else if (j>r)  {
      CopyMem((out+(k*data_size)), (arr+((i++)*data_size)), data_size);
    } else if (cmp((arr+(i*data_size)),(arr+(j*data_size)))<=0) {
      CopyMem((out+(k*data_size)), (arr+((i++)*data_size)), data_size);
    } else {
      CopyMem((out+(k*data_size)), (arr+((j++)*data_size)), data_size);
    }
  }
  for (k=0; k<=r; k++) {
    CopyMem((arr+(k*data_size)), (out+(k*data_size)), data_size);
  }
  return;
}

void MergeSortR(void *arr, void *out, size_t l, size_t r, size_t data_size, int (*cmp)(const void *a, const void *b)) {
  size_t q;
  if (r<=l) {
    return;
  }
  q=(l+r)/2;
  MergeSortR(arr, out, l, q, data_size, cmp);
  MergeSortR(arr, out, q+1, r, data_size, cmp);
  Merge(arr, out, l, q, r, data_size, cmp);
}

void MergeSort(void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b)) {
  void *out=(void*)malloc(n_data*sizeof(*out));
  MergeSortR(arr, out, 0, n_data-1, data_size, cmp);
}

size_t HoarePartition(void *arr, size_t l, size_t r, size_t data_size, int (*cmp)(const void *a, const void *b)) {
  size_t i, j;
  i=l;
  j=r+1;
  while (1) {
    while (cmp((arr+(++i*data_size)), (arr+(l*data_size)))<0) {
      if (i==r) {
        break;
      }
    }
    while (cmp((arr+(l*data_size)), (arr+(--j*data_size)))<0) {
      if (j==l) {
        break;
      }
    }
    if (i>=j) {
      break;
    }
    Swap((arr+(i*data_size)), (arr+(j*data_size)), data_size);
  }
  Swap((arr+(l*data_size)), (arr+(j*data_size)), data_size);
  return(j);
}

void QuickSortR(void *arr, size_t l, size_t r, size_t data_size, int (*cmp)(const void *a, const void *b)) {
  size_t q;
  if (r<=l) {
    return;
  }
  q=HoarePartition(arr, l, r, data_size, cmp);
  QuickSortR(arr, l, q-1, data_size, cmp);
  QuickSortR(arr, q+1, r, data_size, cmp);
  return;
}

void QuickSort(void *arr, size_t n_data, size_t data_size, int (*cmp)(const void *a, const void *b)) {
  QuickSortR(arr, 0, n_data-1, data_size, cmp);
}
