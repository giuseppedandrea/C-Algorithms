#include <stdio.h>
#include <stdlib.h>

#include "item.h"

int cmp_int(const void *a, const void *b) {
   return((*(int*)a)-(*(int*)b));
}

int cmp_float(const void *a, const void *b) {
   return((*(float*)a)-(*(float*)b));
}

int main(int argc, char const *argv[]) {
  int n, k;
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

  Item *item=(Item *)malloc(n*sizeof(*item));
  for (size_t i = 0; i < n; i++) {
    item[i]=ITEMsetVoid();

    if (ITEMcheckVoid(item[i])) {
      printf("Item %p is void\n", item[i]);
    } else {
      printf("Item %p is not void\n", item[i]);
    }
  }

  fscanf(fp_test, "%d", &k);
  for (size_t i = 0; i < n; i++) {
    item[i]=ITEMnew(k);

    if (ITEMcheckVoid(item[i])) {
      printf("Item %p is void\n", item[i]);
    } else {
      printf("Item %p is not void\n", item[i]);
    }

    ITEMaddMember(item[i], sizeof(int));
    ITEMaddMember(item[i], sizeof(float));
  }

  int num_int;
  float num_float;
  for (size_t i = 0; i < n; i++) {
    fscanf(fp_test, "%d", &num_int);
    ITEMsetMember(item[i], 0, &num_int);
    fscanf(fp_test, "%f", &num_float);
    ITEMsetMember(item[i], 1, &num_float);
  }

  for (size_t i = 0; i < n; i++) {
    printf("Item %p - int: %d, float: %f\n", item[i], *(int *)ITEMgetMember(item[i], 0), *(float *)ITEMgetMember(item[i], 1));
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      printf("Key: int - Item %p (%d) is equal to Item %p (%d): %d\n", item[i], *(int *)ITEMgetMember(item[i], 0), item[j], *(int *)ITEMgetMember(item[j], 0), ITEMequal(item[i], item[j], 0, cmp_int));
      printf("Key: float - Item %p (%f) is equal to Item %p (%f): %d\n", item[i], *(float *)ITEMgetMember(item[i], 1), item[j], *(float *)ITEMgetMember(item[j], 1), ITEMequal(item[i], item[j], 1, cmp_float));
      printf("Key: int - Item %p (%d) is less than Item %p (%d): %d\n", item[i], *(int *)ITEMgetMember(item[i], 0), item[j], *(int *)ITEMgetMember(item[j], 0), ITEMless(item[i], item[j], 0, cmp_int));
      printf("Key: float - Item %p (%f) is less than Item %p (%f): %d\n", item[i], *(float *)ITEMgetMember(item[i], 1), item[j], *(float *)ITEMgetMember(item[j], 1), ITEMless(item[i], item[j], 1, cmp_float));
      printf("Key: int - Item %p (%d) is less than or equal to Item %p (%d): %d\n", item[i], *(int *)ITEMgetMember(item[i], 0), item[j], *(int *)ITEMgetMember(item[j], 0), ITEMlessEqual(item[i], item[j], 0, cmp_int));
      printf("Key: float - Item %p (%f) is less than or equal to Item %p (%f): %d\n", item[i], *(float *)ITEMgetMember(item[i], 1), item[j], *(float *)ITEMgetMember(item[j], 1), ITEMlessEqual(item[i], item[j], 1, cmp_float));
      printf("Key: int - Item %p (%d) is greater than Item %p (%d): %d\n", item[i], *(int *)ITEMgetMember(item[i], 0), item[j], *(int *)ITEMgetMember(item[j], 0), ITEMgreater(item[i], item[j], 0, cmp_int));
      printf("Key: float - Item %p (%f) is greater than Item %p (%f): %d\n", item[i], *(float *)ITEMgetMember(item[i], 1), item[j], *(float *)ITEMgetMember(item[j], 1), ITEMgreater(item[i], item[j], 1, cmp_float));
      printf("Key: int - Item %p (%d) is greater than or equal to Item %p (%d): %d\n", item[i], *(int *)ITEMgetMember(item[i], 0), item[j], *(int *)ITEMgetMember(item[j], 0), ITEMgreaterEqual(item[i], item[j], 0, cmp_int));
      printf("Key: float - Item %p (%f) is greater than or equal to Item %p (%f): %d\n", item[i], *(float *)ITEMgetMember(item[i], 1), item[j], *(float *)ITEMgetMember(item[j], 1), ITEMgreaterEqual(item[i], item[j], 1, cmp_float));
    }
  }

  for (size_t i = 0; i < n; i++) {
    ITEMfree(item[i]);
  }

  return(0);
}
