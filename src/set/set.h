#ifndef SET_H
#define SET_H

#include <stdio.h>

#include "set_item.h"

typedef   struct set_array              *SetArray;
typedef   struct set_list               *SetList;

SetArray  SETinitArray                  (int maxN);
SetList   SETinitList                   (void);

void      SETfillArrayUnordered         (SetArray s, SetItem data);
void      SETfillArrayOrdered           (SetArray s, SetItem data);
void      SETfillListUnordered          (SetList s, SetItem data);
void      SETfillListOrdered            (SetList s, SetItem data);

int       SETsearchArrayUnordered       (SetArray s, Key k);
int       SETsearchArrayOrdered         (SetArray s, Key k);
int       SETsearchList                 (SetList s, Key k);

SetArray  SETunionArrayUnordered        (SetArray s1, SetArray s2);
SetArray  SETunionArrayOrdered          (SetArray s1, SetArray s2);
SetList   SETunionListUnordered         (SetList s1, SetList s2);
SetList   SETunionListOrdered           (SetList s1, SetList s2);

SetArray  SETintersectionArrayUnordered (SetArray s1, SetArray s2);
SetArray  SETintersectionArrayOrdered   (SetArray s1, SetArray s2);
SetList   SETintersectionListUnordered  (SetList s1, SetList s2);
SetList   SETintersectionListOrdered    (SetList s1, SetList s2);

int       SETsizeArray                  (SetArray s);
int       SETsizeList                   (SetList s);

int       SETemptyArray                 (SetArray s);
int       SETemptyList                  (SetList s);

void      SETdisplayArray               (SetArray s, FILE *fp);
void      SETdisplayList                (SetList s, FILE *fp);

#endif
