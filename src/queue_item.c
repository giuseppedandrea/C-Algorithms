#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue_item.h"

struct queue_item {
  Key value;
};

static struct queue_item QUEUE_ITEM_NULL = {
  VOID_VALUE
};
static QueueItem QUEUE_ITEM_VOID = &QUEUE_ITEM_NULL;

QueueItem QUEUEitemNew(void) {
  QueueItem data=(QueueItem)malloc(sizeof(*data));
  if(data==NULL)
    return(QUEUEitemSetVoid());
  data->value=DEFAULT_VALUE;
  return(data);
}

void QUEUEitemFree(QueueItem data) {
  free(data);
  return;
}

QueueItem QUEUEitemScan(FILE *fp) {
  QueueItem data=QUEUEitemNew();
  if (data!=NULL) {
    fscanf(fp, FORMAT, &data->value);
  }
  return(data);
}

void QUEUEitemShow(QueueItem data, FILE *fp) {
  fprintf(fp, FORMAT, data->value);
  return;
}

int QUEUEitemCheckVoid(QueueItem data) {
  return(data==QUEUE_ITEM_VOID);
}

QueueItem QUEUEitemSetVoid(void) {
  QueueItem data=QUEUE_ITEM_VOID;
  return(data);
}

Key QUEUEkeyGet(QueueItem data) {
  return(data->value);
}

Key QUEUEkeyCompare(Key k1, Key k2) {
  return(k1-k2);
}

int QUEUEitemEqual(QueueItem data1, QueueItem data2) {
  Key k1=QUEUEkeyGet(data1), k2=QUEUEkeyGet(data2);
  if (QUEUEkeyCompare(k1, k2)==0)
    return(1);
  else
    return(0);
}

int QUEUEitemLess(QueueItem data1, QueueItem data2) {
  Key k1=QUEUEkeyGet(data1), k2=QUEUEkeyGet(data2);
  if (QUEUEkeyCompare(k1, k2)<0)
    return(1);
  else
    return(0);
}

int QUEUEitemLessEqual(QueueItem data1, QueueItem data2) {
  Key k1=QUEUEkeyGet(data1), k2=QUEUEkeyGet(data2);
  if (QUEUEkeyCompare(k1, k2)<=0)
    return(1);
  else
    return(0);
}

int QUEUEitemGreater(QueueItem data1, QueueItem data2) {
  Key k1=QUEUEkeyGet(data1), k2=QUEUEkeyGet(data2);
  if (QUEUEkeyCompare(k1, k2)>0)
    return(1);
  else
    return(0);
}

int QUEUEitemGreaterEqual(QueueItem data1, QueueItem data2) {
  Key k1=QUEUEkeyGet(data1), k2=QUEUEkeyGet(data2);
  if (QUEUEkeyCompare(k1, k2)>=0)
    return(1);
  else
    return(0);
}
