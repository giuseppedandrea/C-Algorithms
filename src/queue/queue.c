#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct queue_array {
  QueueItem *q;
  int N, head, tail;
};

QueueArray QUEUEinitArray(int maxN) {
  QueueArray q=(QueueArray)malloc(sizeof(*q)) ;
  q->q=(QueueItem*)malloc((maxN+1)*sizeof(*(q->q)));
  q->N=maxN+1;
  q->head=maxN+1;
  q->tail=0;
  return(q);
}

typedef struct QUEUEnode *link;

struct QUEUEnode {
  QueueItem data;
  link next;
};

struct queue_list {
  link head;
  link tail;
};

link QUEUEnew(QueueItem data, link next) {
  link x=(link)malloc(sizeof(*x));
  x->data=data;
  x->next=next;
  return(x);
}

QueueList QUEUEinitList(void) {
  QueueList q=(QueueList)malloc(sizeof(*q));
  q->head=NULL;
  q->tail=NULL;
  return(q);
}

int QUEUEemptyArray(QueueArray q) {
  return(((q->head)%(q->N))==(q->tail));
}

int QUEUEemptyList(QueueList q) {
  return((q->head==NULL));
}

void QUEUEputArray(QueueArray q, QueueItem data) {
  q->q[(q->tail)++]=data;
  q->tail=(q->tail)%(q->N);
  return;
}

void QUEUEputList(QueueList q, QueueItem data) {
  if (q->head==NULL){
    q->tail=QUEUEnew(data, q->head);
    q->head=q->tail;
    return;
  }
  q->tail->next=QUEUEnew(data, q->tail->next);
  q->tail=q->tail->next;
  return;
}

QueueItem QUEUEgetArray(QueueArray q) {
  if (QUEUEemptyArray(q)) {
    return(QUEUEitemSetVoid());
  }
  q->head=(q->head)%(q->N);
  return(q->q[q->head++]);
}

QueueItem QUEUEgetList(QueueList q) {
  if (QUEUEemptyList(q)) {
    return(QUEUEitemSetVoid());
  }
  QueueItem data=q->head->data;
  link tmp=q->head->next;
  free(q->head);
  q->head=tmp;
  return(data);
}
