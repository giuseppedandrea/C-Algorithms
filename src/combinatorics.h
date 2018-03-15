#ifndef COMBINATORICS_H
#define COMBINATORICS_H

#include <stdio.h>

size_t  MultiplicationPrinciple         (int **val, size_t *num_choices, size_t n);
size_t  DispositionSimple               (int *val, size_t n, size_t k);
size_t  DispositionRipetition           (int *val, size_t n, size_t k);
size_t  PermutationSimple               (int *val, size_t n);
size_t  PermutationRipetition           (int *val, size_t n);
size_t  CombinationSimple               (int *val, size_t n, size_t k);
size_t  CombinationRipetition           (int *val, size_t n, size_t k);
size_t  PowerSetDivideEtImpera          (int *val, size_t k);
size_t  PowerSetDispositionRipetition   (int *val, size_t k);
size_t  PowerSetCombinationSimple       (int *val, size_t k);
size_t  PartitionDispositionRipetition  (int *val, size_t n, size_t k);
size_t  PartitionErAlgorithmI           (int *val, size_t n);
size_t  PartitionErAlgorithmII          (int *val, size_t n, size_t k);

#endif
