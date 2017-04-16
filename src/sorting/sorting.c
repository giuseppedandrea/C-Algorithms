#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorting.h"

void Swap(void *a, void *b, size_t length) {
  size_t i;
  char *p=a, *q=b, tmp;
  if (p!=q) {
    for (i=0; i<length; i++) {
      tmp=p[i];
      p[i]=q[i];
      q[i]=tmp;
    }
  }
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

void SelectionSort(SortingItem *A, int l, int r) {
  int i, j, min;
  SortingItem temp;
  for(i=l; i<r; i++) {
    min=i;
  	for (j=(i+1); j<=r; j++) {
      if (SORTINGitemLess(A[j],A[min])){
        min=j;
      }
    }
    temp=A[i];
    A[i]=A[min];
    A[min]=temp;
  }
  return;
}

void InsertionSort(SortingItem *A, int l, int r) {
  int i, j;
  SortingItem x;
  for (i=(l+1); i<=r; i++) {
    x=A[i];
    j=(i-1);
    while (j>=l && SORTINGitemLess(x, A[j])) {
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=x;
  }
}

void ShellSort(SortingItem *A, int l, int r) {
  int i, j, h=1, n=(r-l+1);
  SortingItem tmp;
  while (h<(n/3)) {
    h=((3*h)+1);
  }
  while(h>=1) {
    for (i=(l+h); i<=r; i++) {
      j=i;
      tmp=A[i];
      while(j>=(l+h) && SORTINGitemLess(tmp, A[j-h])) {
        A[j]=A[j-h];
        j-=h;
      }
      A[j]=tmp;
    }
    h=(h/3);
  }
}

void CountingSort(SortingItem *A, int l, int r, int k) {
  int i, n, *C;
  SortingItem *B;
  n=(r-l+1);
  B=(SortingItem*)malloc(n*sizeof(SortingItem));
  C=(int*)malloc(k*sizeof(int));
  for (i=0; i<k; i++) {
    C[i]=0;
  }
  for (i=l; i<=r; i++) {
    C[SORTINGkeyGet(A[i])]++;
  }
  for (i=1; i<k; i++) {
    C[i]+=C[i-1];
  }
  for (i=r; i>=l; i--) {
    B[C[SORTINGkeyGet(A[i])]-1]=A[i];
    C[SORTINGkeyGet(A[i])]--;
  }
  for (i=l; i<=r; i++) {
    A[i]=B[i];
  }
}

void Merge(SortingItem *A, SortingItem *B, int l, int q, int r) {
  int i, j, k;
  i=l;
  j=q+1;
  for(k=l; k<=r; k++) {
    if (i>q) {
      B[k]=A[j++];
    } else if (j>r)  {
      B[k]=A[i++];
    } else if (SORTINGitemLessEqual(A[i], A[j])) {
      B[k]=A[i++];
    } else {
      B[k]=A[j++];
    }
  }
  for (k=l; k<=r; k++) {
    A[k]=B[k];
  }
  return;
}

void MergeSortR(SortingItem *A, SortingItem *B, int l, int r) {
  int q;
  if (r<=l) {
    return;
  }
  q=(l+r)/2;
  MergeSortR(A, B, l, q);
  MergeSortR(A, B, q+1, r);
  Merge(A, B, l, q, r);
}

void MergeSort(SortingItem *A, int l, int r) {
  SortingItem *B=(SortingItem*)malloc((r-l+1)*sizeof(SortingItem));
  MergeSortR(A, B, l, r);
}

void swap(SortingItem *v, int n1, int n2) {
  SortingItem temp;
  temp=v[n1];
  v[n1]=v[n2];
  v[n2]=temp;
  return;
}

int HoarePartition(SortingItem *A, int l, int r ) {
  int i, j;
  SortingItem x=A[r];
  i=l-1;
  j=r;
  for ( ; ; ) {
    while(SORTINGitemLess(A[++i], x));
    while(SORTINGitemLess(x, A[--j])) {
      if (j==l) {
        break;
      }
    }
    if (i>=j) {
      break;
    }
    swap(A, i, j);
  }
  swap(A, i, r);
  return(i);
}

void QuickSortR(SortingItem *A, int l, int r ) {
  int q;
  if (r<=l) {
    return;
  }
  q=HoarePartition(A, l, r);
  QuickSortR(A, l, q-1);
  QuickSortR(A, q+1, r);
  return;
}

void QuickSort(SortingItem *A, int l, int r) {
  QuickSortR(A, l, r);
}
