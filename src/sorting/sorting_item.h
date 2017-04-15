#ifndef SORTING_ITEM_H
#define SORTING_ITEM_H

#include <stdio.h>

#define KEY_INT       //Key type is int
//#define KEY_FLOAT   //Key type id float

#define DEFAULT_VALUE 0
#define VOID_VALUE -1

#ifdef KEY_INT
typedef int Key;
#define FORMAT "%d"
#endif
#ifdef KEY_FLOAT
typedef float Key;
#define FORMAT "%f"
#endif

typedef       struct sorting_item      *SortingItem;

SortingItem   SORTINGitemNew           (void);
void          SORTINGitemFree          (SortingItem data);
SortingItem   SORTINGitemScan          (FILE *fp);
void          SORTINGitemShow          (SortingItem data, FILE *fp);
int           SORTINGitemCheckVoid     (SortingItem data);
SortingItem   SORTINGitemSetVoid       (void);
Key           SORTINGkeyGet            (SortingItem data);
Key           SORTINGkeyCompare        (Key k1, Key k2);
int           SORTINGitemEqual         (SortingItem data1, SortingItem data2);
int           SORTINGitemLess          (SortingItem data1, SortingItem data2);
int           SORTINGitemLessEqual     (SortingItem data1, SortingItem data2);
int           SORTINGitemGreater       (SortingItem data1, SortingItem data2);
int           SORTINGitemGreaterEqual  (SortingItem data1, SortingItem data2);

#endif
