#ifndef LIST_H
#define LIST_H

typedef struct singly_list *UnorderedSinglyList;
typedef struct singly_list *OrderedSinglyList;
typedef struct singly_list *SinglyList;

SinglyList  SinglyListNew           (void);
void        SinglyListFree          (SinglyList list, void (*free_list_data)(const void *list_data));
void        SinglyListInsertHead    (UnorderedSinglyList list, void *list_data);
void        SinglyListInsertTail    (UnorderedSinglyList list, void *list_data);
void        SinglyListInsertSort    (OrderedSinglyList list, void *list_data, int (*cmp_list_data)(const void *a, const void *b));
void*       SinglyListSearch        (UnorderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b));
void*       SinglyListSearchSort    (OrderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b));
int         SinglyListDeleteKey     (UnorderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b));
int         SinglyListDeleteKeySort (OrderedSinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b));
int         SinglyListDeleteHead    (SinglyList list);
int         SinglyListDeleteTail    (SinglyList list);
void*       SinglyListExtractHead   (SinglyList list);
void*       SinglyListExtractTail   (SinglyList list);
void*       SinglyListExtractKey    (SinglyList list, void *list_key, void* (*get_list_key)(const void *list_data), int (*cmp_list_key)(const void *a, const void *b));
void        SinglyListPrint         (SinglyList list, void (*print_list_data)(const void *list_data));

#endif
