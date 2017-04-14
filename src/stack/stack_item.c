#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_item.h"

struct stack_item {
  Key value;
};

static struct stack_item STACK_ITEM_NULL = {
  VOID_VALUE
};
static StackItem STACK_ITEM_VOID = &STACK_ITEM_NULL;

StackItem STACKitemNew(void) {
  StackItem data=(StackItem)malloc(sizeof(*data));
  if(data==NULL)
    return(STACKitemSetVoid());
  data->value=DEFAULT_VALUE;
  return(data);
}

void STACKitemFree(StackItem data) {
  free(data);
  return;
}

StackItem STACKitemScan(FILE *fp) {
  StackItem data=STACKitemNew();
  if (data!=NULL) {
    fscanf(fp, FORMAT, &data->value);
  }
  return(data);
}

void STACKitemShow(StackItem data, FILE *fp) {
  fprintf(fp, FORMAT, data->value);
  return;
}

int STACKitemCheckVoid(StackItem data) {
  return(data==STACK_ITEM_VOID);
}

StackItem STACKitemSetVoid(void) {
  StackItem data=STACK_ITEM_VOID;
  return(data);
}

Key STACKkeyGet(StackItem data) {
  return(data->value);
}

Key STACKkeyCompare(Key k1, Key k2) {
  return(k1-k2);
}

int STACKitemEqual(StackItem data1, StackItem data2) {
  Key k1=STACKkeyGet(data1), k2=STACKkeyGet(data2);
  if (STACKkeyCompare(k1, k2)==0)
    return(1);
  else
    return(0);
}

int STACKitemLess(StackItem data1, StackItem data2) {
  Key k1=STACKkeyGet(data1), k2=STACKkeyGet(data2);
  if (STACKkeyCompare(k1, k2)<0)
    return(1);
  else
    return(0);
}

int STACKitemLessEqual(StackItem data1, StackItem data2) {
  Key k1=STACKkeyGet(data1), k2=STACKkeyGet(data2);
  if (STACKkeyCompare(k1, k2)<=0)
    return(1);
  else
    return(0);
}

int STACKitemGreater(StackItem data1, StackItem data2) {
  Key k1=STACKkeyGet(data1), k2=STACKkeyGet(data2);
  if (STACKkeyCompare(k1, k2)>0)
    return(1);
  else
    return(0);
}

int STACKitemGreaterEqual(StackItem data1, StackItem data2) {
  Key k1=STACKkeyGet(data1), k2=STACKkeyGet(data2);
  if (STACKkeyCompare(k1, k2)>=0)
    return(1);
  else
    return(0);
}
