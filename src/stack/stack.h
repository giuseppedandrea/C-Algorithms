#ifndef STACK_H
#define STACK_H

#include "stack_item.h"

typedef struct stack_array *StackArray;
typedef struct stack_list *StackList;

StackArray STACKinitArray(int maxN);
StackList STACKinitList(void);
int STACKemptyArray(StackArray s);
int STACKemptyList(StackList s);
void STACKpushArray(StackArray s, StackItem data);
void STACKpushList(StackList s, StackItem data);
StackItem STACKpopArray(StackArray s);
StackItem STACKpopList(StackList s);

#endif
