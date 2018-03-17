#include <stdio.h>
#include <stdlib.h>

#include "combinatorics.h"

// Multiplication Priciple
size_t MultiplicationPrincipleR(size_t pos, int **val, int *sol, size_t *num_choices, size_t n, size_t count) {
  int i;

  if (pos>=n) {
    for (i=0; i<n; i++)
      printf("%d ", sol[i]);
    printf("\n");
    return(count+1);
  }

  for (i=0; i<num_choices[pos]; i++) {
    sol[pos]=val[pos][i];
    count=MultiplicationPrincipleR(pos+1, val, sol, num_choices, n, count);
  }

  return(count);
}

size_t MultiplicationPrinciple(int **val, size_t *num_choices, size_t n) {
  size_t count;
  int *sol=(int*)malloc(n*sizeof(int));
  count=MultiplicationPrincipleR(0, val, sol, num_choices, n, 0);
  free(sol);
  return(count);
}

// Disposition simple
size_t DispositionSimpleR(size_t pos, int *val, int *sol, size_t *mark, size_t n, size_t k, size_t count) {
  size_t i;

  if (pos>=k) {
    for (i=0; i<k; i++)
      printf("%d ", sol[i]);
    printf("\n");
    return(count+1);
  }

  for (i=0; i<n; i++) {
    if (mark[i]==0) {
      mark[i]=1;
      sol[pos]=val[i];
      count=DispositionSimpleR(pos+1, val, sol, mark, n, k, count);
      mark[i]=0;
    }
  }

  return(count);
}

size_t DispositionSimple(int *val, size_t n, size_t k) {
  size_t i, count;
  int *sol=(int*)malloc(k*sizeof(int));
  size_t *mark=(size_t*)malloc(n*sizeof(size_t));
  for (i=0; i<n; i++)
    mark[i]=0;
  count=DispositionSimpleR(0, val, sol, mark, n, k, 0);
  free(sol);
  free(mark);
  return(count);
}

// Disposition with ripetitions
size_t DispositionRipetitionR(size_t pos, int *val, int *sol, size_t n, size_t k, size_t count) {
  size_t i;

    if (pos>=k) {
      for (i=0; i<k; i++)
        printf("%d ", sol[i]);
      printf("\n");
      return(count+1);
    }

    for (i=0; i<n; i++) {
      sol[pos]=val[i];
      count=DispositionRipetitionR(pos+1, val, sol, n, k, count);
    }

    return(count);
}

size_t DispositionRipetition(int *val, size_t n, size_t k) {
  size_t count;
  int *sol=(int*)malloc(k*sizeof(int));
  count=DispositionRipetitionR(0, val, sol, n, k, 0);
  free(sol);
  return(count);
}

// Permutation simple
size_t PermutationSimpleR(size_t pos, int *val, int *sol, size_t *mark, size_t n, size_t count) {
  size_t i;

  if (pos>=n) {
    for (i=0; i<n; i++)
      printf("%d ", sol[i]);
    printf("\n");
    return(count+1);
  }

  for (i=0; i<n; i++) {
    if (mark[i]==0) {
      mark[i]=1;
      sol[pos]=val[i];
      count=PermutationSimpleR(pos+1, val, sol, mark, n, count);
      mark[i]=0;
    }
  }

  return(count);
}

size_t PermutationSimple(int *val, size_t n) {
  size_t i, count;
  int *sol=(int*)malloc(n*sizeof(int));
  size_t *mark=(size_t*)malloc(n*sizeof(size_t));
  for (i=0; i<n; i++)
    mark[i]=0;
  count=PermutationSimpleR(0, val, sol, mark, n, 0);
  free(sol);
  free(mark);
  return(count);
}

// Permutazion with ripetitions
size_t PermutationRipetitionR(size_t pos, int *dist_val, int *sol, size_t *mark, size_t n, size_t n_dist, size_t count) {
  size_t i;

  if (pos>=n) {
    for (i=0; i<n; i++)
      printf("%d ", sol[i]);
    printf("\n");
    return(count+1);
  }

  for (i=0; i<n_dist; i++) {
    if (mark[i]>0) {
      mark[i]--;
      sol[pos]=dist_val[i];
      count=PermutationRipetitionR(pos+1, dist_val, sol, mark, n, n_dist, count);
      mark[i]++;
    }
  }

  return(count);
}

size_t PermutationRipetition(int *val, size_t n) {
  size_t i, j, n_dist, count;

  int *dist_val=(int*)malloc(n*sizeof(int));
  int *sol=(int*)malloc(n*sizeof(int));

  for (i=0; i<n; i++) {
    for (j=i+1; j<n; j++) {
      if (val[j]<val[i]) {
        int tmp=val[j];
        val[j]=val[i];
        val[i]=tmp;
      }
    }
  }

  for (i=1, n_dist=1; i<n; i++)
    if(val[i-1]!=val[i])
      n_dist++;

  size_t *mark=(size_t*)malloc(n_dist*sizeof(size_t));

  for (i=0; i<n_dist; i++)
    mark[i]=0;

  j=0;
  dist_val[j++]=val[0];
  for (i=1; i<n; i++)
    if(val[i-1]!=val[i])
      dist_val[j++]=val[i];

  i=1;
  j=0;
  mark[j]=1;
  while(i<n) {
    while (val[i-1]==val[i]) {
      i++;
      mark[j]++;
    }
    j++;
    mark[j]++;
    i++;
  }

  count=PermutationRipetitionR(0, dist_val, sol, mark, n, n_dist, 0);

  free(dist_val);
  free(sol);
  free(mark);

  return(count);
}

// Combination simple
size_t CombinationSimpleR(size_t pos, int *val, int *sol, size_t n, size_t k, size_t start, size_t count) {
  size_t i;

  if (pos>=k) {
    for (i=0; i<k; i++)
      printf("%d ", sol[i]);
    printf("\n");
    return(count+1);
  }

  for (i=start; i<n; i++) {
    sol[pos]=val[i];
    count=CombinationSimpleR(pos+1, val, sol, n, k, i+1, count);
  }

  return(count);
}

size_t CombinationSimple(int *val, size_t n, size_t k) {
  size_t count;
  int *sol=(int*)malloc(k*sizeof(int));
  count=CombinationSimpleR(0, val, sol, n, k, 0, 0);
  free(sol);
  return(count);
}

// Combination with ripetitions
size_t CombinationRipetitionR(size_t pos, int *val, int *sol, size_t n, size_t k, size_t start, size_t count) {
  size_t i;

  if (pos>=k) {
    for (i=0; i<k; i++)
      printf("%d ", sol[i]);
    printf("\n");
    return(count+1);
  }

  for (i=start; i<n; i++) {
    sol[pos]=val[i];
    count=CombinationRipetitionR(pos+1, val, sol, n, k, start, count);
    start++;
  }

  return(count);
}

size_t CombinationRipetition(int *val, size_t n, size_t k) {
  size_t count;
  int *sol=(int*)malloc(k*sizeof(int));
  count=CombinationRipetitionR(0, val, sol, n, k, 0, 0);
  free(sol);
  return(count);
}

// Powerset (Divide et impera)
size_t PowerSetDivideEtImperaR(size_t pos, int *val, int *sol, size_t k, size_t start, size_t count) {
  int i;

  if (start>=k) {
     printf("{ ");
      for (i=0; i<pos; i++)
        printf("%d ", sol[i]);
     printf("} \n");
     return(count+1);
  }

  for (i=start; i<k; i++) {
     sol[pos]=val[i];
     count=PowerSetDivideEtImperaR(pos+1, val, sol, k, i+1, count);
  }

  count=PowerSetDivideEtImperaR(pos, val, sol, k, k, count);

  return(count);
}

size_t PowerSetDivideEtImpera(int *val, size_t k) {
  size_t count;
  int *sol=(int*)malloc(k*sizeof(int));
  count=PowerSetDivideEtImperaR(0, val, sol, k, 0, 0);
  free(sol);
  return(count);
}

// Powerset (Disposition with ripetition)
size_t PowerSetDispositionRipetitionR(size_t pos, int *val, int *sol, size_t k, size_t count) {
  size_t i;

  if (pos>=k) {
    printf("{ ");
    for (i=0; i<k; i++)
      if (sol[i]!=0)
        printf("%d ", val[i]);
    printf("} \n");
    return(count+1);
  }

  sol[pos] = 0;
  count=PowerSetDispositionRipetitionR(pos+1, val, sol, k, count);
  sol[pos] = 1;
  count=PowerSetDispositionRipetitionR(pos+1, val, sol, k, count);

  return(count);
}

size_t PowerSetDispositionRipetition(int *val, size_t k) {
  size_t count;
  int *sol=(int*)malloc(k*sizeof(int));
  count=PowerSetDispositionRipetitionR(0, val, sol, k, 0);
  free(sol);
  return(count);
}

// Powerset (Combination simple)
size_t PowerSetCombinationSimpleR(size_t pos, int* val, int* sol, size_t n, size_t k, size_t start) {
  size_t count=0, i;

  if (pos==n) {
     printf("{ ");
     for (i=0; i<n; i++)
        printf("%d ", sol[i]);
     printf("}\n");
     return(1);
  }

  for (i=start; i<k; i++) {
     sol[pos]=val[i];
     count+=PowerSetCombinationSimpleR(pos+1, val, sol, n, k, i+1);
  }

  return(count);
}

size_t PowerSetCombinationSimple(int *val, size_t k) {
  size_t count=0, n;
  int *sol=(int*)malloc(k*sizeof(int));
  printf("{ }\n");
  count++;
  for(n=1; n<=k; n++)
     count+=PowerSetCombinationSimpleR(0, val, sol, n, k, 0);
  free(sol);
  return(count);
}

// Partition (Disposition with ripetition)
size_t PartitionDispositionRipetitionR(size_t pos, int *val, int *sol, size_t n, size_t k, size_t count) {
  size_t i, j, occ[k];

  for (i=0; i<k; i++)
     occ[i]=0;

  if (pos>=n) {
    for (i=0; i<n; i++)
       occ[sol[i]]++;
    for (i=0; i<k; i++)
      if (occ[i]==0)
        return(count);

    printf("partition: ");
    for (i=0; i<k; i++) {
      printf("{ ");
      for (j=0; j<n; j++) {
        if (sol[j]==i)
          printf("%d ", val[j]);
      }
      printf("}  ");
    }
    printf("\n");
    return(count+1);
  }

  for (i=0; i<k; i++) {
    sol[pos]=i;
    count=PartitionDispositionRipetitionR(pos+1, val, sol, n, k, count);
  }

  return(count);
}

size_t PartitionDispositionRipetition(int *val, size_t n, size_t k) {
  size_t count;
  int *sol=(int*)malloc(n*sizeof(int));
  count=PartitionDispositionRipetitionR(0, val, sol, n, k, 0);
  free(sol);
  return(count);
}

// Partition (Er Algorithm I)
size_t PartitionErAlgorithmIR(size_t pos, int *val, int *sol, size_t n, size_t m, size_t count) {
  size_t i, j;

  if (pos>=n) {
    printf("partition: ");
    for (i=0; i<m; i++) {
      printf("{ ");
      for (j=0; j<n; j++) {
        if (sol[j]==i)
          printf("%d ", val[j]);
      }
      printf("}  ");
    }
    printf("\n");
    return(count+1);
  }

  for (i=0; i<m; i++) {
    sol[pos]=i;
    count=PartitionErAlgorithmIR(pos+1, val, sol, n, m, count);
  }

  sol[pos]=m;
  count=PartitionErAlgorithmIR(pos+1, val, sol, n, m+1, count);

  return(count);
}

size_t PartitionErAlgorithmI(int *val, size_t n) {
  size_t count;
  int *sol=(int*)malloc(n*sizeof(int));
  count=PartitionErAlgorithmIR(0, val, sol, n, 0, 0);
  free(sol);
  return(count);
}

// Partition (Er Algorithm II)
size_t PartitionErAlgorithmIIR(size_t pos, int *val, int *sol, size_t n, size_t k, size_t m, size_t count) {
  size_t i, j;

  if (pos>=n) {
    if (m==k) {
      printf("partition: ");
      for (i=0; i<m; i++) {
        printf("{ ");
        for (j=0; j<n; j++) {
          if (sol[j]==i)
            printf("%d ", val[j]);
        }
        printf("}  ");
      }
      printf("\n");
      return(count+1);
    }
    return(count);
  }

  for (i=0; i<m; i++) {
    sol[pos]=i;
    count=PartitionErAlgorithmIIR(pos+1, val, sol, n, k, m, count);
  }

  sol[pos]=m;
  count=PartitionErAlgorithmIIR(pos+1, val, sol, n, k, m+1, count);

  return(count);
}

size_t PartitionErAlgorithmII(int *val, size_t n, size_t k) {
  size_t count;
  int *sol=(int*)malloc(n*sizeof(int));
  count=PartitionErAlgorithmIIR(0, val, sol, n, k, 0, 0);
  free(sol);
  return(count);
}
