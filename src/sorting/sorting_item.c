#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorting_item.h"

struct sorting_item {
  Key value;
};

static struct sorting_item SORTING_ITEM_NULL = {
  VOID_VALUE
};
static SortingItem SORTING_ITEM_VOID = &SORTING_ITEM_NULL;

SortingItem SORTINGitemNew(void) {
  SortingItem data=(SortingItem)malloc(sizeof(*data));
  if(data==NULL)
    return(SORTINGitemSetVoid());
  data->value=DEFAULT_VALUE;
  return(data);
}

void SORTINGitemFree(SortingItem data) {
  free(data);
  return;
}

SortingItem SORTINGitemScan(FILE *fp) {
  SortingItem data=SORTINGitemNew();
  if (data!=NULL) {
    fscanf(fp, FORMAT, &data->value);
  }
  return(data);
}

void SORTINGitemShow(SortingItem data, FILE *fp) {
  fprintf(fp, FORMAT, data->value);
  return;
}

int SORTINGitemCheckVoid(SortingItem data) {
  return(data==SORTING_ITEM_VOID);
}

SortingItem SORTINGitemSetVoid(void) {
  SortingItem data=SORTING_ITEM_VOID;
  return(data);
}

Key SORTINGkeyGet(SortingItem data) {
  return(data->value);
}

Key SORTINGkeyCompare(Key k1, Key k2) {
  return(k1-k2);
}

int SORTINGitemEqual(SortingItem data1, SortingItem data2) {
  Key k1=SORTINGkeyGet(data1), k2=SORTINGkeyGet(data2);
  if (SORTINGkeyCompare(k1, k2)==0)
    return(1);
  else
    return(0);
}

int SORTINGitemLess(SortingItem data1, SortingItem data2) {
  Key k1=SORTINGkeyGet(data1), k2=SORTINGkeyGet(data2);
  if (SORTINGkeyCompare(k1, k2)<0)
    return(1);
  else
    return(0);
}

int SORTINGitemLessEqual(SortingItem data1, SortingItem data2) {
  Key k1=SORTINGkeyGet(data1), k2=SORTINGkeyGet(data2);
  if (SORTINGkeyCompare(k1, k2)<=0)
    return(1);
  else
    return(0);
}

int SORTINGitemGreater(SortingItem data1, SortingItem data2) {
  Key k1=SORTINGkeyGet(data1), k2=SORTINGkeyGet(data2);
  if (SORTINGkeyCompare(k1, k2)>0)
    return(1);
  else
    return(0);
}

int SORTINGitemGreaterEqual(SortingItem data1, SortingItem data2) {
  Key k1=SORTINGkeyGet(data1), k2=SORTINGkeyGet(data2);
  if (SORTINGkeyCompare(k1, k2)>=0)
    return(1);
  else
    return(0);
}
