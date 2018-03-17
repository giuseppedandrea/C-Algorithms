#ifndef QUEUE_H
#define QUEUE_H

#include "queue_item.h"

typedef     struct queue_array  *QueueArray;
typedef     struct queue_list   *QueueList;

QueueArray  QUEUEinitArray      (int maxN);
QueueList   QUEUEinitList       (void);
int         QUEUEemptyArray     (QueueArray q);
int         QUEUEemptyList      (QueueList q);
void        QUEUEputArray       (QueueArray q, QueueItem data);
void        QUEUEputList        (QueueList q, QueueItem data);
QueueItem   QUEUEgetArray       (QueueArray q);
QueueItem   QUEUEgetList        (QueueList q);

#endif
