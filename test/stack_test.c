#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../src/stack.h"

int main(int argc, char const *argv[]) {
  int i, n, mode;
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

  StackArray array=STACKinitArray(n);
  StackList list=STACKinitList();

  for (i=0; i<n; i++) {
    fscanf(fp_test, "%d", &mode);
    StackItem data;
    switch (mode) {
      case 0:
        data=STACKitemScan(fp_test);
        printf("Put: ");
        STACKitemShow(data, stdout);
        printf("\n");
        STACKpushArray(array, data);
        STACKpushList(list, data);
        break;
      case 1:
        printf("Get array: ");
        data=STACKpopArray(array);
        STACKitemShow(data, stdout);
        printf("\n");
        printf("Get list: ");
        data=STACKpopList(list);
        STACKitemShow(data, stdout);
        printf("\n");
        break;
      case 2:
        printf("Empty array: %d\n", STACKemptyArray(array));
        printf("Empty list: %d\n", STACKemptyList(list));
        break;
      default:
        printf("Error mode!\n");
        break;
    }
  }

  return(0);
}
