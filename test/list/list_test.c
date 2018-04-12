#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#include "list.h"
#include "item.h"

void* get_list_key(const void *list_data) {
  return(ITEMgetMember((Item)list_data, 1));
}

int cmp_list_key(const void *a, const void *b) {
  return((*(int*)(a))-(*(int*)(b)));
}

int cmp_list_data(const void *a, const void *b) {
  return(cmp_list_key(get_list_key((Item)a), get_list_key((Item)b)));
}

void print_list_data(const void *list_data) {
  if (list_data==NULL) {
    printf("Item NULL\n");
  } else {
    printf("Item %p - char: %c, int: %d\n", list_data, *(char *)ITEMgetMember((Item)list_data, 0), *(int *)ITEMgetMember((Item)list_data, 1));
  }
}

void free_list_data(const void *list_data) {
  ITEMfree((Item)list_data);
}

int main(int argc, char const *argv[]) {
  int ret;
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

  UnorderedSinglyList unordered_singly_list, ordered_singly_list;
  char c;
  int i;
  Item item;

  unordered_singly_list=SinglyListNew();

  printf("- Unordered Singly List: %p\n", unordered_singly_list);

  while (fscanf(fp_test, " %c %d\n", &c, &i)!=EOF) {
    item=ITEMnew(2);
    ITEMaddMember(item, sizeof(char));
    ITEMaddMember(item, sizeof(int));
    ITEMsetMember(item, 0, &c);
    ITEMsetMember(item, 1, &i);

    SinglyListInsertHead(unordered_singly_list, item);
  }

  printf("-- SinglyListInsertHead\n");
  printf("--- List:\n");
  SinglyListPrint(unordered_singly_list, print_list_data);

  rewind(fp_test);

  while (fscanf(fp_test, " %c %d\n", &c, &i)!=EOF) {
    item=ITEMnew(2);
    ITEMaddMember(item, sizeof(char));
    ITEMaddMember(item, sizeof(int));
    ITEMsetMember(item, 0, &c);
    ITEMsetMember(item, 1, &i);

    SinglyListInsertTail(unordered_singly_list, item);
  }

  printf("-- SinglyListInsertTail\n");
  printf("--- List:\n");
  SinglyListPrint(unordered_singly_list, print_list_data);

  printf("-- SinglyListSearch\n");
  item=ITEMnew(2);
  ITEMaddMember(item, sizeof(char));
  ITEMaddMember(item, sizeof(int));
  c='a';
  i=8;
  ITEMsetMember(item, 0, &c);
  ITEMsetMember(item, 1, &i);
  printf("--- Item to search:\n");
  print_list_data(item);
  item=SinglyListSearch(unordered_singly_list, ITEMgetMember(item, 1), get_list_key, cmp_list_key);
  printf("--- Item in list:\n");
  print_list_data(item);
  item=ITEMnew(2);
  ITEMaddMember(item, sizeof(char));
  ITEMaddMember(item, sizeof(int));
  c='a';
  i=10;
  ITEMsetMember(item, 0, &c);
  ITEMsetMember(item, 1, &i);
  printf("--- Item to search:\n");
  print_list_data(item);
  item=SinglyListSearch(unordered_singly_list, ITEMgetMember(item, 1), get_list_key, cmp_list_key);
  printf("--- Item in list:\n");
  print_list_data(item);
  printf("--- List:\n");
  SinglyListPrint(unordered_singly_list, print_list_data);

  printf("-- SinglyListDeleteKey\n");
  item=ITEMnew(2);
  ITEMaddMember(item, sizeof(char));
  ITEMaddMember(item, sizeof(int));
  c='z';
  i=8;
  ITEMsetMember(item, 0, &c);
  ITEMsetMember(item, 1, &i);
  printf("--- Item to delete:\n");
  print_list_data(item);
  ret=SinglyListDeleteKey(unordered_singly_list, ITEMgetMember(item, 1), get_list_key, cmp_list_key, free_list_data);
  printf("--- Item deleted: %d\n", ret);
  item=ITEMnew(2);
  ITEMaddMember(item, sizeof(char));
  ITEMaddMember(item, sizeof(int));
  c='z';
  i=10;
  ITEMsetMember(item, 0, &c);
  ITEMsetMember(item, 1, &i);
  printf("--- Item to delete:\n");
  print_list_data(item);
  ret=SinglyListDeleteKey(unordered_singly_list, ITEMgetMember(item, 1), get_list_key, cmp_list_key, free_list_data);
  printf("--- Item deleted: %d\n", ret);
  printf("--- List:\n");
  SinglyListPrint(unordered_singly_list, print_list_data);

  printf("-- SinglyListDeleteHead\n");
  SinglyListDeleteHead(unordered_singly_list, free_list_data);
  printf("--- List:\n");
  SinglyListPrint(unordered_singly_list, print_list_data);

  printf("-- SinglyListDeleteTail\n");
  SinglyListDeleteTail(unordered_singly_list, free_list_data);
  printf("--- List:\n");
  SinglyListPrint(unordered_singly_list, print_list_data);

  printf("-- SinglyListExtractHead\n");
  item=SinglyListExtractHead(unordered_singly_list);
  printf("--- Item extract:\n");
  print_list_data(item);
  printf("--- List:\n");
  SinglyListPrint(unordered_singly_list, print_list_data);

  printf("-- SinglyListExtractTail\n");
  item=SinglyListExtractTail(unordered_singly_list);
  printf("--- Item extract:\n");
  print_list_data(item);
  printf("--- List:\n");
  SinglyListPrint(unordered_singly_list, print_list_data);

  printf("-- SinglyListExtractKey\n");
  item=ITEMnew(2);
  ITEMaddMember(item, sizeof(char));
  ITEMaddMember(item, sizeof(int));
  c='z';
  i=1;
  ITEMsetMember(item, 0, &c);
  ITEMsetMember(item, 1, &i);
  printf("--- Item to extract:\n");
  print_list_data(item);
  item=SinglyListExtractKey(unordered_singly_list, ITEMgetMember(item, 1), get_list_key, cmp_list_key);
  printf("--- Item extract:\n");
  print_list_data(item);
  item=ITEMnew(2);
  ITEMaddMember(item, sizeof(char));
  ITEMaddMember(item, sizeof(int));
  c='y';
  i=10;
  ITEMsetMember(item, 0, &c);
  ITEMsetMember(item, 1, &i);
  printf("--- Item to extract:\n");
  print_list_data(item);
  item=SinglyListExtractKey(unordered_singly_list, ITEMgetMember(item, 1), get_list_key, cmp_list_key);
  printf("--- Item extract:\n");
  print_list_data(item);
  printf("--- List:\n");
  SinglyListPrint(unordered_singly_list, print_list_data);

  SinglyListFree(unordered_singly_list, free_list_data);

  rewind(fp_test);

  ordered_singly_list=SinglyListNew();

  printf("- Ordered Singly List: %p\n", ordered_singly_list);

  while (fscanf(fp_test, " %c %d\n", &c, &i)!=EOF) {
    item=ITEMnew(2);
    ITEMaddMember(item, sizeof(char));
    ITEMaddMember(item, sizeof(int));
    ITEMsetMember(item, 0, &c);
    ITEMsetMember(item, 1, &i);

    SinglyListInsertSort(ordered_singly_list, item, cmp_list_data);
  }

  printf("-- SinglyListInsertSort\n");
  printf("--- List:\n");
  SinglyListPrint(ordered_singly_list, print_list_data);

  printf("-- SinglyListSearchSort\n");
  item=ITEMnew(2);
  ITEMaddMember(item, sizeof(char));
  ITEMaddMember(item, sizeof(int));
  c='a';
  i=8;
  ITEMsetMember(item, 0, &c);
  ITEMsetMember(item, 1, &i);
  printf("--- Item to search:\n");
  print_list_data(item);
  item=SinglyListSearchSort(ordered_singly_list, ITEMgetMember(item, 1), get_list_key, cmp_list_key);
  printf("--- Item in list:\n");
  print_list_data(item);
  item=ITEMnew(2);
  ITEMaddMember(item, sizeof(char));
  ITEMaddMember(item, sizeof(int));
  c='a';
  i=10;
  ITEMsetMember(item, 0, &c);
  ITEMsetMember(item, 1, &i);
  printf("--- Item to search:\n");
  print_list_data(item);
  item=SinglyListSearchSort(ordered_singly_list, ITEMgetMember(item, 1), get_list_key, cmp_list_key);
  printf("--- Item in list:\n");
  print_list_data(item);
  printf("--- List:\n");
  SinglyListPrint(ordered_singly_list, print_list_data);

  printf("-- SinglyListDeleteKeySort\n");
  item=ITEMnew(2);
  ITEMaddMember(item, sizeof(char));
  ITEMaddMember(item, sizeof(int));
  c='z';
  i=8;
  ITEMsetMember(item, 0, &c);
  ITEMsetMember(item, 1, &i);
  printf("--- Item to delete:\n");
  print_list_data(item);
  ret=SinglyListDeleteKeySort (ordered_singly_list, ITEMgetMember(item, 1), get_list_key, cmp_list_key, free_list_data);
  printf("--- Item deleted: %d\n", ret);
  item=ITEMnew(2);
  ITEMaddMember(item, sizeof(char));
  ITEMaddMember(item, sizeof(int));
  c='y';
  i=10;
  ITEMsetMember(item, 0, &c);
  ITEMsetMember(item, 1, &i);
  printf("--- Item to delete:\n");
  print_list_data(item);
  ret=SinglyListDeleteKeySort (ordered_singly_list, ITEMgetMember(item, 1), get_list_key, cmp_list_key, free_list_data);
  printf("--- Item deleted: %d\n", ret);
  printf("--- List:\n");
  SinglyListPrint(ordered_singly_list, print_list_data);

  SinglyListFree(ordered_singly_list, free_list_data);

  return(0);
}
