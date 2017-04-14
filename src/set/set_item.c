#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set_item.h"

struct set_item {
  Key value;
};

static struct set_item SET_ITEM_NULL = {
  VOID_VALUE
};
static SetItem SET_ITEM_VOID = &SET_ITEM_NULL;

SetItem SETitemNew(void) {
  SetItem data=(SetItem)malloc(sizeof(*data));
  if(data==NULL)
    return(SETitemSetVoid());
  data->value=DEFAULT_VALUE;
  return(data);
}

void SETitemFree(SetItem data) {
  free(data);
  return;
}

SetItem SETitemScan(FILE *fp) {
  SetItem data=SETitemNew();
  if (data!=NULL) {
    fscanf(fp, FORMAT, &data->value);
  }
  return(data);
}

void SETitemShow(SetItem data, FILE *fp) {
  fprintf(fp, FORMAT, data->value);
  return;
}

int SETitemCheckVoid(SetItem data) {
  return(data==SET_ITEM_VOID);
}

SetItem SETitemSetVoid(void) {
  SetItem data=SET_ITEM_VOID;
  return(data);
}

Key SETkeyGet(SetItem data) {
  return(data->value);
}

Key SETkeyCompare(Key k1, Key k2) {
  return(k1-k2);
}

int SETitemEqual(SetItem data1, SetItem data2) {
  Key k1=SETkeyGet(data1), k2=SETkeyGet(data2);
  if (SETkeyCompare(k1, k2)==0)
    return(1);
  else
    return(0);
}

int SETitemLess(SetItem data1, SetItem data2) {
  Key k1=SETkeyGet(data1), k2=SETkeyGet(data2);
  if (SETkeyCompare(k1, k2)<0)
    return(1);
  else
    return(0);
}

int SETitemLessEqual(SetItem data1, SetItem data2) {
  Key k1=SETkeyGet(data1), k2=SETkeyGet(data2);
  if (SETkeyCompare(k1, k2)<=0)
    return(1);
  else
    return(0);
}

int SETitemGreater(SetItem data1, SetItem data2) {
  Key k1=SETkeyGet(data1), k2=SETkeyGet(data2);
  if (SETkeyCompare(k1, k2)>0)
    return(1);
  else
    return(0);
}

int SETitemGreaterEqual(SetItem data1, SetItem data2) {
  Key k1=SETkeyGet(data1), k2=SETkeyGet(data2);
  if (SETkeyCompare(k1, k2)>=0)
    return(1);
  else
    return(0);
}
