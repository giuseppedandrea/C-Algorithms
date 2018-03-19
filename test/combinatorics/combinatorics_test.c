#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "combinatorics.h"

int cmp(const void *a, const void *b) {
   return((*(int*)a)-(*(int*)b));
}

int main(int argc, char const *argv[]) {
  size_t i, j, n, k, total;
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

  fscanf(fp_test, "%zu", &n);
  fscanf(fp_test, "%zu", &k);
  int *input=(int*)malloc(n*sizeof(*input));
  int **choices=(int**)malloc(n*sizeof(int*));
  size_t *num_choices=(size_t*)malloc(n*sizeof(*num_choices));
  for (i=0; i<n; i++) {
    fscanf(fp_test, "%d", &input[i]);
    num_choices[i]=k;
    choices[i]=(int*)malloc(k*sizeof(int));
    for (j=0; j<k; j++) {
      choices[i][j]=input[i]+j+(10*i);
    }
  }

  printf("MultiplicationPrinciple\n");
  total=MultiplicationPrinciple(choices, num_choices, n);
  printf("Total: %zu\n\n", total);

  printf("DispositionSimple\n");
  total=DispositionSimple(input, n, k);
  printf("Total: %zu\n\n", total);

  printf("DispositionRipetition\n");
  total=DispositionRipetition(input, n, k);
  printf("Total: %zu\n\n", total);

  printf("PermutationSimple\n");
  total=PermutationSimple(input, n);
  printf("Total: %zu\n\n", total);

  printf("PermutationRipetition\n");
  total=PermutationRipetition(input, n);
  printf("Total: %zu\n\n", total);

  printf("CombinationSimple\n");
  total=CombinationSimple(input, n, k);
  printf("Total: %zu\n\n", total);

  printf("CombinationRipetition\n");
  total=CombinationRipetition(input, n, k);
  printf("Total: %zu\n\n", total);

  printf("PowerSetDivideEtImpera\n");
  total=PowerSetDivideEtImpera(input, n);
  printf("Total: %zu\n\n", total);

  printf("PowerSetDispositionRipetition\n");
  total=PowerSetDispositionRipetition(input, n);
  printf("Total: %zu\n\n", total);

  printf("PowerSetCombinationSimple\n");
  total=PowerSetCombinationSimple(input, n);
  printf("Total: %zu\n\n", total);

  printf("PartitionDispositionRipetition\n");
  total=PartitionDispositionRipetition(input, n, k);
  printf("Total: %zu\n\n", total);

  printf("PartitionErAlgorithmI\n");
  total=PartitionErAlgorithmI(input, n);
  printf("Total: %zu\n\n", total);

  printf("PartitionErAlgorithmII\n");
  total=PartitionErAlgorithmII(input, n, k);
  printf("Total: %zu\n\n", total);

  return(0);
}
