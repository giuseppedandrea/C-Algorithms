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
};

SinglyList SinglyListNew(void) {
  SinglyList list=(SinglyList)malloc(sizeof(*list));
  if (list==NULL)
    return(NULL);
  list->head=NULL;
  return(list);
}

void SinglyListFree(SinglyList list, void (*free_list_data)(const void *list_data)) {
  singly_link x=list->head;
  singly_link tmp;
  while (x!=NULL) {
    tmp=x;
    free_list_data(x->data);
    x=x->next;
    free(tmp);
  }
  free(list);
  return;
}

singly_link newSinglyNode(void *data, singly_link next) {
  singly_link x=(singly_link)malloc(sizeof(*x));
  if (x==NULL)
    return(NULL);
  x->data=data;
  x->next=next;
  return(x);
}

void SinglyListInsertHead(UnorderedSinglyList list, void *list_data) {
  list->head=newSinglyNode(list_data, list->head);
  return;
}

void SinglyListInsertTail(UnorderedSinglyList list, void *list_data) {
  singly_link x;
  if (list->head==NULL) {
    list->head=newSinglyNode(list_data, NULL);
    return;
  }
  for (x=list->head; x->next!=NULL; x=x->next);
  x->next=newSinglyNode(list_data, NULL);
  return;
}

void SinglyListInsertSort(OrderedSinglyList list, void *list_data, int (*cmp_list_data)(const void *a, const void *b)) {
  singly_link x, p;
  if (list->head==NULL || cmp_list_data(list->head->data, list_data)>0) {
    list->head=newSinglyNode(list_data, list->head);
    return;
  }
  for (x=list->head->next, p=list->head; x!=NULL && cmp_list_data(list_data, x->data)>0; p=x, x=x->next);
  p->next=newSinglyNode(list_data, x);
  return;
}

void* SinglyListSearch(UnorderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b)) {
  singly_link x;
  for (x=list->head; x!=NULL; x=x->next)
    if (cmp_list_key(get_list_key(x->data), list_key)==0)
      return(x->data);
  return(NULL);
}

void* SinglyListSearchSort(OrderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b)) {
  singly_link x;
  for (x=list->head; x!=NULL && cmp_list_key(list_key, get_list_key(x->data))>=0; x=x->next)
    if (cmp_list_key(get_list_key(x->data), list_key)==0)
      return(x->data);
  return(NULL);
}

int SinglyListDeleteKey(UnorderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b), void (*free_list_data)(const void *list_data)) {
  singly_link x, p;
  if (list->head==NULL)
    return(0);
  for (x=list->head, p=NULL; x!=NULL; p=x, x=x->next) {
    if (cmp_list_key(get_list_key(x->data), list_key)==0) {
      if (x==list->head)
        list->head=x->next;
      else
        p->next=x->next;
      free_list_data(x->data);
      free(x);
      return(1);
    }
  }
  return(0);
}

int SinglyListDeleteKeySort(OrderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b), void (*free_list_data)(const void *list_data)) {
  singly_link x, p;
  if (list->head==NULL)
    return(0);
  for (x=list->head, p=NULL; x!=NULL && cmp_list_key(list_key ,get_list_key(x->data))>=0; p=x, x=x->next) {
    if (cmp_list_key(get_list_key(x->data), list_key)==0) {
      if (x==list->head)
        list->head=x->next;
      else
        p->next=x->next;
      free_list_data(x->data);
      free(x);
      return(1);
    }
  }
  return(0);
}

int SinglyListDeleteHead(SinglyList list, void (*free_list_data)(const void *list_data)) {
  singly_link x=list->head;
  if (list->head==NULL)
    return(0);
  list->head=list->head->next;
  free_list_data(x->data);
  free(x);
  return(1);
}

int SinglyListDeleteTail(SinglyList list, void (*free_list_data)(const void *list_data)) {
  singly_link x, tmp;
  if (list->head==NULL)
    return(0);
  for (x=list->head; x->next!=NULL; tmp=x, x=x->next);
  tmp->next=NULL;
  free_list_data(x->data);
  free(x);
  return(1);
}

void* SinglyListExtractHead(SinglyList list) {
  singly_link x=list->head;
  void *data;
  if (x==NULL)
    return(NULL);
  data=x->data;
  list->head=x->next;
  free(x);
  return(data);
}

void* SinglyListExtractTail(SinglyList list) {
  singly_link x, p;
  void *data;
  if (list->head==NULL) {
    return(NULL);
  }
  for (x=list->head; x->next!=NULL; p=x, x=x->next);
  if (x==list->head) {
    list->head=x->next;
    data=x->data;
  } else {
    p->next=x->next;
    data=x->data;
  }
  free(x);
  return(data);
}

void* SinglyListExtractKey(SinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b)) {
  singly_link x, p;
  void *data=NULL;
  for (x=list->head; x!=NULL; p=x, x=x->next) {
    if (cmp_list_key(get_list_key(x->data), list_key)==0) {
      if (x==list->head) {
        list->head=x->next;
        data=x->data;
      } else {
        p->next=x->next;
        data=x->data;
      }
      free(x);
      return(data);
    }
  }
  return(data);
}

void SinglyListPrint(SinglyList list, void (*print_list_data)(const void *list_data)) {
  singly_link x;
  for (x=list->head; x!=NULL; x=x->next) {
    print_list_data(x->data);
  }
  return;
}
