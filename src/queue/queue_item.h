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

typedef     struct queue_item      *QueueItem;

QueueItem   QUEUEitemNew           (void);
void        QUEUEitemFree          (QueueItem data);
QueueItem   QUEUEitemScan          (FILE *fp);
void        QUEUEitemShow          (QueueItem data, FILE *fp);
int         QUEUEitemCheckVoid     (QueueItem data);
QueueItem   QUEUEitemSetVoid       (void);
Key         QUEUEkeyGet            (QueueItem data);
Key         QUEUEkeyCompare        (Key k1, Key k2);
int         QUEUEitemEqual         (QueueItem data1, QueueItem data2);
int         QUEUEitemLess          (QueueItem data1, QueueItem data2);
int         QUEUEitemLessEqual     (QueueItem data1, QueueItem data2);
int         QUEUEitemGreater       (QueueItem data1, QueueItem data2);
int         QUEUEitemGreaterEqual  (QueueItem data1, QueueItem data2);

#endif
