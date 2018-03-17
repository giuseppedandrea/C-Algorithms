#include <stdio.h>
#include <stdlib.h>

#include "set.h"

struct set_array {
  SetItem *s;
  int N;
};

SetArray SETinitArray(int maxN) {
  SetArray s=(SetArray)malloc(sizeof(*s));
  s->s=(SetItem*)malloc(maxN*sizeof(*(s->s)));
  s->N=0;
  return(s);
}

typedef struct SETnode *link;

struct SETnode {
  SetItem data;
  link next;
};

struct set_list {
  link head;
  int N;
};

link SETnew(SetItem data, link next) {
  link x=(link)malloc(sizeof(*x));
  x->data=data;
  x->next=next;
  return(x);
}

SetList SETinitList(void) {
  SetList s=(SetList)malloc(sizeof(*s));
  s->head=NULL;
  s->N=0;
  return(s);
}

void SETfillArrayUnordered(SetArray s, SetItem data) {
  s->s[s->N]=data;
  s->N++;
  return;
}

void SETfillArrayOrdered(SetArray s, SetItem data) {
  int x, i;
  for (x=0; (x<(s->N)) && SETitemLess(s->s[x], data); x++);
  for (i=(s->N); i>x; i--) {
    s->s[i]=s->s[i-1];
  }
  s->s[x]=data;
  s->N++;
  return;
}

void SETfillListUnordered(SetList s, SetItem data) {
  s->head=SETnew(data, s->head);
  s->N++;
  return;
}

void SETfillListOrdered(SetList s, SetItem data) {
  link x, p;
  if (s->head==NULL || SETitemLess(data, s->head->data)) {
    s->head=SETnew(data, s->head);
    s->N++;
    return;
  }
  for (x=(s->head->next), p=s->head; (x!=NULL) && SETitemLess(x->data, data); p=x, x=x->next);
  p->next=SETnew(data, x);
  s->N++;
  return;
}

int SETsearchArrayUnordered(SetArray s, Key k) {
  int i;
  for (i=0; i<(s->N); i++) {
    if (SETkeyCompare(SETkeyGet(s->s[i]), k) == 0) {
      return(1);
    }
  }
  return(0);
}

int SETsearchArrayOrdered(SetArray s, Key k) {
  int l=0, m, r=(s->N)-1;
  while (l<=r) {
    m=l+((r-l)/2);
    if (SETkeyCompare(SETkeyGet(s->s[m]), k)==0) {
      return(1);
    }
    if (SETkeyCompare(SETkeyGet(s->s[m]), k)<0) {
      l=m+1;
    } else {
      r=m-1;
    }
  }
  return(0);
}

int SETsearchList(SetList s, Key k) {
  link x, head=s->head;
  for (x=head; x!=NULL; x=x->next) {
    if (SETkeyCompare(SETkeyGet(x->data), k)==0) {
      return(1);
    }
  }
  return(0);
}

SetArray SETunionArrayUnordered(SetArray s1, SetArray s2) {
  int i, j;
  int founds2, counts2=0;
  SetArray s=SETinitArray((s1->N)+(s2->N));
  for (i=0; i<(s1->N); i++) {
    SETfillArrayUnordered(s, s1->s[i]);
  }
  for (i=0; i<(s2->N); i++) {
    founds2=0;
    for (j=0; j<(s1->N); j++) {
      if (SETitemEqual(s1->s[j], s2->s[i])) {
        founds2=1;
        break;
      }
    }
    if (founds2==0) {
      SETfillArrayUnordered(s, s2->s[i]);
      counts2++;
    }
  }
  s->N=(s1->N)+counts2;
  return(s);
}

SetArray SETunionArrayOrdered(SetArray s1, SetArray s2) {
  int i=0, j=0, k=0, common=0;
  int size1=SETsizeArray(s1), size2=SETsizeArray(s2);
  SetArray s=SETinitArray(size1+size2);
  for(k=0; k<(size1+size2); k++) {
    if (i>=size1){
      s->s[k]=s2->s[j++];
    } else if (j>=size2) {
      s->s[k]=s1->s[i++];
    } else if (SETitemLess(s1->s[i], s2->s[j])) {
      s->s[k]=s1->s[i++];
    } else if (SETitemLess(s2->s[j], s1->s[i])) {
      s->s[k]=s2->s[j++];
    } else {
      s->s[k]=s1->s[i++];
      j++;
      common++;
    }
  }
  s->N=k-common;
  return(s);
}

SetList SETunionListUnordered(SetList s1, SetList s2) {
  link x1, x2;
  int founds2, counts2=0;
  SetList s=SETinitList();
  for (x1=(s1->head); x1!=NULL; x1=x1->next) {
    SETfillListUnordered(s, x1->data);
  }
  for (x2=(s2->head); x2!=NULL; x2=x2->next) {
    for (x1=(s1->head), founds2=0; x1!=NULL; x1=x1->next) {
      if (SETitemEqual(x1->data, x2->data)) {
        founds2=1;
        break;
      }
    }
    if (founds2==0) {
      SETfillListUnordered(s, x2->data);
      counts2++;
    }
  }
  s->N=(s1->N)+counts2;
  return(s);
}

SetList SETunionListOrdered(SetList s1, SetList s2) {
  link x, y, tail;
  SetList s=SETinitList();
  x=s1->head;
  y=s2->head;

  while ((x!=NULL) || (y!=NULL)) {
    if (x==NULL) {
      if ((s->head)==NULL) {
        s->head=SETnew(y->data, s->head);
        tail=s->head;
      } else {
        tail->next=SETnew(y->data, tail->next);
        tail=tail->next;
      }
      y=y->next;
    } else if (y==NULL) {
      if ((s->head)==NULL) {
        s->head=SETnew(x->data, s->head);
        tail=s->head;
      } else {
        tail->next=SETnew(x->data, tail->next);
        tail=tail->next;
      }
      x=x->next;
    } else if (SETitemLess(y->data, x->data)) {
      if ((s->head)==NULL) {
        s->head=SETnew(y->data, s->head);
        tail=s->head;
      } else {
        tail->next=SETnew(y->data, tail->next);
        tail=tail->next;
      }
      y=y->next;
    } else if (SETitemLess(x->data, y->data)) {
      if ((s->head)==NULL) {
        s->head=SETnew(x->data, s->head);
        tail=s->head;
      } else {
        tail->next=SETnew(x->data, tail->next);
        tail=tail->next;
      }
      x=x->next;
    } else {
      if ((s->head)==NULL) {
        s->head=SETnew(x->data, s->head);
        tail=s->head;
      } else {
        tail->next=SETnew(x->data, tail->next);
        tail=tail->next;
      }
      x=x->next;
      y=y->next;
    }
    s->N++;
  }
  return(s);
}

SetArray SETintersectionArrayUnordered(SetArray s1, SetArray s2) {
  int i, j;
  SetArray s=SETinitArray((s1->N)+(s2->N));
  for (i=0; i<(s1->N); i++) {
    for (j=0; j<(s2->N); j++) {
      if (SETitemEqual(s1->s[i], s2->s[j])) {
        SETfillArrayUnordered(s, s1->s[i]);
      }
    }
  }
  return(s);
}

SetArray SETintersectionArrayOrdered(SetArray s1, SetArray s2) {
  int i=0, j=0, counts=0;
  int size1=SETsizeArray(s1), size2=SETsizeArray(s2), minsize;
  SetArray s;
  minsize=((size1<=size2)?size1:size2);
  s=SETinitArray(minsize);
  while ((i<size1) && (j<size2)) {
    if (SETitemEqual(s1->s[i], s2->s[j])) {
      s->s[counts++]=s1->s[i];
      i++;
      j++;
    } else if (SETitemLess(s1->s[i], s2->s[j])) {
      i++;
    } else {
      j++;
    }
  }
  s->N=counts;
  return(s);
}

SetList SETintersectionListUnordered(SetList s1, SetList s2) {
  link x1, x2;
  SetList s=SETinitList();
  for (x1=s1->head; x1!=NULL; x1=x1->next) {
    for (x2=s2->head; x2!=NULL; x2=x2->next) {
      if (SETitemEqual(x1->data, x2->data)) {
        SETfillListUnordered(s, x1->data);
      }
    }
  }
  return(s);
}

SetList SETintersectionListOrdered(SetList s1, SetList s2) {
  link x, y, tail;
  SetList s=SETinitList();
  x=s1->head;
  y=s2->head;
  while ((x!=NULL) && (y!=NULL)) {
    if (SETitemEqual(x->data, y->data)) {
      if ((s->head)==NULL) {
        s->head=SETnew(x->data, s->head);
        tail=s->head;
      } else {
        tail->next=SETnew(x->data, tail->next);
        tail=tail->next;
      }
      s->N++;
      x=x->next;
      y=y->next;
    } else if (SETitemLess(x->data, y->data)) {
      x=x->next;
    } else {
      y=y->next;
    }
  }
  return(s);
}

int SETsizeArray(SetArray s) {
  return(s->N);
}

int SETsizeList(SetList s) {
  return(s->N);
}

int SETemptyArray(SetArray s) {
  return((s->N)==0);
}

int SETemptyList(SetList s) {
  return((s->N)==0);
}

void SETdisplayArray(SetArray s, FILE *fp) {
  int i;
  for (i=0; i<(s->N); i++) {
    SETitemShow(s->s[i], fp);
    fprintf(fp, "\n");
  }
  return;
}

void SETdisplayList(SetList s, FILE *fp) {
  link x;
  for (x=(s->head); x!=NULL; x=x->next) {
    SETitemShow(x->data, fp);
    fprintf(fp, "\n");
  }
  return;
}
