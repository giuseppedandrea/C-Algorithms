#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct singly_node *singly_link;

struct singly_node {
  void *data;
  singly_link next;
};

struct singly_list {
  singly_link head;
  singly_link tail;
};

singly_link newSinglyNode(void *data, singly_link next) {
  singly_link x=(singly_link)malloc(sizeof(*x));
  if (x==NULL)
    return(NULL);
  x->data=data;
  x->next=next;
  return(x);
}

void SinglyListInsertHead(UnorderedSinglyList list, void *list_data) {
  singly_link head=list->head;
  head=newSinglyNode(list_data, head);
  return;
}

void SinglyListInsertTail(UnorderedSinglyList list, void *list_data) {
  singly_link head=list->head;
  singly_link x;
  if (head==NULL) {
    head=newSinglyNode(list_data, NULL);
    return;
  }
  for (x=head; x->next!=NULL; x=x->next);
  x->next=newSinglyNode(list_data, NULL);
  return;
}

void SinglyListInsertSort(OrderedSinglyList list, void *list_data, int (*cmp_list_data)(const void *a, const void *b)) {
  singly_link head=list->head;
  singly_link x, p;
  if (head==NULL || cmp_list_data(head->data, list_data)>0) {
    head=newSinglyNode(list_data, head);
    return;
  }
  for (x=head->next, p=head; x!=NULL && cmp_list_data(list_data, x->data)>0; p=x, x=x->next);
  p->next=newSinglyNode(list_data, x);
  return;
}

void* SinglyListSearch(UnorderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b)) {
  singly_link head=list->head;
  singly_link x;
  for (x=head; x!=NULL; x=x->next)
    if (cmp_list_key(get_list_key(x->data), list_key)==0)
      return(x->data);
  return(NULL);
}

void* SinglyListSearchSort(OrderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b)) {
  singly_link head=list->head;
  singly_link x;
  for (x=head; x!=NULL && cmp_list_key(list_key, get_list_key(x->data))>=0; x=x->next)
    if (cmp_list_key(get_list_key(x->data), list_key)==0)
      return(x->data);
  return(NULL);
}

int SinglyListDeleteKey(UnorderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b)) {
  singly_link head=list->head;
  singly_link x, p;
  if (head==NULL)
    return(0);
  for (x=head, p=NULL; x!=NULL; p=x, x=x->next) {
    if (cmp_list_key(get_list_key(x->data), list_key)==0) {
      if (x==head)
        head=x->next;
      else
        p->next=x->next;
      free(x);
      break;
    }
  }
  return(1);
}

int SinglyListDeleteKeySort(OrderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b)) {
  singly_link head=list->head;
  singly_link x, p;
  if (head==NULL)
    return(0);
  for (x=head, p=NULL; x!=NULL && cmp_list_key(list_key ,get_list_key(x->data))>=0; p=x, x=x->next) {
    if (cmp_list_key(get_list_key(x->data), list_key)==0) {
      if (x==head)
        head=x->next;
      else
        p->next=x->next;
      free(x);
      break;
    }
  }
  return(1);
}

int SinglyListDeleteHead(SinglyList list) {
  singly_link head=list->head;
  singly_link tmp=head;
  if (head==NULL)
    return(0);
  head=head->next;
  free(tmp);
  return(1);
}

int SinglyListDeleteTail(SinglyList list) {
  singly_link head=list->head;
  singly_link x, tmp;
  if (head==NULL)
    return(0);
  for (x=head; x->next!=NULL; tmp=x, x=x->next);
  tmp->next=NULL;
  free(x);
  return(1);
}

void* SinglyListExtractHead(SinglyList list) {
  singly_link head=list->head;
  singly_link tmp=head;
  void *data;
  if (tmp==NULL)
    return(NULL);
  data=tmp->data;
  head=tmp->next;
  free(tmp);
  return(data);
}

void* SinglyListExtractTail(SinglyList list) {
  singly_link head=list->head;
  singly_link x, p;
  void *data=NULL;
  for (x=head; x!=NULL; p=x, x=x->next);
  if (x==head) {
    head=x->next;
    data=x->data;
  } else {
    p->next=x->next;
    data=x->data;
  }
  free(x);
  return(data);
}

void* SinglyListExtractKey(SinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b)) {
  singly_link head=list->head;
  singly_link x, p;
  void *data=NULL;
  for (x=head; x!=NULL; p=x, x=x->next) {
    if (cmp_list_key(get_list_key(x->data), list_key)==0) {
      if (x==head) {
        head=x->next;
        data=x->data;
      } else {
        p->next=x->next;
        data=x->data;
      }
      free(x);
      break;
    }
  }
  return(data);
}
