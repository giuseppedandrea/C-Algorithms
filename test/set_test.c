#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../src/set.h"

int main(int argc, char const *argv[]) {
  int i, n1, n2;
  FILE *fp_test;

  if (argc!=6) {
    printf("Arguments error!\n");
    printf("Usage: %s <input_file> <search_1> <search_2> <search_union> <search_intersection>\n", argv[0]);
    return(EXIT_FAILURE);
  }

  fp_test=fopen(argv[1], "r");

  if (fp_test==NULL) {
    printf("Failed to open file \"%s\"\n", argv[1]);
    return(EXIT_FAILURE);
  }

  fscanf(fp_test, "%d", &n1);

  SetArray array_unordered1=SETinitArray(n1);
  SetArray array_ordered1=SETinitArray(n1);
  SetList list_unordered1=SETinitList();
  SetList list_ordered1=SETinitList();

  for (i=0; i<n1; i++) {
    SetItem data=SETitemScan(fp_test);
    SETfillArrayUnordered(array_unordered1, data);
    SETfillArrayOrdered(array_ordered1, data);
    SETfillListUnordered(list_unordered1, data);
    SETfillListOrdered(list_ordered1, data);
  }

  fscanf(fp_test, "%d", &n2);

  SetArray array_unordered2=SETinitArray(n2);
  SetArray array_ordered2=SETinitArray(n2);
  SetList list_unordered2=SETinitList();
  SetList list_ordered2=SETinitList();

  for (i=0; i<n2; i++) {
    SetItem data=SETitemScan(fp_test);
    SETfillArrayUnordered(array_unordered2, data);
    SETfillArrayOrdered(array_ordered2, data);
    SETfillListUnordered(list_unordered2, data);
    SETfillListOrdered(list_ordered2, data);
  }

  SetArray array_unordered_union=SETinitArray(n1+n2);
  SetArray array_unordered_intersection=SETinitArray(((n1<=n2)?n1:n2));
  SetArray array_ordered_union=SETinitArray(n1+n2);
  SetArray array_ordered_intersection=SETinitArray(((n1<=n2)?n1:n2));
  SetList list_unordered_union=SETinitList();
  SetList list_unordered_intersection=SETinitList();
  SetList list_ordered_union=SETinitList();
  SetList list_ordered_intersection=SETinitList();

  array_unordered_union=SETunionArrayUnordered(array_unordered1, array_unordered2);
  array_ordered_union=SETunionArrayOrdered(array_ordered1, array_ordered2);
  list_unordered_union=SETunionListUnordered(list_unordered1, list_unordered2);
  list_ordered_union=SETunionListOrdered(list_ordered1, list_ordered2);

  array_unordered_intersection=SETintersectionArrayUnordered(array_unordered1, array_unordered2);
  array_ordered_intersection=SETintersectionArrayOrdered(array_ordered1, array_ordered2);
  list_unordered_intersection=SETintersectionListUnordered(list_unordered1, list_unordered2);
  list_ordered_intersection=SETintersectionListOrdered(list_ordered1, list_ordered2);

  printf("Search 1:\n");
  printf("\tarray_unordered\n");
  printf("\t\t%d\n", SETsearchArrayUnordered(array_unordered1, atoi(argv[2])));
  printf("\tarray_ordered\n");
  printf("\t\t%d\n", SETsearchArrayOrdered(array_ordered1, atoi(argv[2])));
  printf("\tlist_unordered\n");
  printf("\t\t%d\n", SETsearchList(list_unordered1, atoi(argv[2])));
  printf("\tlist_ordered\n");
  printf("\t\t%d\n", SETsearchList(list_ordered1, atoi(argv[2])));

  printf("Search 2:\n");
  printf("\tarray_unordered\n");
  printf("\t\t%d\n", SETsearchArrayUnordered(array_unordered2, atoi(argv[3])));
  printf("\tarray_ordered\n");
  printf("\t\t%d\n", SETsearchArrayOrdered(array_ordered2, atoi(argv[3])));
  printf("\tlist_unordered\n");
  printf("\t\t%d\n", SETsearchList(list_unordered2, atoi(argv[3])));
  printf("\tlist_ordered\n");
  printf("\t\t%d\n", SETsearchList(list_ordered2, atoi(argv[3])));

  printf("Search union:\n");
  printf("\tarray_unordered\n");
  printf("\t\t%d\n", SETsearchArrayUnordered(array_unordered_union, atoi(argv[4])));
  printf("\tarray_ordered\n");
  printf("\t\t%d\n", SETsearchArrayOrdered(array_ordered_union, atoi(argv[4])));
  printf("\tlist_unordered\n");
  printf("\t\t%d\n", SETsearchList(list_unordered_union, atoi(argv[4])));
  printf("\tlist_ordered\n");
  printf("\t\t%d\n", SETsearchList(list_ordered_union, atoi(argv[4])));

  printf("Search intersection:\n");
  printf("\tarray_unordered\n");
  printf("\t\t%d\n", SETsearchArrayUnordered(array_unordered_intersection, atoi(argv[5])));
  printf("\tarray_ordered\n");
  printf("\t\t%d\n", SETsearchArrayOrdered(array_ordered_intersection, atoi(argv[5])));
  printf("\tlist_unordered\n");
  printf("\t\t%d\n", SETsearchList(list_unordered_intersection, atoi(argv[5])));
  printf("\tlist_ordered\n");
  printf("\t\t%d\n", SETsearchList(list_ordered_intersection, atoi(argv[5])));

  printf("Size 1:\n");
  printf("\tarray_unordered\n");
  printf("\t\t%d\n", SETsizeArray(array_unordered1));
  printf("\tarray_ordered\n");
  printf("\t\t%d\n", SETsizeArray(array_ordered1));
  printf("\tlist_unordered\n");
  printf("\t\t%d\n", SETsizeList(list_unordered1));
  printf("\tlist_ordered\n");
  printf("\t\t%d\n", SETsizeList(list_ordered1));

  printf("Size 2:\n");
  printf("\tarray_unordered\n");
  printf("\t\t%d\n", SETsizeArray(array_unordered2));
  printf("\tarray_ordered\n");
  printf("\t\t%d\n", SETsizeArray(array_ordered2));
  printf("\tlist_unordered\n");
  printf("\t\t%d\n", SETsizeList(list_unordered2));
  printf("\tlist_ordered\n");
  printf("\t\t%d\n", SETsizeList(list_ordered2));

  printf("Size union:\n");
  printf("\tarray_unordered\n");
  printf("\t\t%d\n", SETsizeArray(array_unordered_union));
  printf("\tarray_ordered\n");
  printf("\t\t%d\n", SETsizeArray(array_ordered_union));
  printf("\tlist_unordered\n");
  printf("\t\t%d\n", SETsizeList(list_unordered_union));
  printf("\tlist_ordered\n");
  printf("\t\t%d\n", SETsizeList(list_ordered_union));

  printf("Size intersection:\n");
  printf("\tarray_unordered\n");
  printf("\t\t%d\n", SETsizeArray(array_unordered_intersection));
  printf("\tarray_ordered\n");
  printf("\t\t%d\n", SETsizeArray(array_ordered_intersection));
  printf("\tlist_unordered\n");
  printf("\t\t%d\n", SETsizeList(list_unordered_intersection));
  printf("\tlist_ordered\n");
  printf("\t\t%d\n", SETsizeList(list_ordered_intersection));

  printf("Empty 1:\n");
  printf("\tarray_unordered\n");
  printf("%d\n", SETemptyArray(array_unordered1));
  printf("\tarray_ordered\n");
  printf("%d\n", SETemptyArray(array_ordered1));
  printf("\tlist_unordered\n");
  printf("%d\n", SETemptyList(list_unordered1));
  printf("\tlist_ordered\n");
  printf("%d\n", SETemptyList(list_ordered1));

  printf("Empty 2:\n");
  printf("\tarray_unordered\n");
  printf("%d\n", SETemptyArray(array_unordered2));
  printf("\tarray_ordered\n");
  printf("%d\n", SETemptyArray(array_ordered2));
  printf("\tlist_unordered\n");
  printf("%d\n", SETemptyList(list_unordered2));
  printf("\tlist_ordered\n");
  printf("%d\n", SETemptyList(list_ordered2));

  printf("Empty union:\n");
  printf("\tarray_unordered\n");
  printf("%d\n", SETemptyArray(array_unordered_union));
  printf("\tarray_ordered\n");
  printf("%d\n", SETemptyArray(array_ordered_union));
  printf("\tlist_unordered\n");
  printf("%d\n", SETemptyList(list_unordered_union));
  printf("\tlist_ordered\n");
  printf("%d\n", SETemptyList(list_ordered_union));

  printf("Empty intersection:\n");
  printf("\tarray_unordered\n");
  printf("%d\n", SETemptyArray(array_unordered_intersection));
  printf("\tarray_ordered\n");
  printf("%d\n", SETemptyArray(array_ordered_intersection));
  printf("\tlist_unordered\n");
  printf("%d\n", SETemptyList(list_unordered_intersection));
  printf("\tlist_ordered\n");
  printf("%d\n", SETemptyList(list_ordered_intersection));

  printf("Display 1:\n");
  printf("\tarray_unordered\n");
  SETdisplayArray(array_unordered1, stdout);
  printf("\tarray_ordered\n");
  SETdisplayArray(array_ordered1, stdout);
  printf("\tlist_unordered\n");
  SETdisplayList(list_unordered1, stdout);
  printf("\tlist_ordered\n");
  SETdisplayList(list_ordered1, stdout);

  printf("Display 2:\n");
  printf("\tarray_unordered\n");
  SETdisplayArray(array_unordered2, stdout);
  printf("\tarray_ordered\n");
  SETdisplayArray(array_ordered2, stdout);
  printf("\tlist_unordered\n");
  SETdisplayList(list_unordered2, stdout);
  printf("\tlist_ordered\n");
  SETdisplayList(list_ordered2, stdout);

  printf("Display union:\n");
  printf("\tarray_unordered\n");
  SETdisplayArray(array_unordered_union, stdout);
  printf("\tarray_ordered\n");
  SETdisplayArray(array_ordered_union, stdout);
  printf("\tlist_unordered\n");
  SETdisplayList(list_unordered_union, stdout);
  printf("\tlist_ordered\n");
  SETdisplayList(list_ordered_union, stdout);

  printf("Display intersection:\n");
  printf("\tarray_unordered\n");
  SETdisplayArray(array_unordered_intersection, stdout);
  printf("\tarray_ordered\n");
  SETdisplayArray(array_ordered_intersection, stdout);
  printf("\tlist_unordered\n");
  SETdisplayList(list_unordered_intersection, stdout);
  printf("\tlist_ordered\n");
  SETdisplayList(list_ordered_intersection, stdout);

  return(0);
}
