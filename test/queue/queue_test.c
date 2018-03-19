#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "queue.h"

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

  QueueArray array=QUEUEinitArray(n);
  QueueList list=QUEUEinitList();

  for (i=0; i<n; i++) {
    fscanf(fp_test, "%d", &mode);
    QueueItem data;
    switch (mode) {
      case 0:
        data=QUEUEitemScan(fp_test);
        printf("Put: ");
        QUEUEitemShow(data, stdout);
        printf("\n");
        QUEUEputArray(array, data);
        QUEUEputList(list, data);
        break;
      case 1:
        printf("Get array: ");
        data=QUEUEgetArray(array);
        QUEUEitemShow(data, stdout);
        printf("\n");
        printf("Get list: ");
        data=QUEUEgetList(list);
        QUEUEitemShow(data, stdout);
        printf("\n");
        break;
      case 2:
        printf("Empty array: %d\n", QUEUEemptyArray(array));
        printf("Empty list: %d\n", QUEUEemptyList(list));
        break;
      default:
        printf("Error mode!\n");
        break;
    }
  }

  return(0);
}
