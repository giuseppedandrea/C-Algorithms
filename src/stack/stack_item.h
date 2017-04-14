#ifndef ITEM_H
#define ITEM_H

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

typedef     struct stack_item      *StackItem;

StackItem   STACKitemNew           (void);
void        STACKitemFree          (StackItem data);
StackItem   STACKitemScan          (FILE *fp);
void        STACKitemShow          (StackItem data, FILE *fp);
int         STACKitemCheckVoid     (StackItem data);
StackItem   STACKitemSetVoid       (void);
Key         STACKkeyGet            (StackItem data);
Key         STACKkeyCompare        (Key k1, Key k2);
int         STACKitemEqual         (StackItem data1, StackItem data2);
int         STACKitemLess          (StackItem data1, StackItem data2);
int         STACKitemLessEqual     (StackItem data1, StackItem data2);
int         STACKitemGreater       (StackItem data1, StackItem data2);
int         STACKitemGreaterEqual  (StackItem data1, StackItem data2);

#endif
