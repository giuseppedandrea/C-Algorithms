#ifndef SET_ITEM_H
#define SET_ITEM_H

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

typedef   struct set_item   *SetItem;

SetItem   SETitemNew           (void);
void      SETitemFree          (SetItem data);
SetItem   SETitemScan          (FILE *fp);
void      SETitemShow          (SetItem data, FILE *fp);
int       SETitemCheckVoid     (SetItem data);
SetItem   SETitemSetVoid       (void);
Key       SETkeyGet            (SetItem data);
Key       SETkeyCompare        (Key k1, Key k2);
int       SETitemEqual         (SetItem data1, SetItem data2);
int       SETitemLess          (SetItem data1, SetItem data2);
int       SETitemLessEqual     (SetItem data1, SetItem data2);
int       SETitemGreater       (SetItem data1, SetItem data2);
int       SETitemGreaterEqual  (SetItem data1, SetItem data2);

#endif
