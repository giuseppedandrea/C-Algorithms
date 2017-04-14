#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct stack_array {
  StackItem *s;
  int N;
};

StackArray STACKinitArray(int maxN) {
  StackArray s=(StackArray)malloc(sizeof(*s));
  s->s=(StackItem*)malloc(maxN*sizeof(StackItem));
  s->N=0;
  return(s);
}

typedef struct STACKnode *link;

struct STACKnode {
  StackItem data;
  link next;
};

struct stack_list {
  link head;
  int N;
};

link STACKnew(StackItem data, link next) {
  link x=(link)malloc(sizeof(*x));
  x->data=data;
  x->next=next;
  return(x);
}

StackList STACKinitList(void) {
  StackList s=(StackList)malloc(sizeof(*s)) ;
  s->head=NULL;
  s->N=0;
  return(s);
}

int STACKemptyArray(StackArray s) {
  return((s->N)==0);
}

int STACKemptyList(StackList s) {
  return(s->head==NULL);
}

void STACKpushArray(StackArray s, StackItem data) {
  s->s[s->N++]=data;
  return;
}

void STACKpushList(StackList s, StackItem data) {
  s->head=STACKnew(data, s->head);
  return;
}

StackItem STACKpopArray(StackArray s) {
  if (STACKemptyArray(s)) {
    return(STACKitemSetVoid());
  }
  return(s->s[--(s->N)]);
}

StackItem STACKpopList(StackList s) {
  if (STACKemptyList(s)) {
    return(STACKitemSetVoid());
  }
  StackItem data;
  link tmp;
  data=s->head->data;
  tmp=s->head->next;
  free(s->head);
  s->head=tmp;
  return(data);
}
