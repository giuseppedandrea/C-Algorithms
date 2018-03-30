#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>

typedef struct item* Item;

Item  ITEMnew           (size_t n_members);
void  ITEMfree          (Item item);
void  ITEMaddMember     (Item item, size_t member_size);
void  ITEMsetMember     (Item item, size_t index_member, void *member_data);
void* ITEMgetMember     (Item item, size_t index_member);
int   ITEMcheckVoid     (Item item);
Item  ITEMsetVoid       (void);
int   ITEMequal         (Item item_A, Item item_B, size_t index_member_key, int (*cmp_item_key)(const void *a, const void *b));
int   ITEMless          (Item item_A, Item item_B, size_t index_member_key, int (*cmp_item_key)(const void *a, const void *b));
int   ITEMlessEqual     (Item item_A, Item item_B, size_t index_member_key, int (*cmp_item_key)(const void *a, const void *b));
int   ITEMgreater       (Item item_A, Item item_B, size_t index_member_key, int (*cmp_item_key)(const void *a, const void *b));
int   ITEMgreaterEqual  (Item item_A, Item item_B, size_t index_member_key, int (*cmp_item_key)(const void *a, const void *b));

#endif
