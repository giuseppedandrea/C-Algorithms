#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"

struct item {
  size_t *members_size;
  void **members_data;
  size_t n_members;
  size_t members_used;
};

static struct item ITEM_NULL = {
  NULL,
  NULL,
  0,
  0
};
static Item ITEM_VOID = &ITEM_NULL;

void CopyMem(void *dest, void *src, size_t length) {
  size_t i;
  char *p=dest, *q=src;
  for (i=0; i<length; i++) {
    p[i]=q[i];
  }
}

Item ITEMnew(size_t n_members) {
  Item item=(Item)malloc(sizeof(*item));
  if(item==NULL)
    return(ITEMsetVoid());
  item->members_size=(size_t *)malloc(n_members*sizeof(*(item->members_size)));
  item->members_data=(void **)malloc(n_members*sizeof(*(item->members_data)));
  for (size_t i = 0; i < n_members; i++) {
    item->members_size[i]=0;
    item->members_data[i]=NULL;
  }
  item->n_members=n_members;
  item->members_used=0;
  return(item);
}

void ITEMfree(Item item) {
  if (ITEMcheckVoid(item))
    return;
  if (item->members_size!=NULL)
    free(item->members_size);
  if (item->members_data!=NULL)
    for (size_t i = 0; i < item->n_members; i++)
      if (item->members_data[i]!=NULL)
        free(item->members_data[i]);
  free(item);
  return;
}

void ITEMaddMember(Item item, size_t member_size) {
  if (ITEMcheckVoid(item))
    return;
  item->members_size[item->members_used]=member_size;
  item->members_data[item->members_used]=(void *)malloc(member_size);
  item->members_used++;
  return;
}

void ITEMsetMember(Item item, size_t index_member, void *member_data) {
  if (ITEMcheckVoid(item))
    return;
  CopyMem(item->members_data[index_member], member_data, item->members_size[index_member]);
  return;
}

void* ITEMgetMember(Item item, size_t index_member) {
  if (ITEMcheckVoid(item))
    return(NULL);
  return(item->members_data[index_member]);
}

int ITEMcheckVoid(Item item) {
  return(item==ITEM_VOID);
}

Item ITEMsetVoid(void) {
  Item item=ITEM_VOID;
  return(item);
}

int ITEMequal(Item item_A, Item item_B, size_t index_member_key, int (*cmp_member_key)(const void *a, const void *b)) {
  if (ITEMcheckVoid(item_A) || ITEMcheckVoid(item_B))
    return(-1);
  if (index_member_key<0 || index_member_key>(item_A->n_members))
    return(-1);
  if (cmp_member_key(item_A->members_data[index_member_key], item_B->members_data[index_member_key])==0)
    return(1);
  else
    return(0);
}

int ITEMless(Item item_A, Item item_B, size_t index_member_key, int (*cmp_member_key)(const void *a, const void *b)) {
  if (ITEMcheckVoid(item_A) || ITEMcheckVoid(item_B))
    return(-1);
  if (index_member_key<0 || index_member_key>(item_A->n_members))
    return(-1);
  if (cmp_member_key(item_A->members_data[index_member_key], item_B->members_data[index_member_key])<0)
    return(1);
  else
    return(0);
}

int ITEMlessEqual(Item item_A, Item item_B, size_t index_member_key, int (*cmp_member_key)(const void *a, const void *b)) {
  if (ITEMcheckVoid(item_A) || ITEMcheckVoid(item_B))
    return(-1);
  if (index_member_key<0 || index_member_key>(item_A->n_members))
    return(-1);
  if (cmp_member_key(item_A->members_data[index_member_key], item_B->members_data[index_member_key])<=0)
    return(1);
  else
    return(0);
}

int ITEMgreater(Item item_A, Item item_B, size_t index_member_key, int (*cmp_member_key)(const void *a, const void *b)) {
  if (ITEMcheckVoid(item_A) || ITEMcheckVoid(item_B))
    return(-1);
  if (index_member_key<0 || index_member_key>(item_A->n_members))
    return(-1);
  if (cmp_member_key(item_A->members_data[index_member_key], item_B->members_data[index_member_key])>0)
    return(1);
  else
    return(0);
}

int ITEMgreaterEqual(Item item_A, Item item_B, size_t index_member_key, int (*cmp_member_key)(const void *a, const void *b)) {
  if (ITEMcheckVoid(item_A) || ITEMcheckVoid(item_B))
    return(-1);
  if (index_member_key<0 || index_member_key>(item_A->n_members))
    return(-1);
  if (cmp_member_key(item_A->members_data[index_member_key], item_B->members_data[index_member_key])>=0)
    return(1);
  else
    return(0);
}
